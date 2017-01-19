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
private:
    Tree* T ;
};



#endif
