#include "startingwindow.h"
#include <QApplication>
#include "includes.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartingWindow w;
    w.show();
    Event e;
    e.basicEventInformation();
    Event e1("HOW YOU DOIN >?!!");
    Event e2("D0l0r3sH@ze");
    Event e3("GOD FORBIDHEJE");
    Log l;
    l.addLog(e1);
    l.addLog(e2);
    l.addLog(e3);
    l.printBasicLog();
    EventQueue someEventQueue;
    someEventQueue.addEvent(e);
    LogHandler someLogHandler;
    l.printCurrentLogs();
    someLogHandler.updateLog(someLogHandler.getTime(), l);

    User u1("Georgica") , u2("Vasile","Georgica") , u3("Ionel","Georgica"), u4("GICA","Vasile");

    Node *b;
        b = new Node;
        b->user = u1;
        b->father = NULL;
    Node *c, *d , *eee;
        c = new Node ; d = new Node , eee= new Node;
        c->user = u2; d->user = u3; eee->user = u4;
    Tree f(b);
    //qDebug() << d->user.getUserName();
    f.add(c,"Georgica");
    f.add(d,"Georgica");
    f.add(eee,"Vasile");
    f.traverse();
    return a.exec();
}
