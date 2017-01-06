#include "usermanager.h"

QSqlDatabase UserManager::my_db;

Error UserManager::registerUser(QString username, QString password, QString email) {
    if (!my_db.isOpen()) {
        my_db.open();
    }

    QString newUser = Operations::encode(username);
    QString newPass = Operations::encode(password);
    QString newMail = Operations::encode(email);

    QSqlQuery query;
    QString sql = "SELECT name FROM sqlite_master WHERE type=table AND name=USERS;";
    query.exec(sql);
    if (!query.next()) {
        sql = "CREATE TABLE USERS (id integer primary key, username text, password text, email text);";
        query.exec(sql);
    }

    sql = "INSERT INTO USERS (username, password, email) VALUES (:name, :pass, :email);";
    query.prepare(sql);
    query.bindValue(":name", newUser);
    query.bindValue(":pass", newPass);
    query.bindValue(":email", newMail);
    query.exec();

    my_db.close();
    return OK;
}


Error UserManager::findUserByName(QString name) {
    if (!my_db.isOpen()) {
        my_db = QSqlDatabase::addDatabase("QSQLITE");
        my_db.setDatabaseName(DBNAME);
        my_db.open();
    }

    name = Operations::encode(name);
    QSqlQuery query;
    QString sql = "SELECT username FROM USERS WHERE username=(:name);";
    query.prepare(sql);
    query.bindValue(":name", name);
    if (query.exec()) {
        if (query.next()) {
            return OK;
        }
    }

    my_db.close();
    return ERROR;
}


Error UserManager::findUserByMail(QString mail) {
    if (!my_db.isOpen()) {
        my_db = QSqlDatabase::addDatabase("QSQLITE");
        my_db.setDatabaseName(DBNAME);
        my_db.open();
    }

    mail = Operations::encode(mail);
    QSqlQuery query;
    QString sql = "SELECT email FROM USERS WHERE email=(:mail);";
    query.prepare(sql);
    query.bindValue(":mail", mail);
    if (query.exec()) {
        if (query.next()) {
            return OK;
        }
    }

    my_db.close();
    return ERROR;
}

QString UserManager::getUserData(QString username) {
    if (!my_db.isOpen()) {
        my_db = QSqlDatabase::addDatabase("QSQLITE");
        my_db.setDatabaseName(DBNAME);
        my_db.open();
    }

    QString result = "";
    username = Operations::encode(username);
    QSqlQuery query;
    QString sql = "SELECT username,password,email FROM USERS WHERE username=(:name);";
    query.prepare(sql);
    query.bindValue(":name", username);
    if (query.exec()) {
        if (query.next()) {
            result = result + query.record().value(0).toString() + "," + query.record().value(1).toString() + "," + query.record().value(2).toString();
        }

        else result = "404";
    }
    return result;
}
