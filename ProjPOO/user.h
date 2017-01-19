#ifndef USER_H
#define USER_H

#include <QString>
#include <QObject>

class Firma;
class Tree;
class User : public QObject {
    Q_OBJECT

public:
    User(QString);
    User(QString,QString);
    User(QString ,Firma* ,QString);
    User();

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
    int getLevel(){
        return level;
    }
    Firma* getFirma(){
        return firma;
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

private:
    QString username , boss;
    Firma* firma;
protected:
    int level;
};

#endif // USER_H
