#include "loghandler.hpp"

QString LogHandler::getTime(){
    return QDateTime::currentDateTime().toString("ddd, d-MMMM-yyyy");
}

QString LogHandler::getFullTime() {
    return QDateTime::currentDateTime().toString("-dddd, d-MMMM-yyyy, hh:mm:ss-");
}

bool LogHandler::exists(QString date) {
    return FileOperations::check(PATH_TO_LOGS, date);
}

Error LogHandler::updateLog(QString date, Log *log ){
    QVector<QString> logs = log->getLogs();
    date = date + ".txt";

    if(!QFile::exists(PATH_TO_LOGS + "/" + date)) {
        FileOperations::createFile(PATH_TO_LOGS, date);
        FileOperations::writeToFile(PATH_TO_LOGS, date, "Logs started at:\n------------------------\n"
                                                                            + this->getFullTime()
                                                                      + "\n------------------------\n");
    }

    for(QString it : logs) {
        FileOperations::writeToFile(PATH_TO_LOGS, date, it + "\n");
    }

    return Error::OK;
}
