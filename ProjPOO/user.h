#ifndef USER_H
#define USER_H

#include <QString>
#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
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
    void readFromDatabase(QString name);
    void decode(QString);
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
        firma = other.getFirma();
        copy = other.copy ;
        salariu=other.getSalariu();
        moneda=other.getMoneda();
        cnp=other.getCnp();
        email=other.getEmail();
        numeFirma=other.getNumeFirma();
        adresa=other.getAddress();
        dep=other.getDepartment();
        compAerian=other.getCompAerian();
        compMaritim=other.getCompMaritim();
        compRutier=other.getCompRutier();
        compFeroviar=other.getCompFeroviar();
        compInternat=other.getCompInternational();
        compDomestic=other.getCompDomestic();
        depozitare=other.getDepozitare();
        comercial=other.getComercial();
        achizitii=other.getAchizitii();
        manageEchipa=other.getManageEchipa();
        analiza=other.getAnaliza();
        decizii=other.getDecizii();
        prezentare=other.getPrezentare();
        comunicare=other.getComunicare();
        manageProiect=other.getManageProiect();
        manageTimp=other.getManageTimp();
        leanManage=other.getLeanManage();
        sixSigma=other.getSixSigma();
        tADR=other.getTADR();
        tIATA=other.getTIATA();
        sisInfo=other.getSisInfo();
        standardLucru=other.getStandardLucru();

    }
    bool operator==(User &other){
        int i ;
        i =  (boss == other.getBoss()) + (username == other.getUserName());
        if( i == 2)
            return true;
        return false;
    }
    QString getEmail(){
        return this->email;
    }
    QString getCnp(){
        return cnp;
    }
    QString getNumeFirma(){
        return numeFirma;
    }
    QString getSef(){
        return sef;
    }
    QString getAddress(){
        return adresa;
    }
    int getSalariu(){
        return salariu;
    }
    int getMoneda(){
        return moneda;
    }
    int getDepartment(){
        return dep;
    }
    int getCompAerian(){
        return compAerian;
    }
    int getCompMaritim(){
        return compMaritim;
    }
    int getCompFeroviar(){
        return compFeroviar;
    }
    int getCompInternational(){
        return compInternat;
    }
    int getCompDomestic(){
        return compDomestic;
    }
    int getDepozitare(){
        return depozitare;
    }
    int getComercial(){
        return comercial;
    }
    int getAchizitii(){
        return achizitii;
    }
    int getManageEchipa(){
        return manageEchipa;
    }
    int getAnaliza(){
        return analiza;
    }
    int getDecizii(){
        return decizii;
    }
    int getPrezentare(){
        return prezentare;
    }
    int getComunicare(){
        return comunicare;
    }
    int getCompRutier()
    {
        return compRutier;
    }

    int getManageProiect(){
        return manageProiect;
    }
    int getManageTimp(){
        return manageTimp;
    }
    int getLeanManage(){
        return leanManage;
    }
    int getSixSigma(){
        return sixSigma;
    }
    int getTADR(){
        return tADR;
    }
    int getTIATA(){
        return tIATA;
    }

    int getSisInfo(){
        return sisInfo;
    }
    int getStandardLucru(){
        return standardLucru;
    }

signals:
    void onLogin();

protected:
    QSqlDatabase db;
    QString username , boss ;
    QString cnp,email,numeFirma,sef , adresa;
    Firma* firma;
    Tree* copy;
    int salariu ;
    int moneda;
    int dep;
    UserLevel level;
    int compAerian;
    int compMaritim;
    int compRutier;
    int compFeroviar;
    int compInternat;
    int compDomestic;
    int depozitare;
    int comercial;
    int achizitii;
    int manageEchipa;
    int analiza;
    int decizii;
    int prezentare;
    int comunicare;
    int manageProiect;
    int manageTimp;
    int leanManage;
    int sixSigma;
    int tADR;
    int tIATA;
    int sisInfo;
    int standardLucru;
};

#endif // USER_H
