#ifndef TABLE_H
#define TABLE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QsqlRecord>
#include <Qsqlquery>
#include <QString>
// Trebuie schimbat Path-ul la folderul unde se afla proiectul.
#define DATABASE_NAME "C:\\Users\\Luiza\\Desktop\\QDbConnection\\DataBase.db"

class Table
{
public:
    Table(){numberOfRows = 0;}

    static int createTable(QString tableName, QString ColumnValues);

    static int insertQuery(QString tableName, QString rowValues);
    static int deleteQuery(QString tableName, QString rowValues);
    static int updateQuery(Table table, QString tableName, QString newRowValues);
    int tableSize(QString tableName){return numberOfRows;}

    QString readQuery(QString tableName, int index);
    QString readQuery(QString tableName, QString Id);



private:
    static QSqlDatabase db;
    static int numberOfRows;
};

#endif // TABLE_H
