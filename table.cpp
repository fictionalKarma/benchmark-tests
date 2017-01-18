#include "table.h"
#include <QDebug>

QSqlDatabase Table::db;
int Table::numberOfRows;

int Table::createTable(QString tbName, QString columnValues) {

    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;

        QString sql = "CREATE TABLE " +  tbName + " (CRT INT, " + columnValues + ");"; //Se formeaza comanda Sqlite
        query.exec(sql);
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);

    return 0;
}
int Table::insertQuery(QString tableName, QString rowValues) {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;
        QString sql = "INSERT INTO " + tableName + " VALUES(" + QVariant(numberOfRows).toString() + "," + rowValues + ");";
        query.exec(sql);
        numberOfRows++;
        qDebug()<<sql;
    }

    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return numberOfRows;
}
int Table::deleteQuery(QString tableName, QString rowValues){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;
        QStringRef id(&rowValues, 1, 13);
        QString sql = "DELETE FROM " + tableName + " WHERE CNP = " + id.toString() + ";";
        query.exec(sql);
        numberOfRows--;
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return 0;
}
int Table::updateQuery(Table table, QString tableName, QString newRowValues){


    table.deleteQuery(tableName, newRowValues);
    table.insertQuery(tableName, newRowValues);
    return 0;
}

QString Table::readQuery(QString tableName, int index){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();

        QSqlQuery query;
        QString sql = "SELECT * FROM " + tableName + " WHERE CRT = " + QVariant(index + 1).toString() +" ;";
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
