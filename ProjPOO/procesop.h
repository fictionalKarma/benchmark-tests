#ifndef PROCESOP_H
#define PROCESOP_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "table.h"
#define STRSIZE 60
namespace Ui {
class procesop;
}

class procesop : public QWidget
{
    Q_OBJECT

public:
    explicit procesop(QWidget *parent = 0);
    ~procesop();
    Table Rutier, Maritim, Aerian, Depozitare, Feroviar;
    struct pers
    {
        QString text[19];
        int n[2];
    }inputStr[5*STRSIZE];//50 este numarul maxim de intrari, poate fi modificat
    int nrStr;
    int strsize=STRSIZE;
    int indiceIntrare=0;
    int editare=0;
    int nrStr1=0,nrStr2=0,nrStr3=0,nrStr4=0,nrStr5=0;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::procesop *ui;
};

#endif // PROCESOP_H
