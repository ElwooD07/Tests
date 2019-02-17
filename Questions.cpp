#include "Questions.h"
#include "Questions_Nubered.h"
#include "Questions_Diez.h"
#include "Questions_CrLf.h"

void ParseQuestions(const QString& fileContent, Questions& questions)
{
    ParseQuestions_Numbered(fileContent, questions);
    if (!fileContent.isEmpty() && questions.empty())
    {
        ParseQuestions_Diez(fileContent, questions);
    }
    if (!fileContent.isEmpty() && questions.empty())
    {
        ParseQuestions_CrLf(fileContent, questions);
    }
}

