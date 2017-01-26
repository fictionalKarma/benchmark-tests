#ifndef TABLE_H
#define TABLE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include<QMessageBox>
#include <QString>
// Trebuie schimbat Path-ul la folderul unde se afla proiectul.
#define DATABASE_NAME "procese.db"

class Table
{
public:

    int createTable(QString tableName, QString ColumnValues);
    void insertQuery(QString tableName, QString data, std::map<QString,float> floatValues, bool value);
    void insertQuery(QString tableName,QString data,std::map<QString,float> floatValues, std::map<QString,bool> boolValues);
    void insertQuery(std::map<QString,float> floatValues,QString data,QString tipBuget);
    int deleteQuery(QString tableName, int index);
    int updateQuery(QString tableName, QString newRowValues, int index);
    int tableSize(QString tableName);
    void tableSizeToFile(QString tableName);
    void decode(QString c);
    void connect();
    void readQuery(QString tableName, int dso);
    QString readQuery(QString tableName, QString Id);
    Table();


private:
    static QSqlDatabase db;
    int numOfRows;


};

#endif // TABLE_H
