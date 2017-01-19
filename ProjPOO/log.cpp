#include "log.hpp"
QString Log::getTime(){
    return QDateTime::currentDateTime().time().toString("[hh:mm:ss]   ");
}

Error Log::printBasicLog(){
    qDebug() <<"Read file abracadabra at 8.30, close at 8.32 \n";
    return Error::OK;
}

Error Log::printCurrentLogs(){
    QString str;
    for(QString it : logs){
        str = QString::fromUtf8(QByteArray(it.toUtf8()));
    }
    return Error::OK;
}

Error Log::addLog(Event e){
    logs.push_back(this->getTime() + e.toString());
    return Error::OK;
}