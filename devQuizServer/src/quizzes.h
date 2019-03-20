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

    C_ATTR(uuid,
           : Path('/quizzes')
           : AutoArgs
           : ActionClass(REST))
    void uuid(Context *c, const QString &uuid);

    C_ATTR(uuid_GET,
           : Private)
    void uuid_GET(Context *c, const QString &uuid);

    C_ATTR(list_GET,
           : Chained("base")
           : PathPart("list")
           : Args(0))
    void list_GET(Cutelyst::Context *c);

    C_ATTR(create,
           : Chained("base")
           : PathPart("create")
           : Args(0))
    void create(Cutelyst::Context *c);

    C_ATTR(uuid_PUT,
           : Private)
    void uuid_PUT(Context *c, const QString &uuid);
};

#endif //QUIZZES_H

