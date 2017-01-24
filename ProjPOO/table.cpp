#include "table.h"
#include <QDebug>
#include<QFile>
#include<QTextStream>
QSqlDatabase Table::db;
int numOfRows;
struct
{
    QString text[19];
    QString n[25];
}decod;

int Table::createTable(QString tbName, QString columnValues) {

    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;

        QString sql = "CREATE TABLE " +  tbName + " (CRT INT PRIMARY KEY, " + columnValues + ");"; //Se formeaza comanda Sqlite
        query.exec(sql);
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return 0;
}
int Table::tableSize(QString tableName){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
    QSqlQuery query;
    QString sql = "SELECT * FROM " +tableName +";";
    int count=0;
    query.exec(sql);
    while(query.next())
            count++;
    numOfRows=count;
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return numOfRows;
}

int Table::insertQuery(QString tableName, QString rowValues) {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;
        //numOfRows=tableSize(tableName);
        QString sql = "INSERT INTO " + tableName + " VALUES(" + QVariant(numOfRows).toString() + "," + rowValues + ");";
        query.exec(sql);
        numOfRows++;
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return 0;
}
int Table::deleteQuery(QString tableName, int index){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QString sql = "DELETE FROM " + tableName +" WHERE CRT= "+QVariant(index).toString() +";";
        QSqlQuery query;
        query.exec(sql);
        //numOfRows=tableSize(tableName);
        numOfRows--;
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return 0;
}
void Table::decode(QString c)
{
    for(int i=0;i<19;i++)
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
        if(c[i]=='\'')
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

int Table::updateQuery(QString tableName, QString newRowValues, int index){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        char b[6]="BUGET",p[9]="PERSONAL",r[7]="RUTIER",f[9]="FEROVIAR",d[11]="DEPOZITARE",m[8]="MARITIM",a[7]="AERIAN";
        int caz=0,i;
        for(i=0;i<5&&caz==0;i++)
            if(tableName[i]!=b[i])
                break;
        if(i==5)
            caz=1;
        for(i=0;i<8&&caz==0;i++)
            if(tableName[i]!=p[i])
                break;
        if(i==8)
            caz=2;
        for(i=0;i<6&&caz==0;i++)
            if(tableName[i]!=r[i])
                break;
        if(i==6)
            caz=3;
        for(i=0;i<8&&caz==0;i++)
            if(tableName[i]!=f[i])
                break;
        if(i==8)
            caz=4;
        for(i=0;i<10&&caz==0;i++)
            if(tableName[i]!=d[i])
                break;
        if(i==10)
            caz=5;
        for(i=0;i<7&&caz==0;i++)
            if(tableName[i]!=m[i])
                break;
        if(i==7)
            caz=6;
        for(i=0;i<6&&caz==0;i++)
            if(tableName[i]!=a[i])
                break;
        if(i==6)
            caz=7;
        if(caz==1)
        {
            decode(newRowValues);
            QString sql = "UPDATE "+tableName+" SET DATA = "+decod.text[0]+", BUGET = "+decod.n[0]+", CIFRA_AFACERI = "+decod.text[1]+", COST_CUMPARARE = "+decod.text[2]+", PERSONAL = "+decod.text[3]+", TEHNOLOGIE = "+decod.text[4]+", INFRASTRUCTURA = "+decod.text[5]+", INVESTITII = "+decod.text[6]+", COST_RUTIER = "+decod.text[7]+", COST_DEPOZITARE = "+decod.text[8]+", COST_MARITIM = "+decod.text[9]+", COST_AERIAN = "+decod.text[10]+", COST_FEROVIAR = "+decod.text[11]+" WHERE CRT = "+QVariant(index).toString()+";";
            qDebug()<<sql;
            QSqlQuery query;
            query.exec(sql);
        }
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return 0;
}

QString Table::readQuery(QString tableName, int index){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();

        QSqlQuery query;
        QString sql = "SELECT * FROM " + tableName + " WHERE CRT = " + QVariant(index).toString() +" ;";
        query.exec(sql);
        qDebug()<<sql;
        QString tmp ="";
        int i=1;

        int n = query.record().count();
        while(query.next() && i<n-1){
        for( i=1; i<n; i++){
            if(query.record().value(i).type() == query.record().value(1).type()){
                if(i < n-1){
                    tmp = tmp + "'" + query.record().value(i).toString() +"',";
                }
                else{
                    tmp = tmp + "'" + query.record().value(i).toString() +"'";
                }            }
            else{
                if(i < n-1){
                    tmp = tmp + query.record().value(i).toString() +",";
                }
                else{
                    tmp = tmp + query.record().value(i).toString();
                }

            }

        }
        }
        qDebug()<<tmp;
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);

    return tmp;
}
    }
