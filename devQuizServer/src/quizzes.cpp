#include "quizzes.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <QUuid>
#include <QDebug>
using namespace Cutelyst;

Quizzes::Quizzes(QObject *parent) : Controller(parent)
{
}

Quizzes::~Quizzes()
{
}

// FIXME: use another database
void Quizzes::index(Context *c) const
{
    qDebug() << Q_FUNC_INFO;
    QSettings s;
    const QStringList uuids = s.childGroups();

    c->response()->setJsonArrayBody(QJsonArray::fromStringList(uuids));
}

void Quizzes::base(Context *c) const
{
    qDebug() << "Quizzes::base\n";
    c->response()->setHeader("Cache-Control", "no-cache, no-store, must-revalidate");
}