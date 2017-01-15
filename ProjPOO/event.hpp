#ifndef EVENT_H
#define EVENT_H

#include <QDataStream>
#include <QDebug>
#include <QString>
#include "error.hpp"

class Event {

private:
    QString event;
    int numbero;
public:
    Event();
    Event(QString event);

    void updateEvent(QString updateString);
    void stopEvent();
    QString toString();
    void basicEventInformation();
    Event& operator= (Event& other){
        return other;
    }

    friend QTextStream& operator>> (QTextStream &in , Event &e);
};
#endif
