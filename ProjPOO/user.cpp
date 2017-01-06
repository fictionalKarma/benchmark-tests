#include "user.h"

User::User(QString name)
{
    this->username = name;
    emit onLogin();
}
