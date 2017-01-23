#include "user.h"

User::User(QString name)
{
    level = UserLevel::User;
    this->username = name;
    emit onLogin();
}
User::User(QString name, QString bosss){
    level = UserLevel::User;
    this->setUserName(name);
    this->setBoss(bosss);
    emit onLogin();
}
User::User(){
    level = UserLevel::User;
    emit onLogin();
}
User::User(QString name ,Firma* f1 ,QString boss){
    level = UserLevel::User;
    this->username = name;
    firma = f1 ;
    this->boss = boss;
    emit onLogin();
}
