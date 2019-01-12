#include "Questions.h"

namespace
{
    QRegExp question2Start("^\\d+\\.");
    QRegExp answer2Start("^\\s*[ABCDEFАВСЕ]\\."); // Contains cyrillic symbols

    QString ParseQuestionText2(const QVector<QStringRef>& allLines, int firstAnswerLine)
    {
        QString text;
        for (int line = 0; line < firstAnswerLine; ++line)
        {
            auto questLine = allLines[line].trimmed().toString();
            if (line == 0) // delete question number
            {
                if (question2Start.indexIn(questLine) < 0 || question2Start.matchedLength() < 0)
                {
                    qDebug() << "First line was parsed wrong";
                    return { };
                }
                questLine = questLine.right(questLine.size() - question2Start.matchedLength()).trimmed();
            }
            if (!text.isEmpty())
            {
                text += " ";
            }
            text += questLine;
        }
        return text;
    }
}

Answer ParseAnswer1(const QVector<QStringRef>& tokens, int& pos)
{
    Answer answer { };
    bool isNumber = false;
    answer.isRight = tokens.at(pos).toInt(&isNumber) == 1;
    if (!isNumber)
    {
        qDebug() << "Parsing of answer rightness is failed";
    }
    bool end = false;
    for (++pos; pos < tokens.size() && !end;)
    {
        QString token = tokens.at(pos).toString();
        token.toInt(&isNumber);
        end = isNumber || token == "#";
        if (!end)
        {
            answer.text += tokens.at(pos).toString() + " ";
            ++pos;
        }
    }
    return answer;
}

Answers ParseAnswers1(const QVector<QStringRef>& tokens)
{
    Answers answers;
    if (tokens.size() < 2)
    {
        qDebug() << "Detected question with wrong answers count";
        return answers;
    }

    for (int i = 0; i < tokens.size();)
    {
        answers.push_back(ParseAnswer1(tokens, i));
    }
    return answers;
}

Question ParseQuestion1(const QStringRef& text)
{
    Question question;
    QVector<QStringRef> tokens = text.split('\n');
    if (tokens.size() > 2)
    {
        int i = 1;
        for (; i < tokens.size(); ++i)
        {
            bool isNumber = false;
            tokens.at(i).toInt(&isNumber);
            if (tokens.at(i).length() == 1 && isNumber)
            {
                break;
            }
            question.text += tokens.at(i).toString() + " ";
        }
        while (i--) {
            tokens.pop_front();
        }
        question.answers = ParseAnswers1(tokens);
    }
    return question;
}

void ParseQuestions1(const QString &fileContent, Questions &questions)
{
    for (int curIndex = fileContent.indexOf('#', 0); curIndex >= 0; )
    {
        int thisQuestion = curIndex;
        curIndex = fileContent.indexOf('#', curIndex + 1);
        int nextQuestion = (curIndex < 0) ? fileContent.size() : curIndex;
        QStringRef allQuestion(&fileContent, thisQuestion, nextQuestion - thisQuestion);
        Question question = ParseQuestion1(allQuestion);
        if (!question.IsEmpty())
        {
            questions.push_back(question);
        }
    }
}

Answer ParseAnswer2(const QStringRef& line)
{
    Answer answer;
    auto answerLine = line.toString();
    if (answer2Start.indexIn(answerLine) < 0 || answer2Start.matchedLength() < 0)
    {
        qDebug() << "Answer line was parsed wrong";
        return answer;
    }

    answer.text = answerLine.right(answerLine.size() - answer2Start.matchedLength()).trimmed();
    if (answer.text.left(1) == "*")
    {
        answer.isRight = true;
        answer.text = answer.text.right(answer.text.size() - 1).trimmed();
    }

    return answer;
}

Answers ParseAnswers2(const QVector<QStringRef>& lines)
{
    Answers answers;
    bool rightIsDetected = false;
    for (auto line : lines)
    {
        Answer answer = ParseAnswer2(line);
        if (!answer.text.isEmpty())
        {
            answers.push_back(answer);
            rightIsDetected |= answer.isRight;
        }
    }

    if (!rightIsDetected)
    {
        qDebug() << "Right answer was not detected";
        return { };
    }
    return answers;
}

Question ParseQuestion2(const QVector<QStringRef>& lines)
{
    QVector<QStringRef> answersLines;
    int firstAnswerLine = -1;
    for (int line = 0; line < lines.size(); ++line)
    {
        if (answer2Start.indexIn(lines[line].toString()) >= 0)
        {
            if (firstAnswerLine < 0)
            {
                firstAnswerLine = line;
            }
            answersLines.push_back(lines[line]);
        }
    }

    Question question;
    question.text = ParseQuestionText2(lines, firstAnswerLine);
    question.answers = ParseAnswers2(answersLines);
    if (question.text.isEmpty() || question.answers.size() < 2)
    {
        return { };
    }
    return question;
}

void ParseQuestions2(const QString &fileContent, Questions &questions)
{
    QVector<QStringRef> lines = fileContent.splitRef("\n");
    int prevQuestLine = -1;
    QVector<QStringRef> curQuestion;
    for (int line = 0; line < lines.size(); ++line)
    {
        if (question2Start.indexIn(lines[line].toString()) >= 0 || line == lines.size() - 1)
        {
            if (prevQuestLine >= 0)
            {
                Question question = ParseQuestion2(curQuestion);
                if (!question.IsEmpty())
                {
                    questions.push_back(question);
                }
                else
                {
                    qDebug() << "Can't parse question started at line " << prevQuestLine + 1; // Lines in Notepad++ started from 1
                }
            }
            prevQuestLine = line;
            curQuestion.clear();
        }
        if (!lines[line].isEmpty())
        {
            curQuestion.push_back(lines[line]);
        }
    }
}

void ParseQuestions(const QString& fileContent, Questions& questions)
{
    ParseQuestions1(fileContent, questions);
    if (!fileContent.isEmpty() && questions.empty())
    { // Try to parse questions of 2nd version
        ParseQuestions2(fileContent, questions);
    }
}

