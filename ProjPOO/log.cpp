#include "log.hpp"
QString Log::getTime(){
    return QDateTime::currentDateTime().time().toString("[hh:mm:ss]   ");
}

Error Log::printCurrentLogs(){
    QString str;
    for(QString it : logs){
        str = QString::fromUtf8(QByteArray(it.toUtf8()));
        qDebug() << str;
    }
    return Error::OK;
}

Error Log::addLog(QString str) {
    logs.push_back(this->getTime() + str);
    return OK;
}
