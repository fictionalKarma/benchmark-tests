#include "user.h"


User::User(QString name)
{
    level = 0;
    this->username = name;
    emit onLogin();
}
User::User(QString name, QString bosss){
    level = 0 ;
    this->setUserName(name);
    this->setBoss(bosss);
    emit onLogin();
}
User::User(){
    level = 0;
    emit onLogin();
}
User::User(QString name ,Firma* f1 ,QString boss){
    level = 0;
    this->username = name;
    firma = f1 ;
    this->boss = boss;
    emit onLogin();
}
