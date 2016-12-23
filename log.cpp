#include "log.hpp"

Error Log::printBasicLog(){
	std::cout <<"Read file abracadabra at 8.30, close at 8.32 \n";

	return Error::BETTER;
}
Error Log::printCurrentLogs(){
	for(std::vector<std::string>::iterator it = logs.begin(); it != logs.end(); it++)
		std::cout << *it << '\n';
	return Error::BETTER;
}
Error Log::addLog(Event e){
	logs.push_back(e.toString());
	return Error::BETTER;
}