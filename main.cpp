#include <iostream>
#include "formfeed.hpp"
#include "event.hpp"

int main() {
	std::cout<<"Hello World !\n";
	FormFeed a = FormFeed(3);
	a.printSmth();
	
	Event e ;
	e.basicEventInformation();
	return 0;
}
