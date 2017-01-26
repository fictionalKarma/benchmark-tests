#ifndef OBJECTIVES_H
#define OBJECTIVES_H

#include <vector>
#include <QString>
#include <QDate>

class Objective{
public:

    Objective(QString S);
    Objective(QString S , double value );
    Objective(QString S , double value , double target);
    void resetTarget();
    void setTarget(double);
    void setTarget(int);
    double getTarget();
    void resetValue();
    void setValue(double);
    double getValue();
    void addToValue(double val);
    bool pass();
    bool passToday();
    QString toString();
    QString passed();
    void today();
private:
    QString targetInformation;
    double value , target , lastValue;
    QDate date;
};



#endif
