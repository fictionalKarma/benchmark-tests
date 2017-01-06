#include "operations.h"

bool Operations::isValidEmail(QString& mail) {
    if (mail.length() < 3)
        return false;
    else return true;
}

bool Operations::isValidPassword(QString& pwd) {
    if (pwd.length() < 3)
        return false;
    else return true;
}

bool Operations::isValidUser(QString& name) {
    if (name.length() < 3)
        return false;
    else return true;
}

QString Operations::encode(QString arg1) {
    return QString(QCryptographicHash::hash(arg1.toUtf8(), QCryptographicHash::Md5).toHex());
}
