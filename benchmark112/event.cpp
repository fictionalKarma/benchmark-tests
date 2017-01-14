#include "event.hpp"

void Event::basicEventInformation(){
    std::cout << "Printing an event !\n";
}
Event::Event(){}
Event::Event(std::string even){
    this->event = even;
}
Event::~Event(){}

std::string Event::toString(){

    return this->event;
}
void Event::updateEvent(std::string updateString){
    this->event = updateString;

}
std::istream& operator>> (std::istream &in , Event &e){
        std::getline(in,e.event);

        return in;
    }
