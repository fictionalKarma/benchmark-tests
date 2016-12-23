#ifndef LOGHANDLER_H
#define LOGHANDLER_H


/**
	loghandler.cpp
	Purpose: simple static class to implement a log retriever and updater

	@author Pirvu Mircea ,<insert contributor name here>

*/

#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include "log.hpp"
#include "error.hpp"
#include "fileOperations.hpp"
	class LogHandler {
private:
FileOperations logHandler;
public:
std::string PATH_TO_LOGS;

LogHandler(){
	PATH_TO_LOGS="/home/mirceas/Projects/Factori Benchmark/school-project/logs";
} // forces the class to be uninitialized
	/**
		Retrieves a log from the logs file of the system

	@param string pointing towards the date of the log we want to retrieve
	@return returns the container of the log file
	*/
	Log getLog(std::string date);
	/**
	Returns the private FileOperations loghandler
	*/
	FileOperations getLogHandler(){ return logHandler; }
	/**
	Returns the path to logs file
	*/
	std::string getPath() { return PATH_TO_LOGS ;}
	/**
		Updates the log file 

	@param the date of the log file we wish to modify
	@param the logs in question 
	@param stream pointing towards the file we need to modify
	@return return whether the log update has been succesful or not 
	*/
	Error updateLog(std::string date, Log log );
	/**
		Checks wheter a log exists or not

	@param the date in which we wish to know whether there exists any logs
	@return returns @true if log date exists , else returns @false
	*/
	bool exists(std::string date);
	/**
		Returns the local time 

		@return returns a string containing the date in the format : year-month-day
	*/
	std::string getTime();
};
#endif