#ifndef FIRMA_H
#define FIRMA_H


#include "tree.hpp"
#include "objective.hpp"

class Firma {
public:
    Firma();
    Firma(Tree* t);
    Firma(User& u);
    Firma(QString q);
    Tree* getTree();
    std::vector<Objective*> getObjectives(){
        return objectives;
    }
    Objective getBigObjective(){
        return *bigObjective;
    }
    void setObjective(Objective* o);
    void setBoss( User* u);
    double passedObjectives();
    void printObjectives();
    void printObjectivesPassed();
    void updateObjectives();
    void readObjectivesFromDatabase();

private:
    Tree* T ;
    std::vector<Objective*> objectives;
    Objective* bigObjective ;
};



#endif
