#pragma once
#include <QMainWindow>
#include <QCheckBox>
#include "ui_MainWindow.h"
#include "Questions.h"

class AnswerCheckBox;
using Checks = QVector<AnswerCheckBox*>;

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent);

    public slots:
        void on_btnBrowse_clicked();
        void on_btnReload_clicked();
        void on_btnSkip_clicked();
        void on_btnNext_clicked();

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

    private:
        void LoadAllQuestions(const QString& path);
        void StartTesting();
        void PrepareAndShuffleQuestions();
        void ProceedOrFinish();
        void GoToNext();
        bool LoadQuestion(int number);
        void LoadQuestion(const Question& question);
        void SwitchAnswerCheck(int num);
        bool IsAnswerPicked();
        bool CheckAnswers(const Answers& answers);
        void ShowResults();

    private:
        Ui::MainWindow m_ui;
        Questions m_allQuestions;
        Questions m_curQuestions;
        Checks m_checks;
        int m_curQuestion = -1;
        int m_answeredQuestions = 0;
        qreal m_dpiScaleFactor;
};
