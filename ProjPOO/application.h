#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QVector>
#include "loghandler.hpp"
#include "startingwindow.h"

QVector<Log *> Log::_all_logs;

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]) : QApplication(argc, argv) {

    }

    ~Application() {
        LogHandler lh;
        for (Log *i : Log::_all_logs) {
            lh.updateLog(lh.getTime(), i);
        }
    }
};

#endif // APPLICATION_H
