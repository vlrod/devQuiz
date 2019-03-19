#include "devquizserver.h"

#include "quizzes.h"

using namespace Cutelyst;

devQuizServer::devQuizServer(QObject *parent) : Application(parent)
{
}

devQuizServer::~devQuizServer()
{
}

bool devQuizServer::init()
{
    new Quizzes(this);

    return true;
}

