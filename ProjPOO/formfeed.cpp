#include "formfeed.hpp"

FormFeed::FormFeed(int number) {
    number = 0;     // got a warning for unreferenced parameter, so I did this
}

void FormFeed::printSmth(){
    qDebug() << "SMTH\n";
}
