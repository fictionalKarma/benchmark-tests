#ifndef LOG_H
#define LOG_H

/**
	log.cpp
	Purpose :	a class whose purpose is to design , maintain and 
				display a log of activities from a specified date 
*/
#include <string>
#include <iostream>
#include <vector>
#include "event.hpp"
#include "error.hpp"


class Log {
private:
	std::vector<std::string> logs; // today's logs ,each day
									// a new log file should be created
	std::string day , month , year ;
	std::string today ;
public:
	Log(){}
	~Log(){}
	/**
		Prints a list of the day's logs to an output server

		@return Returns an error sticker pointing to whether the logs have been 
				succesfully printed or not
	*/
	std::vector < std :: string > getLogs(){
		return logs;
	}
	Error printCurrentLogs();
	/**
		Adds a log to the current list , based on an event

		@return Returns whether the Event information has been added or not 
	*/
	Error addLog(Event e);
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
	Error deleteLog(std::string checker);
	/**
		Updates the log at index using information from given event

		@param Position of
		@param Event which shall be used to update
	*/
	Error updateLog(int index,Event e);
	Error printBasicLog();

};
#endif