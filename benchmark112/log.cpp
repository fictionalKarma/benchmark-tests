#include "log.hpp"

typedef std::chrono::system_clock Clock;

std::string Log::getTime(){

    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    std::stringstream buffer;
    if( parts->tm_hour < 10)
        buffer <<"0"<<parts->tm_hour  << ":";
    else
        buffer << parts->tm_hour  << ":";
    if ( parts->tm_min <10)
        buffer <<"0"<< 1    + parts->tm_min   << ":";
    else
        buffer <<1    + parts->tm_min   << ":";
    if( parts->tm_sec < 10)
        buffer <<"0"<<parts->tm_sec <<"  ";
    else
        buffer <<parts->tm_sec <<"  ";

    return	buffer.str();
}
Error Log::printBasicLog(){
    std::cout <<"Read file abracadabra at 8.30, close at 8.32 \n";

    return Error::OK;
}
Error Log::printCurrentLogs(){
    QString str;
    for(std::vector<std::string>::iterator it = logs.begin(); it != logs.end(); it++){
        //QMessageBox::information(this,"title",*it+"\n");
        str = QString::fromUtf8(it->c_str());
        qDebug() << str;
    }
    return Error::OK;
}
Error Log::addLog(Event e){
    logs.push_back(this->getTime()+e.toString());
    return Error::OK;
}
