#include "startingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartingWindow w;
    w.show();

    return a.exec();
}
