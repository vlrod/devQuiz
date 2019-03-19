#ifndef DEVQUIZSERVER_H
#define DEVQUIZSERVER_H

#include <Cutelyst/Application>

using namespace Cutelyst;

class devQuizServer : public Application
{
    Q_OBJECT
    CUTELYST_APPLICATION(IID "devQuizServer")
public:
    Q_INVOKABLE explicit devQuizServer(QObject *parent = nullptr);
    ~devQuizServer();

    bool init();
};

#endif //DEVQUIZSERVER_H

