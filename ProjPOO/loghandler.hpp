#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QString>
#include <QDir>
#include "log.hpp"
#include "fileOperations.hpp"

class LogHandler {
public:
    QString PATH_TO_LOGS;

    LogHandler(){
        PATH_TO_LOGS=QDir::currentPath() + "/logs";
        QDir dir = QDir(PATH_TO_LOGS);
        if (!dir.exists()) {
            dir.mkdir(PATH_TO_LOGS);
        }
    }
	/**
		Retrieves a log from the logs file of the system

	@param string pointing towards the date of the log we want to retrieve
	@return returns the container of the log file
	*/
        Log getLog(QString date);

	/**
	Returns the path to logs file
	*/
        QString getPath() { return PATH_TO_LOGS ;}
	/**
		Updates the log file 

	@param the date of the log file we wish to modify
	@param the logs in question 
	@param stream pointing towards the file we need to modify
	@return return whether the log update has been succesful or not 
	*/
        bool updateLog(QString date, QString log );
	/**
		Checks wheter a log exists or not

	@param the date in which we wish to know whether there exists any logs
	@return returns @true if log date exists , else returns @false
	*/
        bool exists(QString date);
	/**
		Returns the local time 

		@return returns a string containing the date in the format : year-month-day
	*/
        QString getTime();
        QString getFullTime();
};
#endif
