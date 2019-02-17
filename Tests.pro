#-------------------------------------------------
#
# Project created by QtCreator 2017-05-31T23:05:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tests
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        MainWindow.cpp \
    Questions.cpp \
    AnswerCheckBox.cpp \
    Questions_Diez.cpp \
    Questions_Nubered.cpp \
    Questions_CrLf.cpp \
    QuestionsUtils.cpp

HEADERS  += MainWindow.h \
    Questions.h \
    AnswerCheckBox.h \
    Questions_Diez.h \
    Questions_Nubered.h \
    Questions_CrLf.h \
    QuestionsUtils.h

FORMS    += MainWindow.ui \
    AnswerCheckBox.ui
