#ifndef QUIZ_TEST_H
#define QUIZ_TEST_H
#include <QtTest/QtTest>
#include <QtCore/QObject>

#include "AutoTest.h"

namespace quiz
{
class QuizzesTest : public QObject
{
  Q_OBJECT
private slots:
  void testGetQuizzes();
};
}
#endif

DECLARE_TEST(quiz::QuizzesTest)
