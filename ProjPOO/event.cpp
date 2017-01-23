#include "event.hpp"

void Event::basicEventInformation(){
    qDebug() << "Printing an event !\n";
}

Event::Event() {}

Event::Event(QString even){
    this->event = even;
}

QString Event::toString(){
    return this->event;
}

void Event::updateEvent(QString updateString){
    this->event = updateString;
}

QTextStream& operator>> (QTextStream &in , Event &e){
    e.event = in.readLine();
    qDebug() << "error";
    return in;
}
