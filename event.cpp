#include "event.hpp"

Error Event::basicEventInformation(){
	std::cout << "Printing an event !\n";

	return Error::BETTER;
}
Event::Event(){}
Event::~Event(){}