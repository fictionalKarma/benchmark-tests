#include <iostream>
#include "includes.hpp"

int main() {
	std::cout<<"Hello World !\n";
	FormFeed a = FormFeed(3);
	a.printSmth();
	
	Event e ;
	e.basicEventInformation();
	Event e1("HOW YOU DOIN >?!!");
	Event e2("D0l0r3sH@ze");
	Event e3("GOD FORBIDHEJE");
	Log l;
	l.addLog(e1);
	l.addLog(e2);
	l.addLog(e3);
	l.printBasicLog();
	EventQueue someEventQueue;
	someEventQueue.addEvent(e);
	LogHandler someLogHandler;
	std::cout<<someLogHandler.getTime()<<"AICIIIIII\n";
	l.printCurrentLogs();
	someLogHandler.updateLog(someLogHandler.getTime(),l);
	/*FileOperations f;
	f.createFile(someLogHandler.PATH_TO_LOGS,"someName");
	f.removeFile(someLogHandler.PATH_TO_LOGS,"someName");
	f.writeToFile(someLogHandler.PATH_TO_LOGS,"someName","a great new string");
	f.writeToFile(someLogHandler.PATH_TO_LOGS,"someName","another great new string");
	if( f.check(someLogHandler.PATH_TO_LOGS,"someName"))
		std::cout <<"someName exists\n";
	else
		std::cout <<"someName doesn't exists\n";
	std::cin>>e;
	std::cout<<e.toString()<<"\n";
	std::cout<<someLogHandler.getTime();
	std::cout<<someLogHandler.exists("someName")<<"\n";
	std::cout<<someLogHandler.exists("1996-12-11")<<"\n";*/
	return 0;
}
