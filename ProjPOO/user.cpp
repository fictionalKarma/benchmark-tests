#include "user.h"

User::User(QString name)
{
    this->username = name;
    emit onLogin();
}
User::User(QString name, QString bosss){
    this->setUserName(name);
    this->setBoss(bosss);
    emit onLogin();
}
User::User(){
    emit onLogin();
}
