#include "startingwindow.h"
#include <QApplication>
#include "includes.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartingWindow w;
    w.show();
    Event e ;
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
        std::cout<<someLogHandler.getTime()<<"AICIIIIII\n";
        //QMessageBox::information(&w,"title",);
        l.printCurrentLogs();
        someLogHandler.updateLog(someLogHandler.getTime(),l);
    return a.exec();
}
