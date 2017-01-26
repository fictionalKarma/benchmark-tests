#include "user.h"
#define DATABASE_NAME "users.db"

User::User(QString name)
{
    level = UserLevel::User;
    isAdmin = false;
    data["username"] = name;
    QString tableName="PERSONAL";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    readFromDatabase(name);
    if(data["isAdmin"]=="true")
    {isAdmin=true;}

    emit onLogin();
}
User::User(QString name, QString bosss){
    level = UserLevel::User;
    isAdmin = false;
    this->setUserName(name);
    this->setBossName(bosss);
    QString tableName="PERSONAL";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    readFromDatabase(name);
    if(data["isAdmin"]=="true")
        isAdmin=true;

    emit onLogin();
}
User::User(){
    level = UserLevel::User;
    isAdmin = false;
    QString tableName="PERSONAL";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    emit onLogin();
}
User::User(QString name ,Firma* f1 ,QString boss){
    level = UserLevel::User;
    isAdmin = false;
    data["username"] = name;
    firma = f1 ;
    this->setBossName(boss);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    readFromDatabase(name);
    if(data["isAdmin"]=="true")
        isAdmin=true;
    emit onLogin();
}

void User::readFromDatabase(QString name) {
    data = UserManager::getUserData(name);
}

