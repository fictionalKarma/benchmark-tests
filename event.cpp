#include "event.hpp"

Error Event::basicEventInformation(){
	std::cout << "Printing an event !\n";

	return Error::BETTER;
}
Event::Event(){}
Event::Event(std::string even){
	this->event = even;
}
Event::~Event(){}

std::string Event::toString(){

	return this->event;
}
Error Event::updateEvent(std::string updateString){
	this->event = updateString;

	return Error::BETTER;
}
std::istream& operator>> (std::istream &in , Event &e){
		std::getline(in,e.event);

		return in;
	}
