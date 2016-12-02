#include <iostream>
#include "includes.hpp"

int main() {
	std::cout<<"Hello World !\n";
	FormFeed a = FormFeed(3);
	a.printSmth();
	
	Event e ;
	e.basicEventInformation();
	Log l;
	l.printBasicLog();
	EventQueue someEventQueue;
	someEventQueue.addEvent(e);
	LogHandler someLogHandler;
	return 0;
}
