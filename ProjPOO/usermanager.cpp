#include "usermanager.h"

QSqlDatabase UserManager::my_db;
Log UserManager::logger;

Error UserManager::registerUser(QString username, QString password, QString email) {
    if (!my_db.open()) {
        openDatabaseConn();
    }
    QString newPass = Operations::encode(password);

    QSqlQuery query(my_db);
    QString sql = "SELECT name FROM sqlite_master WHERE type=table AND name=USERS;";
    query.exec(sql);
    if (!query.next()) {
        sql = "CREATE TABLE USERS (id integer primary key, username text, password text, email text, level text);";
        query.exec(sql);
        query.exec("INSERT INTO USERS (username, password, email, level) VALUES (\'admin\', '" + Operations::encode("admin") + "', \'none\', \'ADMINISTRATOR\');");
    }

    sql = "INSERT INTO USERS (username, password, email, level) VALUES (:name, :pass, :email, \'USER\');";
    query.prepare(sql);
    query.bindValue(":name", username);
    query.bindValue(":pass", newPass);
    query.bindValue(":email", email);
    query.exec();

    my_db.close();
    return OK;
}


Error UserManager::findUserByName(QString name) {
    if (!my_db.open()) {
        openDatabaseConn();
    }

    QSqlQuery query(my_db);
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
    if (!my_db.open()) {
        openDatabaseConn();
    }

    QSqlQuery query(my_db);
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
    if (!my_db.open()) {
        openDatabaseConn();
    }

    if (!findUserByName(username)) {
        logger.addLog(USER_NOT_EXISTS(username));
    }

    QString result = "";
    QSqlQuery query(my_db);
    QString sql = "SELECT username,password,email FROM USERS WHERE username=(:name);";
    query.prepare(sql);
    query.bindValue(":name", username);
    if (query.exec()) {
        if (query.next()) {
            result = result + query.record().value(0).toString() + "," + query.record().value(1).toString() + "," + query.record().value(2).toString() + "," + query.record().value(3).toString();
        }

        else result = "404";
    }

    my_db.close();
    return result;
}

Error UserManager::openDatabaseConn() {
    my_db = QSqlDatabase::addDatabase("QSQLITE", "userdb");
    my_db.setDatabaseName(DBNAME);
    if (!my_db.open())
        qDebug() << "Database Error!";
    return OK;
}

UserLevel UserManager::getUserLevel(QString username) {
    if (!my_db.open()) {
        openDatabaseConn();
    }

    if (!findUserByName(username)) {
        return UserLevel::User;
    }

    QSqlQuery query(my_db);
    query.prepare("SELECT level FROM USERS WHERE username=(:name);");
    query.bindValue(":name", username);
    query.exec();
    query.next();
    QString response = query.record().value(0).toString();
    my_db.close();
    if (response == "USER") return UserLevel::User;
    if (response == "MANAGER") return UserLevel::Manager;
    if (response == "ADMINISTRATOR") return UserLevel::Administrator;
    return UserLevel::User;
}

Error UserManager::setUserLevel(QString username, UserLevel level) {
    if (!my_db.open()) {
        openDatabaseConn();
    }
    QString levels[] = {"USER", "MANAGER", "ADMINISTRATOR"};

    if (!findUserByName(username)) {
        logger.addLog(USER_NOT_EXISTS(username));
        return ERROR;
    }

    QSqlQuery query(my_db);
    query.prepare("UPDATE USERS SET level=(:level) WHERE username=(:name);");
    query.bindValue(":name", username);
    query.bindValue(":level", levels[(int)level]);
    if(!query.exec()) {
        logger.addLog(FAILED_USER_LEVELCHANGE(username));
        return ERROR;
    }
    return OK;
}

Error UserManager::setUserName(QString username, QString newName) {
    if (!my_db.open()) {
        openDatabaseConn();
    }

    if (!Operations::isValidUser(newName)) {
        logger.addLog(USERNAME_NOT_VALID(newName));
        return ERROR;
    }

    if (!findUserByName(username)) {
        logger.addLog(USER_NOT_EXISTS(username));
        return ERROR;
    }

    QSqlQuery query(my_db);
    query.prepare("UPDATE USERS SET username=(:newn) WHERE username=(:name);");
    query.bindValue(":name", username);
    query.bindValue(":newn", newName);
    if(!query.exec()) {
        logger.addLog(FAILED_USER_NAMECHANGE(username));
        return ERROR;
    }
    return OK;
}
