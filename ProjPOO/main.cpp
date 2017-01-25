#include "startingwindow.h"
#include <QApplication>
#include "includes.hpp"
#include<procesop.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    procesop w;//StartingWindow w;
    w.show();
    return a.exec();
}
