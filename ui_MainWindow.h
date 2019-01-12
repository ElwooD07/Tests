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
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnBrowse;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineMaxQuestions;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnReload;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *lblQuestionsTotal;
    QSpacerItem *horizontalSpacer;
    QLabel *lblProgressTitle;
    QLabel *lblProgress;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *lblRightness;
    QGroupBox *groupQuestion;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblQuestion;
    QGroupBox *groupAnswers;
    QVBoxLayout *answersLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnNext;
    QLabel *lblWrong;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSkip;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(815, 480);
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
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, -1, -1);
        btnBrowse = new QPushButton(groupTest);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));

        horizontalLayout_5->addWidget(btnBrowse);

        label_4 = new QLabel(groupTest);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit = new QLineEdit(groupTest);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit);


        horizontalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        label_2 = new QLabel(groupTest);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineMaxQuestions = new QLineEdit(groupTest);
        lineMaxQuestions->setObjectName(QStringLiteral("lineMaxQuestions"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineMaxQuestions->sizePolicy().hasHeightForWidth());
        lineMaxQuestions->setSizePolicy(sizePolicy1);
        lineMaxQuestions->setMinimumSize(QSize(0, 0));
        lineMaxQuestions->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(lineMaxQuestions);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, -1, -1);
        btnReload = new QPushButton(groupTest);
        btnReload->setObjectName(QStringLiteral("btnReload"));
        btnReload->setStyleSheet(QStringLiteral("color: #501010"));

        horizontalLayout_6->addWidget(btnReload);


        horizontalLayout->addLayout(horizontalLayout_6);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addWidget(groupTest);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, -1, 10, -1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lblQuestionsTotal = new QLabel(centralWidget);
        lblQuestionsTotal->setObjectName(QStringLiteral("lblQuestionsTotal"));

        horizontalLayout_2->addWidget(lblQuestionsTotal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lblProgressTitle = new QLabel(centralWidget);
        lblProgressTitle->setObjectName(QStringLiteral("lblProgressTitle"));

        horizontalLayout_2->addWidget(lblProgressTitle);

        lblProgress = new QLabel(centralWidget);
        lblProgress->setObjectName(QStringLiteral("lblProgress"));

        horizontalLayout_2->addWidget(lblProgress);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lblRightness = new QLabel(centralWidget);
        lblRightness->setObjectName(QStringLiteral("lblRightness"));
        lblRightness->setStyleSheet(QStringLiteral("color: #209920"));

        horizontalLayout_2->addWidget(lblRightness);


        verticalLayout->addLayout(horizontalLayout_2);

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
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        btnNext->setFont(font);
        btnNext->setAutoDefault(true);

        horizontalLayout_3->addWidget(btnNext);

        lblWrong = new QLabel(centralWidget);
        lblWrong->setObjectName(QStringLiteral("lblWrong"));
        lblWrong->setStyleSheet(QStringLiteral("color: #cc2020;"));

        horizontalLayout_3->addWidget(lblWrong);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnSkip = new QPushButton(centralWidget);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        sizePolicy2.setHeightForWidth(btnSkip->sizePolicy().hasHeightForWidth());
        btnSkip->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(btnSkip);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 5);
        verticalLayout->setStretch(4, 1);
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
        label_4->setText(QApplication::translate("MainWindow", ":", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201\320\276\320\262:", nullptr));
        lineMaxQuestions->setInputMask(QString());
        lineMaxQuestions->setText(QApplication::translate("MainWindow", "20", nullptr));
        btnReload->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262:", nullptr));
        lblQuestionsTotal->setText(QApplication::translate("MainWindow", "0", nullptr));
        lblProgressTitle->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201:", nullptr));
        lblProgress->setText(QApplication::translate("MainWindow", "0/0", nullptr));
        label->setStyleSheet(QApplication::translate("MainWindow", "color: #209920", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\321\205 \320\276\321\202\320\262\320\265\321\202\320\276\320\262:", nullptr));
        lblRightness->setText(QApplication::translate("MainWindow", "0", nullptr));
        groupQuestion->setTitle(QApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        lblQuestion->setText(QString());
        groupAnswers->setTitle(QApplication::translate("MainWindow", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202\321\213 \320\276\321\202\320\262\320\265\321\202\320\260", nullptr));
        btnNext->setText(QApplication::translate("MainWindow", "| \320\222\320\277\320\265\321\200\320\265\320\264 >", nullptr));
        lblWrong->setText(QApplication::translate("MainWindow", "\320\235\320\265\320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\320\271 \320\276\321\202\320\262\320\265\321\202", nullptr));
        btnSkip->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
