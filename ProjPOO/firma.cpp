#include "firma.hpp"

Firma::Firma(){
     T = new Tree();
}
Firma::Firma(Tree* t){
    T = t;
}
Firma::Firma(User& u){
    Node *n = new Node;
    n->user = u ;
    T = new Tree(n);
}
Firma::Firma(QString q){
    Node *n = new Node;
    User u(q);
    n->user = u;
    T = new Tree(n);
}
Tree* Firma::getTree(){
    return T;
}
