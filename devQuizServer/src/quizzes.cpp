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

void Quizzes::uuid(Context *c, const QString &uuid)
{
    qDebug() << Q_FUNC_INFO << uuid;
}

void Quizzes::uuid_GET(Context *c, const QString &uuid)
{
    qDebug() << Q_FUNC_INFO << uuid;
    QSettings s;
    if (s.childGroups().contains(uuid))
    {
        s.beginGroup(uuid);
        c->response()->setJsonObjectBody({{QStringLiteral("title"), s.value(QStringLiteral("title")).toString()},
                                          {QStringLiteral("description"), s.value(QStringLiteral("description")).toString()},
                                          {QStringLiteral("type"), s.value(QStringLiteral("type")).toInt()}});
    }
    else
    {
        c->response()->setJsonObjectBody({{QStringLiteral("error"), QStringLiteral("not found")}});
        c->response()->setStatus(Response::NotFound);
    }
}

void Quizzes::uuid_PUT(Context *c, const QString &uuid)
{
    qDebug() << Q_FUNC_INFO << uuid;
    const QJsonDocument doc = c->request()->bodyData().toJsonDocument();
    const QJsonObject obj = doc.object();
    qDebug() << obj.value(QStringLiteral("title")).toString() << "\n";

    QSettings s;
    s.beginGroup(uuid);
    s.setValue(QStringLiteral("title"), obj.value(QStringLiteral("title")).toString());
    s.setValue(QStringLiteral("description"), obj.value(QStringLiteral("description")).toString());
    s.setValue(QStringLiteral("type"), obj.value(QStringLiteral("type")).toInt());
    s.endGroup();
    s.sync();

    if (s.status()) {
        c->response()->setJsonObjectBody({{QStringLiteral("status"), QStringLiteral("error")},
                                          {QStringLiteral("error"), QStringLiteral("failed")}});
    } else {
        c->response()->setJsonObjectBody({{QStringLiteral("status"), QStringLiteral("ok")},
                                          {QStringLiteral("uuid"), uuid}});
    }
}

void Quizzes::create(Context *c)
{
    qDebug() << Q_FUNC_INFO;
    const QString uuid = QUuid::createUuid().toString().remove(QLatin1Char('{')).remove(QLatin1Char('}'));
    uuid_PUT(c, uuid);
}


void Quizzes::list_GET(Cutelyst::Context *c)
{
    qDebug() << Q_FUNC_INFO;
    QSettings s;
    const QStringList uuids = s.childGroups();


    const QString id_str("id");
    const QString title_str("title");
    const QString desc_str("description");
    const QString type_str("type");

    QJsonArray quizArray;
    for (auto uuid : uuids) {
        QJsonObject item_data;
        s.beginGroup(uuid);
        item_data.insert(id_str, uuid);
        item_data.insert(title_str, QJsonValue(s.value(QStringLiteral("title")).toString()));
        item_data.insert(desc_str, QJsonValue(s.value(QStringLiteral("description")).toString()));
        item_data.insert(type_str, QJsonValue(s.value(QStringLiteral("type")).toInt()));
        quizArray.push_back(QJsonValue(item_data));
        s.endGroup();
    }

    QJsonObject responseObj;

    responseObj.insert(QString("content"), QJsonValue(quizArray));
    c->response()->setJsonObjectBody(responseObj);
}