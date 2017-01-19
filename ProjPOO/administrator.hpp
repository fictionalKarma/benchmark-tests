#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "firma.hpp"
class Administrator : public User{
public:
    Administrator(QString);
    Administrator(QString, QString);
    Administrator();
    Firma& getFirma();
   	void addUser(User &u);
private:
    Firma& firm ;
};




#endif
