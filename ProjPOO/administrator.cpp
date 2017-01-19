#include "administrator.hpp"

Administrator::Administrator() : User() {
    level = 2;
    firm = new Firma;
}
Administrator::Administrator(QString q) : User(q) {
    level = 2;
    firm = new Firma(this);
}
Administrator::Administrator(QString q, QString q1) : User(q,q1){
    level = 2;
    firm = new Firma
}

