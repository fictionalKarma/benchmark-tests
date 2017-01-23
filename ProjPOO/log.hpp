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
   QString day , month , year ;
   QString today ;
public:
    static QVector<Log *> _all_logs;
    Log(){
        _all_logs.push_back(this);
    }

    ~Log(){}
    /**
        Prints a list of the day's logs to an output server

        @return Returns an error sticker pointing to whether the logs have been
                succesfully printed or not
    */

    QVector<QString> getLogs() {
        return logs;
    }

    Error printCurrentLogs();
    /**
        Adds a log to the current list , based on an event

        @return Returns whether the Event information has been added or not
    */
    Error addLog(QString str);
    /**
        Mostly useless method,since we don't usually want to destroy evidence *giggles*

        @param	Position of
        @return Returns whether the log at position has been succesfully deleted
    */
    Error deleteLog(int index);
    /**
        another Mostly useless method,since we don't usually want to destroy evidence *giggles*

        @param the string checker we want to match all our logs with
        @return Returns whether all logs with the checker string have been
                succesfully destroyed (no coming backs) or not
    */
    Error deleteLog(QString checker);
    /**
        Updates the log at index using information from given event

        @param Position of
        @param Event which shall be used to update
    */
    Error updateLog(int index, QString str);
    QString getTime();
};
#endif
