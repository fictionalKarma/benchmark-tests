#include "usermanager.h"

QSqlDatabase UserManager::my_db;
Log UserManager::logger;

bool UserManager::registerUser(QString username, QString password, QString email) {
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
    }

    sql = "INSERT INTO USERS (username, password, email, level) VALUES (:name, :pass, :email, \'USER\');";
    query.prepare(sql);
    query.bindValue(":name", username);
    query.bindValue(":pass", newPass);
    query.bindValue(":email", email);
    query.exec();

    my_db.close();
    return true;
}


bool UserManager::findUserByName(QString name) {
    if (!my_db.open()) {
        openDatabaseConn();
    }

    QSqlQuery query(my_db);
    QString sql = "SELECT username FROM USERS WHERE username=(:name);";
    query.prepare(sql);
    query.bindValue(":name", name);
    if (query.exec()) {
        if (query.next()) {
            return true;
        }
    }

    my_db.close();
    return false;
}


bool UserManager::findUserByMail(QString mail) {
    if (!my_db.open()) {
        openDatabaseConn();
    }

    QSqlQuery query(my_db);
    QString sql = "SELECT email FROM USERS WHERE email=(:mail);";
    query.prepare(sql);
    query.bindValue(":mail", mail);
    if (query.exec()) {
        if (query.next()) {
            return true;
        }
    }

    my_db.close();
    return false;
}

QMap<QString, QString> UserManager::getUserData(QString username) {
    if (!my_db.isOpen()) {
        openDatabaseConn();
    }

    if (!findUserByName(username)) {
        logger.addLog(USER_NOT_EXISTS(username));
    }

    QMap<QString, QString> result;
    QSqlQuery query(my_db);
    query.prepare("SELECT username, password, email, level FROM USERS WHERE username=(:name);");
    query.bindValue(":name", username);
    query.exec();
    if (query.next()) {
        result.insert("username", query.record().value(0).toString());
        result.insert("password", query.record().value(1).toString());
        result.insert("email", query.record().value(2).toString());
        result.insert("level", query.record().value(3).toString());
    }

    query.prepare("SELECT name, cnp, address, company, salary, boss, department  FROM PERSONAL WHERE username=(:name);");
    query.bindValue(":name", username);
    query.exec();
    if (query.next()) {
        result.insert("name", query.record().value(0).toString());
        result.insert("cnp", query.record().value(1).toString());
        result.insert("address", query.record().value(2).toString());
        result.insert("company", query.record().value(3).toString());
        result.insert("salary", query.record().value(4).toString());
        result.insert("boss", query.record().value(5).toString());
        result.insert("department", query.record().value(6).toString());

    }

    query.prepare("SELECT transport_comp, teamwork, negotiation, analysis, presentation, social, decision, timemanage FROM COMPETENCES WHERE name=(:name);");
    query.bindValue(":name", result["name"]);
    query.exec();
    if (query.next()) {
        result.insert("transport_comp", query.record().value(0).toString());
        result.insert("teamwork", query.record().value(1).toString());
        result.insert("negotiation", query.record().value(2).toString());
        result.insert("analysis", query.record().value(3).toString());
        result.insert("presentation", query.record().value(4).toString());
        result.insert("social", query.record().value(5).toString());
        result.insert("decision", query.record().value(6).toString());
        result.insert("time_management", query.record().value(7).toString());
    }

    query.prepare("SELECT project_man, iata_lic, adr_lic, sixsigma, it_manage, time_manage, admin FROM EXPERTISE WHERE name=(:name);");
    query.bindValue(":name", result["name"]);
    query.exec();
    if (query.next()) {
        result.insert("project_management", query.record().value(0).toString());
        result.insert("iata_license", query.record().value(1).toString());
        result.insert("adr_license", query.record().value(2).toString());
        result.insert("sixsigma_belt", query.record().value(3).toString());
        result.insert("it_management", query.record().value(4).toString());
        result.insert("time_training", query.record().value(5).toString());
        result.insert("isAdmin",query.record().value(6).toString());
        //qDebug()<<"this user is admin"<<result["isAdmin"];
    }
    my_db.close();
    return result;
}

