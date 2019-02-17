#include "Questions_CrLf.h"
#include "QuestionsUtils.h"

namespace
{
    Answer ParseAnswer(const QStringRef line)
    {
        Answer answer { };
        if (line.size() >= 1)
        {
            if (line.left(1) == "+" && line.size() > 1)
            {
                answer.isRight = true;
                answer.text = line.right(line.size() - 1).toString();
            }
            else
            {
                answer.text = line.toString();
            }
        }
        return answer;
    }

    Answers ParseAnswers(const QVector<QStringRef>& lines)
    {
        Answers answers;
        if (lines.size() < 2)
        {
            qDebug() << "Detected question with wrong answers count";
            return answers;
        }

        int rightsCount = 0;
        bool notRightWithMinuses = true;
        for (auto line : lines)
        {
            auto answer = ParseAnswer(line);
            if (answer.text.isEmpty())
            {
                return { };
            }

            if (answer.isRight)
            {
                ++rightsCount;
            }
            else if (answer.text.size() > 1 && answer.text.left(1) != "-")
            {
                notRightWithMinuses = false;
            }
            answers.push_back(answer);
        }

        if (rightsCount != 1)
        {
            qDebug() << "Detected " << rightsCount << " right answers";
            return { };
        }

        if (notRightWithMinuses)
        {
            for (auto& answer : answers)
            {
                if (!answer.isRight)
                {
                    answer.text = answer.text.right(answer.text.size() - 1);
                }
            }
        }
        return answers;
    }

    Question ParseQuestion(const QVector<QStringRef>& lines)
    {
        int firstAnswerLine = -1;
        int line = 0;
        for (; line < lines.size(); ++line)
        {
            if (lines[line].left(1) == "+" && firstAnswerLine < 0)
            {
                firstAnswerLine = line;
                break;
            }
        }

        Question question;
        question.text = ParseQuestionText(lines, firstAnswerLine);

        QVector<QStringRef> answersLines;
        for (; line < lines.size(); ++line)
        {
            answersLines.push_back(lines[line]);
        }
        question.answers = ParseAnswers(answersLines);

        if (question.text.isEmpty() || question.answers.size() < 2)
        {
            return { };
        }
        return question;
    }
}

void ParseQuestions_CrLf(const QString& fileContent, Questions& questions)
{
    QVector<QStringRef> lines = fileContent.splitRef("\n");
    int prevQuestLine = -1;
    QVector<QStringRef> curQuestion;
    for (int line = 0; line < lines.size(); ++line)
    {
        if (lines[line].isEmpty())
        {
            if (curQuestion.size() >= 3)
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
            else if (!AreLinesEmpty(curQuestion))
            {
                qWarning() << "The question started at line " << prevQuestLine + 1 << " is too small";
            }
            prevQuestLine = line;
            curQuestion.clear();
        }
        else
        {
            curQuestion.push_back(lines[line]);
        }
    }
}
