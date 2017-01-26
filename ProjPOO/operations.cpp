#include "operations.h"

bool Operations::isValidEmail(QString mail) {
    if (mail.length() < 10)
        return false;
    if (mail.contains(' '))
        return false;
    if (!mail.contains('@') && !mail.contains(".com"))
        return false;
    for(QChar c : mail) {
        if (c > 122) return false;
        if (c < 97) {
            if (c == 95 || c == 46) continue;
            if (c >= 65 || c <= 90) continue;
            return false;
        }
    }

    return true;
}

bool Operations::isValidPassword(QString pwd) {
    if (pwd.length() < 6)
        return false;
    auto containsDigit = [pwd]() {
      for (QChar c : pwd) {
          if (c.isDigit()) return true;
      }
      return false;
    }();
    if (!containsDigit)
        return false;

    return true;
}

bool Operations::isValidUser(QString name) {
    if (name.length() < 3)
        return false;

    if (name.contains(' '))
        return false;

    for(QChar c : name) {
        if (c > 122) return false;
        if (c < 97) {
            if (c.isDigit()) continue;
            if (c >= 65 && c <= 90) continue;
            return false;
        }
    }

    return true;
}

bool Operations::isValidName(QString name) {
    if (name.length() < 3)
        return false;
    name = name.trimmed();

    for(QChar c : name) {
        if (c.isLetter() || c.isSpace()) continue;
        else return false;
    }

    return true;
}

QString Operations::encode(QString arg1) {
    return QString(QCryptographicHash::hash(arg1.toUtf8(), QCryptographicHash::Md5).toHex());
}
