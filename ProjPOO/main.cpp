#include "startingwindow.h"
#include <QApplication>
#include "includes.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartingWindow w;
    w.show();
    return a.exec();
}
