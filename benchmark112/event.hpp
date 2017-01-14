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
    Event(std::string event);
    ~Event();

    void updateEvent(std::string updateString);
    void stopEvent();
    std::string toString();
    void basicEventInformation();
    Event& operator= (Event& other){

        return other;
    }
    friend std::istream& operator>> (std::istream &in , Event &e);

};
#endif
