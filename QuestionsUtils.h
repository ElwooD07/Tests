#pragma once
#include <QtCore>

QString ParseQuestionText(const QVector<QStringRef>& allLines, int firstAnswerLine);
bool AreLinesEmpty(const QVector<QStringRef>& lines);
