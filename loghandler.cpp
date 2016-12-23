#include "loghandler.hpp"

typedef std::chrono::system_clock Clock;

std::string LogHandler::getTime(){
		
	auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    std::stringstream buffer;
    buffer << 1900 + parts->tm_year  << "-";
    buffer << 1    + parts->tm_mon   << "-";
    buffer <<        parts->tm_mday ;
	
	return	buffer.str();	
}
bool LogHandler::exists(std::string date){
	//return true;
	//std::string copy = PATH_TO_LOGS;
	return logHandler.check(PATH_TO_LOGS,date);
}
Error LogHandler::updateLog(std::string date, Log log ){
	std::vector <std::string> logs = log.getLogs();
	if(!this->exists(date))
		logHandler.createFile(PATH_TO_LOGS,date);
	for(std::vector<std::string>::iterator it = logs.begin(); it != logs.end(); it++)
		logHandler.writeToFile(PATH_TO_LOGS,date,*it);
	return Error::BETTER;
}