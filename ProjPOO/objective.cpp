#include "objective.hpp"
#include <QDebug>

Objective::Objective(QString S){

	targetInformation = S;
	value = 0.0;
	target = 0.0;
    lastValue = 0.0;
}
Objective::Objective(QString S , double value){
	targetInformation = S;
	this->value = value;
    lastValue = 0.0;
	target =0.0;
}
Objective::Objective(QString S , double value , double tar){
	targetInformation = S;
	this->value = value ;
    lastValue = 0.0;
	target = tar;
}
void Objective::resetTarget(){
	target = 0.0;
}
void Objective::setTarget(double tar){
    target  = tar ;
}
void Objective::setTarget(int tar){
    target = (double)tar;
}

double Objective::getTarget(){
	return target;
}
void Objective::resetValue(){
    lastValue = 0.0;
	value = 0.0;
}
void Objective::setValue(double val){
	value = val ;
}
double Objective::getValue(){
	return value;
}
void Objective::addToValue(double val){
    lastValue = value;
	value += val ;
}
bool Objective::pass(){
	if(value > target)
		return true;
	return false;
}
QString Objective::toString(){
    QString tar = targetInformation;
    double procent = value / target;
    procent = procent * 100;
    int pp = (int) procent;
    tar = tar + " " + QString::number(pp) +"%";
    return tar;
}
bool Objective::passToday(){

    if((value - lastValue) > target/ date.currentDate().daysInMonth());
        return true;
    return false;
}
QString Objective::passed(){
    QString tar = targetInformation;
    if(passToday())
        tar = tar + ":" + " REACHED";
    else
        tar = tar + ":" + " NOT REACHED";
    return tar;
}
void Objective::today(){
    qDebug()<< date.currentDate().daysInMonth();
}
