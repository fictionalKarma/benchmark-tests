#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <stack>
#include "error.hpp"

class Event {
	
private:
 	std::string event;
	int numbero;
public:
	Event();
	~Event();

	Error createEvent();
	Error updateEvent();
	Error stopEvent();
	Error holdEvent();
	Error basicEventInformation();
	Event& operator= (Event& other){

		return *this;
	}


};
#endif