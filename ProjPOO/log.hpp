#ifndef LOG_H
#define LOG_H

/**
    log.cpp
    Purpose :	a class whose purpose is to design , maintain and
                display a log of activities from a specified date
*/
#include <QString>
#include <QVector>
#include <QDateTime>
#include <QDebug>
#include <logstrings.h>

class Log {
private:
   QVector<QString> logs; // today's logs ,each day
                          // a new log file should be created
public:
    static QVector<QString> _all_logs;
    Log();

    ~Log(){}

    QVector<QString> getLogs() {
        return logs;
    }

    bool printCurrentLogs();
    bool addLog(QString str);
    bool deleteLog(int index);
    bool deleteLog(QString checker);
    bool updateLog(int index, QString str);
    QString getTime();
};
#endif
