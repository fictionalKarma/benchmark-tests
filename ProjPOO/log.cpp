#include "log.hpp"

QString Log::getTime(){
    return QDateTime::currentDateTime().time().toString("[hh:mm:ss]   ");
}

QVector<QString> Log::_all_logs;

Log::Log() {}

bool Log::printCurrentLogs(){
    QString str;
    for(QString it : logs){
        str = QString::fromUtf8(QByteArray(it.toUtf8()));
        qDebug() << str;
    }
    return true;
}

bool Log::addLog(QString str) {
    logs.push_back(this->getTime() + str);
    _all_logs.push_back(str);
    return true;
}
