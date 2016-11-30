#ifndef LOGHANDLER_H
#define LOGHANDLER_H

/**
	loghandler.cpp
	Purpose: simple static class to implement a log retriever and updater

	@author Pirvu Mircea ,<insert contributor name here>

*/
#include <string>
#include <ctime>
#include "log.hpp"
#include "error.hpp"
	class LogHandler {
public:
	LogHandler(){} // forces the class to be uninitialized
	/**
		Retrieves a log from the logs file of the system

	@param string pointing towards the date of the log we want to retrieve
	@return returns the container of the log file
	*/
	static Log getLog(std::string date);
	
	/**
		Updates the log file 

	@param the date of the log file we wish to modify
	@param the logs in question 
	@param stream pointing towards the file we need to modify
	@return return whether the log update has been succesful or not 
	*/
	static Error updateLog(std::string date, Log log , std::ofstream& out);
};
#endif