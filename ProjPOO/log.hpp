#ifndef LOG_H
#define LOG_H

/**
    log.cpp
    Purpose :	a class whose purpose is to design , maintain and
                display a log of activities from a specified date
*/
#include <QString>
#include <QVector>
#include "error.hpp"
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

    Error printCurrentLogs();
    Error addLog(QString str);
    Error deleteLog(int index);
    Error deleteLog(QString checker);
    Error updateLog(int index, QString str);
    QString getTime();
};
#endif
