#ifndef BDONNE_H
#define BDONNE_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>
//#include <QSqlQuery>
#include <iostream>
#include <map>
//Json
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "contact.h"
#include "interaction.h"
#include "tache.h"
class bdonne : public QObject
{
     Q_OBJECT

private:
    QSqlDatabase db;
    contact *c;
    Interaction *I;
    Tache *T;
    string idC;
    string idI;
    string idT;
public:
    explicit bdonne(QObject *parent = nullptr);
    ~bdonne();

    QJsonArray remplirJson();

signals:


public slots:

};

#endif // BDONNE_H
