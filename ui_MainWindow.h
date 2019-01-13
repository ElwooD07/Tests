/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupTest;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBrowse;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineMaxQuestions;
    QLabel *lblQuestionsTotal;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnReload;
    QGroupBox *groupQuestion;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblQuestion;
    QGroupBox *groupAnswers;
    QVBoxLayout *answersLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnNext;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblWrong;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *lblRightness;
    QProgressBar *progressBar;
    QPushButton *btnSkip;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 556);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(100500, 100500));
        MainWindow->setStyleSheet(QStringLiteral("font-size: 11pt; color: #101010"));
        MainWindow->setDocumentMode(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupTest = new QGroupBox(centralWidget);
        groupTest->setObjectName(QStringLiteral("groupTest"));
        groupTest->setFlat(false);
        groupTest->setCheckable(false);
        horizontalLayout = new QHBoxLayout(groupTest);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        btnBrowse = new QPushButton(groupTest);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));
        btnBrowse->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(btnBrowse);

        lineEdit = new QLineEdit(groupTest);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, -1, -1, -1);
        label_2 = new QLabel(groupTest);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(label_2);

        lineMaxQuestions = new QLineEdit(groupTest);
        lineMaxQuestions->setObjectName(QStringLiteral("lineMaxQuestions"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineMaxQuestions->sizePolicy().hasHeightForWidth());
        lineMaxQuestions->setSizePolicy(sizePolicy1);
        lineMaxQuestions->setMinimumSize(QSize(0, 0));
        lineMaxQuestions->setMaximumSize(QSize(16777215, 16777215));
        lineMaxQuestions->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineMaxQuestions);

        lblQuestionsTotal = new QLabel(groupTest);
        lblQuestionsTotal->setObjectName(QStringLiteral("lblQuestionsTotal"));

        horizontalLayout_4->addWidget(lblQuestionsTotal);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnReload = new QPushButton(groupTest);
        btnReload->setObjectName(QStringLiteral("btnReload"));
        btnReload->setStyleSheet(QStringLiteral("color: #501010"));

        horizontalLayout_4->addWidget(btnReload);

        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(3, 10);

        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addWidget(groupTest);

        groupQuestion = new QGroupBox(centralWidget);
        groupQuestion->setObjectName(QStringLiteral("groupQuestion"));
        verticalLayout_2 = new QVBoxLayout(groupQuestion);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblQuestion = new QLabel(groupQuestion);
        lblQuestion->setObjectName(QStringLiteral("lblQuestion"));
        lblQuestion->setWordWrap(true);

        verticalLayout_2->addWidget(lblQuestion);


        verticalLayout->addWidget(groupQuestion);

        groupAnswers = new QGroupBox(centralWidget);
        groupAnswers->setObjectName(QStringLiteral("groupAnswers"));
        groupAnswers->setFlat(false);
        answersLayout = new QVBoxLayout(groupAnswers);
        answersLayout->setSpacing(5);
        answersLayout->setContentsMargins(11, 11, 11, 11);
        answersLayout->setObjectName(QStringLiteral("answersLayout"));

        verticalLayout->addWidget(groupAnswers);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        btnNext->setFont(font);
        btnNext->setAutoDefault(true);

        horizontalLayout_3->addWidget(btnNext);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(100, 0));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblWrong = new QLabel(widget);
        lblWrong->setObjectName(QStringLiteral("lblWrong"));
        lblWrong->setStyleSheet(QStringLiteral("color: #cc2020;"));

        horizontalLayout_2->addWidget(lblWrong);


        horizontalLayout_3->addWidget(widget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, -1, -1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        lblRightness = new QLabel(centralWidget);
        lblRightness->setObjectName(QStringLiteral("lblRightness"));
        lblRightness->setStyleSheet(QStringLiteral("color: #209920"));

        horizontalLayout_5->addWidget(lblRightness);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setInvertedAppearance(false);

        horizontalLayout_5->addWidget(progressBar);


        horizontalLayout_3->addLayout(horizontalLayout_5);

        btnSkip = new QPushButton(centralWidget);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        sizePolicy1.setHeightForWidth(btnSkip->sizePolicy().hasHeightForWidth());
        btnSkip->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btnSkip);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 5);
        verticalLayout->setStretch(3, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        btnNext->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\321\213", nullptr));
        groupTest->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202", nullptr));
        btnBrowse->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214...", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201\320\276\320\262:", nullptr));
        lineMaxQuestions->setInputMask(QString());
        lineMaxQuestions->setText(QApplication::translate("MainWindow", "20", nullptr));
        lblQuestionsTotal->setText(QApplication::translate("MainWindow", "/ 0", nullptr));
        btnReload->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        groupQuestion->setTitle(QApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        lblQuestion->setText(QString());
        groupAnswers->setTitle(QApplication::translate("MainWindow", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202\321\213 \320\276\321\202\320\262\320\265\321\202\320\260", nullptr));
        btnNext->setText(QApplication::translate("MainWindow", "| \320\222\320\277\320\265\321\200\320\265\320\264 >", nullptr));
        lblWrong->setText(QApplication::translate("MainWindow", "\320\235\320\265\320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\320\271 \320\276\321\202\320\262\320\265\321\202", nullptr));
        label->setStyleSheet(QApplication::translate("MainWindow", "color: #209920", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\321\205 \320\276\321\202\320\262\320\265\321\202\320\276\320\262:", nullptr));
        lblRightness->setText(QApplication::translate("MainWindow", "0", nullptr));
        progressBar->setFormat(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201: %v/%m", nullptr));
        btnSkip->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
