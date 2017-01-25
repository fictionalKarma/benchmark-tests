#include "firma.hpp"

Firma::Firma(){
     T = new Tree();
     bigObjective = new Objective("OBIECTIVE ATINSE ",passedObjectives(),objectives.size());
     readObjectivesFromDatabase();
}
Firma::Firma(Tree* t){
    T = t;
    bigObjective = new Objective("OBIECTIVE ATINSE ",passedObjectives(),objectives.size());
    readObjectivesFromDatabase();
}
Firma::Firma(User& u){
    Node *n = new Node;
    n->user = u ;
    T = new Tree(n);
    bigObjective = new Objective("OBIECTIVE ATINSE ",passedObjectives(),objectives.size());
    readObjectivesFromDatabase();
}
Firma::Firma(QString q){
    Node *n = new Node;
    User u(q);
    n->user = u;
    T = new Tree(n);
    bigObjective = new Objective("OBIECTIVE ATINSE ",passedObjectives(),objectives.size());
    readObjectivesFromDatabase();
}
Tree* Firma::getTree(){
    return T;
}
void Firma::setBoss( User* u){
    Node *n = new Node ;
    n->father = NULL;
    n->user = *u;
    T->setBoss(n);
}
double Firma::passedObjectives(){
    double sum = 0.0;
    for ( Objective *o : objectives)
        if(o->pass())
            sum+=1.0;
    return sum;
}
void Firma::setObjective(Objective* o){

    objectives.push_back(o);
    int n = objectives.size();
    bigObjective->setTarget(n);
    bigObjective->addToValue(o->pass());
}
void Firma::updateObjectives(){
    int count = 0;
    for(Objective* o : objectives){
        if(o->pass())
            count++;
    }
    bigObjective->setValue(count);
}

void Firma::printObjectives(){
    qDebug() << bigObjective->toString();
    for(Objective *o : objectives)
       qDebug() << o->toString();
}
void Firma::printObjectivesPassed(){
    qDebug() << bigObjective->passed();
    for(Objective *o : objectives)
       qDebug() << o->passed();
}

void Firma::readObjectivesFromDatabase(){

}
