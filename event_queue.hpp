#ifndef EVENT_STACK_H
#define EVENT_STACK_H

#include <string>
#include <queue>
#include "event.hpp"
#include "error.hpp"
class EventQueue{
private:	
	std::queue<Event> events;
	int size ;
public:
	EventQueue(){
		size = 0;
	}
	EventQueue(Event firstEvent){
		size = 1;
		events.push(firstEvent);
	}
	/**
		Clears the event on end of program. 

	*/
	~EventQueue();
	/**
		Adds an event to the event stack.

		@param event to be put in an event holder for usage .
		@return returns whether it has been succesfully placed in the event holder or not .
	*/
	Error addEvent(Event e);
	/**
		Removes an event from the event queue.

		@return returns the event in question
	*/
	Event removeEvent();
	/**
		Updates an event at given position

		@param position of the event to be updated
		@return returns whether the event has been succesfully updated or not 
	*/
	Error updateEvent(int index);
	/**
		Updates the first event to be executed

		@return returns wheter the event ha been succesfully updated or not
	*/
	Error updateEvent();
	/**
		Holds the event to be executed

		@return returs whether the event has been put on hold or not
	*/
	Error holdEvent();
};

#endif