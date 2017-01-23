#include "administrator.hpp"

Administrator::Administrator() : User() {
    level = 2;

}
Administrator::Administrator(QString q) : User(q) {
    level = 2;
}
Administrator::Administrator(QString q, QString q1) : User(q,q1){
    level = 2;
}
Administrator::Administrator(QString q ,Firma* f , QString q1 ) : User(q,f,q1){
    level = 2;
}

