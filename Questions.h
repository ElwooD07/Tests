#pragma once
#include <QtCore>

struct Answer
{
    bool isRight;
    QString text;
};
using Answers = QVector<Answer>;

struct Question
{
    QString text;
    Answers answers;
    bool IsEmpty() const { return text.isEmpty() || answers.isEmpty(); }
    bool passed = false;
};
using Questions = QVector<Question>;


Answer ParseAnswer1(const QVector<QStringRef>& tokens, int& pos);
Answers ParseAnswers1(const QVector<QStringRef>& tokens);
Question ParseQuestion1(const QStringRef& text);
void ParseQuestions1(const QString& fileContent, Questions& questions);

Answer ParseAnswer2(const QVector<QStringRef>& tokens, int& pos);
Answers ParseAnswers2(const QVector<QStringRef>& tokens);
Question ParseQuestion2(const QStringRef& text);
void ParseQuestions2(const QString& fileContent, Questions& questions);

void ParseQuestions(const QString& fileContent, Questions& questions);
