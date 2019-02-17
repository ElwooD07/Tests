#include "Questions_Diez.h"

namespace
{
    Answer ParseAnswer(const QVector<QStringRef>& tokens, int& pos)
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

    Answers ParseAnswers(const QVector<QStringRef>& tokens)
    {
        Answers answers;
        if (tokens.size() < 2)
        {
            qDebug() << "Detected question with wrong answers count";
            return answers;
        }

        for (int i = 0; i < tokens.size();)
        {
            answers.push_back(ParseAnswer(tokens, i));
        }
        return answers;
    }

    Question ParseQuestion(const QStringRef& text)
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
            question.answers = ParseAnswers(tokens);
        }
        return question;
    }
}

void ParseQuestions_Diez(const QString& fileContent, Questions& questions)
{
    for (int curIndex = fileContent.indexOf('#', 0); curIndex >= 0; )
    {
        int thisQuestion = curIndex;
        curIndex = fileContent.indexOf('#', curIndex + 1);
        int nextQuestion = (curIndex < 0) ? fileContent.size() : curIndex;
        QStringRef allQuestion(&fileContent, thisQuestion, nextQuestion - thisQuestion);
        Question question = ParseQuestion(allQuestion);
        if (!question.IsEmpty())
        {
            questions.push_back(question);
        }
    }
}
