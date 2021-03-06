#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <random>
#include "MainWindow.h"
#include "AnswerCheckBox.h"

namespace
{
    QString LoadFile(const QString& path)
    {
        QFile file(path);
        if (!file.open(QFile::ReadOnly | QFile::Text)) return "";
        QTextStream in(&file);
        return in.readAll();
    }

    bool LoadQuestions(const QString& path, Questions& questions)
    {
        QString content = LoadFile(path);
        if (content.isEmpty()) return false;
        ParseQuestions(content, questions);
        return !questions.isEmpty();
    }

    void ClearLayout(QLayout* layout)
    {
        QLayoutItem* item = nullptr;
        while((item = layout->takeAt(0)))
        {
            if (item->widget())
            {
                delete item->widget();
            }
            delete item;
        }
    }

    qreal GetDpiScaleFactor()
    {
        QDesktopWidget desktopWidget;
        QScreen* defScreen = QApplication::screens().at(desktopWidget.primaryScreen());
        return defScreen->logicalDotsPerInch() / 96; // 96 is a standard DPI for Windows
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_dpiScaleFactor(GetDpiScaleFactor())
{
    m_ui.setupUi(this);
    setMinimumSize(minimumSize() * m_dpiScaleFactor);
    m_ui.btnSkip->setEnabled(false);
    m_ui.btnNext->setEnabled(false);
    m_ui.lblWrong->setVisible(false);
}

void MainWindow::on_btnBrowse_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Найти файл теста", QDir::currentPath());
    if (!path.isEmpty())
    {
        LoadAllQuestions(path);
    }
}

void MainWindow::on_btnReload_clicked()
{
    QString path = m_ui.lineEdit->text();
    if (path.isEmpty())
    {
        QMessageBox::information(this, windowTitle(), "Вы не выбрали тест");
    }
    else
    {
        LoadAllQuestions(path);
    }
}

void MainWindow::on_btnSkip_clicked()
{
    GoToNext();
}

void MainWindow::on_btnNext_clicked()
{
    if (m_ui.lblWrong->isVisible())
    {
        m_ui.lblWrong->setVisible(false);
        ProceedOrFinish();
        return;
    }

    if (m_curQuestion >= 0 && IsAnswerPicked())
    {
        Question& curQuestion = m_curQuestions[m_curQuestion];
        curQuestion.passed = true;

        if (CheckAnswers(curQuestion.answers))
        {
            ++m_answeredQuestions;
            ProceedOrFinish();
        }
        else
        {
            m_ui.lblWrong->setVisible(true);
        }
        m_ui.lblRightness->setText(QString::number(m_answeredQuestions));
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Return)
    {
        on_btnNext_clicked();
    }
    else if (event->key() >= Qt::Key_1 && event->key() <= Qt::Key_9)
    {
        SwitchAnswerCheck(event->key() - Qt::Key_1);
    }

    QMainWindow::keyPressEvent(event);
}

void MainWindow::LoadAllQuestions(const QString& path)
{
    Questions questions;
    if (!LoadQuestions(path, questions))
    {
        QMessageBox::information(this, windowTitle(), "Не удалось прочитать этот файл");
        return;
    }
    m_allQuestions.swap(questions);
    m_ui.lineEdit->setText(path);
    m_ui.lblQuestionsTotal->setText(QString("/ %1").arg(m_allQuestions.size()));
    m_ui.lineMaxQuestions->setValidator(new QIntValidator(1, m_allQuestions.size(), this));
    m_ui.btnSkip->setEnabled(true);
    m_ui.btnNext->setEnabled(true);
    StartTesting();
}

void MainWindow::StartTesting()
{
    PrepareAndShuffleQuestions();
    m_answeredQuestions = 0;
    m_ui.lblRightness->setText(QString::number(m_answeredQuestions));
    LoadQuestion(0);
}

void MainWindow::PrepareAndShuffleQuestions()
{
    const int defMaxQuestions = 20;
    bool ok = false;
    int maxQuestions = m_ui.lineMaxQuestions->text().toInt(&ok);
    if (!ok)
    {
        maxQuestions = defMaxQuestions;
    }
    else if (maxQuestions > m_allQuestions.size())
    {
        maxQuestions = m_allQuestions.size();
    }
    m_ui.lineMaxQuestions->setText(QString::number(maxQuestions));
    m_ui.progressBar->setMaximum(maxQuestions);

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::shuffle(m_allQuestions.begin(), m_allQuestions.end(), generator);
    m_curQuestions.clear();
    qCopy(m_allQuestions.begin(), m_allQuestions.begin() + maxQuestions, std::back_inserter(m_curQuestions));
    for (Question& question : m_curQuestions)
    {
        std::shuffle(question.answers.begin(), question.answers.end(), generator);
    }
}

void MainWindow::ProceedOrFinish()
{
    if (m_answeredQuestions == m_curQuestions.size())
    {
        ShowResults();
    }
    else
    {
        GoToNext();
    }
}

void MainWindow::GoToNext()
{
    if (m_curQuestion == m_curQuestions.size() - 1 ||
        !LoadQuestion(++m_curQuestion))
    {
        bool success = LoadQuestion(0);
        if (!success)
        {
            qDebug() << "Huston, we have a problem";
            ShowResults();
        }
    }
}

bool MainWindow::LoadQuestion(int number)
{
    for (int i = number; i < m_curQuestions.size(); ++i)
    {
        if (!m_curQuestions.at(i).passed)
        {
            m_curQuestion = i;
            m_ui.progressBar->setValue(m_curQuestion + 1);
            LoadQuestion(m_curQuestions.at(m_curQuestion));
            return true;
        }
    }
    return false;
}

void MainWindow::LoadQuestion(const Question& question)
{
    m_checks.clear();
    ClearLayout(m_ui.answersLayout);
    m_ui.lblQuestion->setText(question.text);
    for (int i = 0; i < question.answers.size(); ++i)
    {
        AnswerCheckBox* check = new AnswerCheckBox(m_ui.groupAnswers, i + 1, question.answers.at(i).text, m_dpiScaleFactor);
        m_checks.push_back(check);
        m_ui.answersLayout->addWidget(check);
    }
    m_ui.answersLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Preferred, QSizePolicy::Expanding));
}

void MainWindow::SwitchAnswerCheck(int num)
{
    if (num >= 0 && num < m_checks.size())
    {
        m_checks.at(num)->SwitchCheckedState();
    }
}

bool MainWindow::IsAnswerPicked()
{
    bool checked = false;
    for (auto check : m_checks)
    {
        checked |= check->IsChecked();
    }
    return checked;
}

bool MainWindow::CheckAnswers(const Answers& answers)
{
    bool right = true;
    for (int i = 0; i < m_checks.size() && i < answers.size(); ++i)
    {
        AnswerCheckBox& check = *m_checks.at(i);
        check.EnableSummarizedView(answers.at(i).isRight);
        if (check.IsChecked() != answers.at(i).isRight)
        {
            right = false;
        }
    }
    return right;
}

void MainWindow::ShowResults()
{
    QMessageBox::information(this, "Результаты", QString("Правильных ответов: %0 из %1").arg(
                                 m_answeredQuestions).arg(m_curQuestions.size()), "Пройти еще раз");
    StartTesting();
}
