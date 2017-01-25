#include "user.h"
#define DATABASE_NAME "users.db"
struct pers
{
    QString text[7];
    QString n[25];//da faq is n?

}decod;

User::User(QString name)
{
    level = UserLevel::User;
    this->username = name;
    QString tableName="PERSONAL";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    readFromDatabase(name);
    emit onLogin();
}
User::User(QString name, QString bosss){
    level = UserLevel::User;
    this->setUserName(name);
    this->setBoss(bosss);
    QString tableName="PERSONAL";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    emit onLogin();
}
User::User(){
    level = UserLevel::User;
    QString tableName="PERSONAL";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    emit onLogin();
}
User::User(QString name ,Firma* f1 ,QString boss){
    level = UserLevel::User;
    this->username = name;
    firma = f1 ;
    this->boss = boss;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();
    emit onLogin();
}
void User::decode(QString c)
{
    for(int i=0;i<7;i++)
        decod.text[i]="";
    for(int i=0;i<25;i++)
        decod.n[i]="";
    int i=0,k=1,l=0;
    while(c[i]!=',')
    {
        decod.text[0]+=c[i];
        i++;
    }
    i++;
    int size=c.size();
    for(;i<size;i++)
    {
        if(c[i]=='\'' )
        {
            while(c[i]!=','&&i<size)
            {
                decod.text[k]+=c[i];
                i++;
            }
            k++;
        }
        else
        {
            while(c[i]!=','&&i<size)
            {
                decod.n[l]+=c[i];
                i++;
            }
            l++;
        }
    }
}
void User::readFromDatabase(QString name)
{
    QSqlQuery query;
    query.exec("SELECT * FROM PERSONAL WHERE nume=\'"+name+"'\;");
    QStringList userData;
    if (query.next()) {
        int fieldNumber = query.record().count();
        int i = 0;      // pornim de la field 1, fiindca 0 este CRT
        while (i++ < fieldNumber+1) {     // i se incrementeaza dupa ce se compara cu fieldNumber
           userData.append(query.record().value(i).toString());
           qDebug() << userData[i] << " ";
        }
    }
/*
    if(decod.text[1].size()==name.size())
    {
        for(l=0;l<name.size();l++)
            if(decod.text[1][l]!=name[l])
                break;
        if(l==name.size())
        {
            //intrare=decod;
            ok=1;
            break;
        }
    }
            cnp=decod.text[0];
            email=decod.text[2];
            numeFirma=decod.text[3];
            sef=decod.text[4];
            salariu=decod.text[5].toInt();
            adresa=decod.text[6];
            moneda=decod.n[1].toInt();//lei sau euro la salariu
            dep=decod.n[2].toInt();//0 1 2 3 4 respectiv rutier,depozitare,maritim,aerian,feroviar
            compAerian=decod.n[3].toInt();
            compMaritm=decod.n[4].toInt();
            compRutier=decod.n[5].toInt();
            compFeroviar=decod.n[6].toInt();
            compInternat=decod.n[7].toInt();
            compDomestic=decod.n[8].toInt();
            depozitare=decod.n[9].toInt();
            comercial=decod.n[10].toInt();
            achizitii=decod.n[11].toInt();
            manageEchipa=decod.n[12].toInt();
            analiza=decod.n[13].toInt();
            prezentare=decod.n[14].toInt();
            decizii=decod.n[15].toInt();
            comunicare=decod.n[16].toInt();
            manageProiect=decod.n[17].toInt();
            manageTimp=decod.n[18].toInt();
            leanManage=decod.n[19].toInt();
            sixSigma=decod.n[20].toInt();
            tADR=decod.n[21].toInt();
            tIATA=decod.n[22].toInt();
            sisInfo=decod.n[23].toInt();
            standardLucru=decod.n[24].toInt();


    }
    if(ok==0)
        qDebug()<<"Nu s-a gasit";
        */

}

