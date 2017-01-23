#ifndef FIRMA_H
#define FIRMA_H


#include "tree.hpp"

class Firma {
public:
	Firma();
    Firma(Tree* t);
    Firma(User& u);
    Firma(QString q);
    Tree* getTree();
    void setBoss( User* u);
private:
    Tree* T ;
};



#endif
