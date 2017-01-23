#include "event_queue.hpp"

void EventQueue::addEvent(Event e){
    events.enqueue(e);
}

