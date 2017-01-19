#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "firma.hpp"
class Administrator : public User{
public:
    Administrator(QString);
    Administrator(QString, QString);
    Administrator();
    Administrator(QString , Firma* , QString);

   	void addUser(User &u);
    void addUser(QString , QString);
private:
};



#endif
