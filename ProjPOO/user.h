#ifndef USER_H
#define USER_H

#include <QString>
#include <QObject>
#include "userlevels.h"

class Firma;
class Tree;
struct Node ;
class User : public QObject {
    Q_OBJECT

public:
    User(QString);
    User(QString,QString);
    User(QString ,Firma* ,QString);
    User();
    virtual void dummyFunction(){}
    QString getUserName(){
        return username;
    }
    QString getBoss(){
        return boss;
    }
    void setUserName(QString q){
        username = q;
    }
    void setBoss(QString q){
        boss = q;
    }
    UserLevel getLevel(){
        return level;
    }
    Firma* getFirma(){
        return firma;
    }
    void setFirma(Firma *f){
        firma = f;
    }

    void setTree(Tree *k){
        copy = k;
    }
    Tree* getTree(){
        return copy;
    }

    void operator= (User &other){
        this->setBoss(other.getBoss());
        this->setUserName(other.getUserName());
    }
    bool operator==(User &other){
        int i ;
        i =  (boss == other.getBoss()) + (username == other.getUserName());
        if( i == 2)
            return true;
        return false;
    }

signals:
    void onLogin();

protected:
    QString username , boss;
    Firma* firma;
    Tree* copy;
    UserLevel level;
};

#endif // USER_H
