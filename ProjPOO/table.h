#ifndef TABLE_H
#define TABLE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
// Trebuie schimbat Path-ul la folderul unde se afla proiectul.
#define DATABASE_NAME "D:\\POOProj\\formfeed\\DataBase.db"

class Table
{
public:

    int createTable(QString tableName, QString ColumnValues);

    int insertQuery(QString tableName, QString rowValues);
    int deleteQuery(QString tableName, int index);
    int updateQuery(QString tableName, QString newRowValues, int index);
    int tableSize(QString tableName);
    void tableSizeToFile(QString tableName);
    void decode(QString c);

    QString readQuery(QString tableName, int index);
    QString readQuery(QString tableName, QString Id);


private:
    static QSqlDatabase db;
    int numOfRows;

};

#endif // TABLE_H
