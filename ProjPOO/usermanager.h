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
    static bool existaSupervisor(QString, QString table);
    static bool openDatabaseConn();
    static bool registerUser(QString username, QString password, QString email);
    static bool registerUserData(QString username, QMap<QString, QString> stringList);
    static bool removeUser(QString username);
    static bool findUserByName(QString username);
    static bool findUserByMail(QString mail);
    static bool setUserLevel(QString username, UserLevel level);
    static bool setUserName(QString username, QString newName);
    static void setUserData(QString username, QMap<QString, QString> newData);
    static UserLevel getUserLevel(QString username);
    static QMap<QString, QString> getUserData(QString username);
    static void createTableFirma(QString numeFirma);
    static bool checkExistance(QString numeFirma);
    static void insertIntoFirma(QString ,QString,QString );

    static QString getAdmin(QString company);
    static std::vector<QString> fetchCopii(QString company , QString boss);
};

#endif // USERMAN_H
