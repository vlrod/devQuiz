#ifndef QUIZZES_H
#define QUIZZES_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Quizzes : public Controller
{
    Q_OBJECT
public:
    explicit Quizzes(QObject *parent = nullptr);
    ~Quizzes();

    C_ATTR(index,
           : Path("/quizzes")
           : AutoArgs)
    void index(Cutelyst::Context *c) const;

    C_ATTR(base,
           : Chained("/")
           : PathPart("quizzes")
           : CaptureArgs(0))
    void base(Cutelyst::Context *) const;
};

#endif //QUIZZES_H

