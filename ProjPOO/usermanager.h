#ifndef USERMAN_H
#define USERMAN_H

#include <QDebug>
#include "operations.h"
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#define DBNAME "C:\\Users\\cosmi\\Desktop\\users.db"

class UserManager
{
private:
    static QSqlDatabase my_db;

public:
    static Error registerUser(QString username, QString password, QString email);
    static Error removeUser(QString username);
    static Error findUserByName(QString username);
    static Error findUserByMail(QString mail);
    static QString getUserData(QString username);
};

#endif // USERMAN_H
