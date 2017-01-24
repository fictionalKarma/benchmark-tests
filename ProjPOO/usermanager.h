#ifndef USERMAN_H
#define USERMAN_H

#include <QDebug>
#include "operations.h"
#include "userlevels.h"
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include "log.hpp"
#define DBNAME "users.db"

class UserManager
{
private:
    static QSqlDatabase my_db;
    static Log logger;

public:
    static Error openDatabaseConn();
    static Error registerUser(QString username, QString password, QString email);
    static Error removeUser(QString username);
    static Error findUserByName(QString username);
    static Error findUserByMail(QString mail);
    static Error setUserLevel(QString username, UserLevel level);
    static Error setUserName(QString username, QString newName);
    static UserLevel getUserLevel(QString username);
    static QString getUserData(QString username);
};

#endif // USERMAN_H
