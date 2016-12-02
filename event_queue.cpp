#include "event_queue.hpp"

Error EventQueue::addEvent(Event e){
	events.push(e);

	return Error::BETTER;
}
EventQueue::~EventQueue(){}
