#include "Questions_Nubered.h"
#include "QuestionsUtils.h"

namespace
{
    QRegExp question2Start("^\\d+\\.");
    QRegExp answer2Start("^\\s*[ABCDEFАВСЕ]\\."); // Contains cyrillic symbols

    QString ParseAndCheckQuestionText(const QVector<QStringRef>& allLines, int firstAnswerLine)
    {
        QString questText = ParseQuestionText(allLines, firstAnswerLine);
        if (question2Start.indexIn(questText) < 0 || question2Start.matchedLength() < 0)
        {
            qDebug() << "First line was parsed wrong";
            return { };
        }
        return questText.right(questText.size() - question2Start.matchedLength()).trimmed();
    }

    Answer ParseAnswer(const QStringRef& line)
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

    Answers ParseAnswers(const QVector<QStringRef>& lines)
    {
        Answers answers;
        bool rightIsDetected = false;
        for (auto line : lines)
        {
            Answer answer = ParseAnswer(line);
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

    Question ParseQuestion(const QVector<QStringRef>& lines)
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
        question.text = ParseAndCheckQuestionText(lines, firstAnswerLine);
        question.answers = ParseAnswers(answersLines);
        if (question.text.isEmpty() || question.answers.size() < 2)
        {
            return { };
        }
        return question;
    }
}

void ParseQuestions_Numbered(const QString& fileContent, Questions& questions)
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
                Question question = ParseQuestion(curQuestion);
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
