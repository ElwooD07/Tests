#include "QuestionsUtils.h"

QString ParseQuestionText(const QVector<QStringRef>& allLines, int firstAnswerLine)
{
    QString text;
    for (int line = 0; line < firstAnswerLine; ++line)
    {
        auto questLine = allLines[line].trimmed().toString();
        if (!text.isEmpty())
        {
            text += " ";
        }
        text += questLine;
    }
    return text;
}

bool AreLinesEmpty(const QVector<QStringRef>& lines)
{
    for (auto& line : lines)
    {
        if (!line.isEmpty())
        {
            return false;
        }
    }
    return true;
}
