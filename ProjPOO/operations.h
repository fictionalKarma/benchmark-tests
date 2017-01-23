#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QString>
#include <QCryptographicHash>
#include "error.hpp"
#include <QDateTime>

class Operations
{
public:
   static bool isValidUser(QString name);
   static bool isValidPassword(QString pwd);
   static bool isValidEmail(QString mail);
   static QString encode(QString arg1);
   static QString getTime(QString format);
};

#endif // OPERATIONS_H
