#include "quizzestest.h"
#include "../src/quizhelper.h"

#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

using namespace quiz;
void QuizzesTest::testGetQuizzes()
{
    QuizHelper q;
    QCOMPARE(q.isValid(), true);
}
