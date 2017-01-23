#include "administrator.hpp"

Administrator::Administrator() : User() {
    level = UserLevel::Administrator;

}
Administrator::Administrator(QString q) : User(q) {
    level = UserLevel::Administrator;
}
Administrator::Administrator(QString q, QString q1) : User(q,q1){
    level = UserLevel::Administrator;
}
Administrator::Administrator(QString q ,Firma* f , QString q1 ) : User(q,f,q1){
    level = UserLevel::Administrator;
}