bool UserManager::openDatabaseConn() {
    my_db = QSqlDatabase::addDatabase("QSQLITE", "userdb");
    my_db.setDatabaseName(DBNAME);
    if (!my_db.open())
        qDebug() << "Database bool!";
    return true;
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

bool UserManager::setUserLevel(QString username, UserLevel level) {
    if (!my_db.open()) {
        openDatabaseConn();
    }
    QString levels[] = {"USER", "MANAGER", "ADMINISTRATOR"};

    if (!findUserByName(username)) {
        logger.addLog(USER_NOT_EXISTS(username));
        return false;
    }

    QSqlQuery query(my_db);
    query.prepare("UPDATE USERS SET level=(:level) WHERE username=(:name);");
    query.bindValue(":name", username);
    query.bindValue(":level", levels[(int)level]);
    if(!query.exec()) {
        logger.addLog(FAILED_USER_LEVELCHANGE(username));
        return false;
    }
    return true;
}

bool UserManager::setUserName(QString username, QString newName) {
    if (!my_db.open()) {
        openDatabaseConn();
    }

    if (!Operations::isValidUser(newName)) {
        logger.addLog(USERNAME_NOT_VALID(newName));
        return false;
    }

    if (!findUserByName(username)) {
        logger.addLog(USER_NOT_EXISTS(username));
        return false;
    }

    QSqlQuery query(my_db);
    query.prepare("UPDATE USERS SET username=(:newn) WHERE username=(:name);");
    query.bindValue(":name", username);
    query.bindValue(":newn", newName);
    if(!query.exec()) {
        logger.addLog(FAILED_USER_NAMECHANGE(username));
        return false;
    }
    return true;
}

bool UserManager::registerUserData(QString username, QMap<QString, QString> stringList) {
    if (!my_db.isOpen()) {
        openDatabaseConn();
    }

    QSqlQuery query(my_db);
    QString sql = "SELECT name FROM sqlite_master WHERE type=table AND name=PERSONAL;";
    query.exec(sql);
    if (!query.next()) {
        sql = "CREATE TABLE PERSONAL (id integer primary key, name text, cnp number, address text, company text, salary number, boss text, department text, username text);";
        query.exec(sql);
        sql = "CREATE TABLE COMPETENCES (id integer primary key, name text, transport_comp text, teamwork text, negotiation text, analysis text, presentation text, social text, decision text, timemanage text);";
        query.exec(sql);
        sql = "CREATE TABLE EXPERTISE (id integer primary key, name text, project_man text, iata_lic text, adr_lic text, sixsigma text, it_manage text, time_manage text, admin text);";
        query.exec(sql);
    }

    //Personal Data
    sql = "INSERT INTO PERSONAL (name, cnp, address, company, salary, boss, department, username) VALUES (:name, :cnp, :address, :company, :salary, :boss, :department, :un);";
    query.prepare(sql);
    query.bindValue(":name", stringList["name"]);
    query.bindValue(":cnp", stringList["cnp"]);
    query.bindValue(":address", stringList["address"]);
    query.bindValue(":company", stringList["company"]);
    query.bindValue(":salary", stringList["salary"]);
    query.bindValue(":boss", stringList["boss"]);
    query.bindValue(":department", stringList["department"]);
    query.bindValue(":un", username);
    query.exec();

           // Competences
    sql = "INSERT INTO COMPETENCES (name, transport_comp, teamwork, negotiation, analysis, presentation, social, decision, timemanage) VALUES (:name, :trans, :team, :neg, :data, :pres, :social, :deci, :time);";
    query.prepare(sql);
    query.bindValue(":name", stringList["name"]);
    query.bindValue(":trans", stringList["drivingComp"]);
    query.bindValue(":team", stringList["teamwork"]);
    query.bindValue(":neg", stringList["negotiation"]);
    query.bindValue(":data", stringList["analysis"]);
    query.bindValue(":pres", stringList["presentation"]);
    query.bindValue(":social", stringList["social"]);
    query.bindValue(":deci", stringList["decision"]);
    query.bindValue(":time", stringList["timemanage"]);
    query.exec();
          // Expertise
    sql = "INSERT INTO EXPERTISE (name, project_man, iata_lic, adr_lic, sixsigma, it_manage, time_manage,admin) VALUES (:name, :proj, :iata, :adr, :sigma, :itm, :time_man,:admin)";
    query.prepare(sql);
    query.bindValue(":name", stringList["name"]);
    query.bindValue(":proj", stringList["projmanage"]);
    query.bindValue(":iata", stringList["iata"]);
    query.bindValue(":adr", stringList["adr"]);
    query.bindValue(":sigma", stringList["sixsigma"]);
    query.bindValue(":itm", stringList["itman"]);
    query.bindValue(":time_man", stringList["timeman"]);
    query.bindValue(":admin",stringList["admin"]);
    qDebug()<<query.exec();

    my_db.close();
    return true;
}

void UserManager::setUserData(QString username, QMap<QString, QString> newData) {

}
bool UserManager::checkExistance(QString numeFirma){
    if(!my_db.isOpen())
        openDatabaseConn();
    QString sql ="SELECT count(*) FROM "+numeFirma+";";
    QSqlQuery query(my_db);
    query.prepare(sql);
    query.exec();
    my_db.close();
    if(!query.next())
    {
        return false;
    }
    return true;

}
void UserManager::insertIntoFirma(QString angajat,QString boss,QString firma)
{
    if(!my_db.isOpen())
        openDatabaseConn();
    QString sql="INSERT INTO "+firma+"  (username, boss) VALUES (:username , :boss );";
    qDebug()<<sql;
//sql = "INSERT INTO USERS (username, password, email, level) VALUES (:name, :pass, :email, \'USER\');";

    QSqlQuery query(my_db);
    query.prepare(sql);
    query.bindValue(":username",angajat);
    query.bindValue(":boss",boss);
    qDebug()<<"Introdu angajat "+angajat<<query.exec();
    my_db.close();
}

void UserManager::createTableFirma(QString numeFirma){
    if(!my_db.isOpen())
        openDatabaseConn();
    QString sql = "CREATE TABLE "+numeFirma+" ( username TEXT , boss TEXT);";
    QSqlQuery querry(my_db);
    querry.prepare(sql);

    qDebug()<<"Querry create table FIRMA "<< querry.exec() ;
    my_db.close();
}
