#include "formfeed.h"
#include <QApplication>
#include "table.h"
#include "buget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    formfeed w;
    w.show();


    return a.exec();
}
