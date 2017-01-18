#ifndef PROCESOP_H
#define PROCESOP_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "table.h"
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
    }inputStr[120];//50 este numarul maxim de intrari, poate fi modificat
    int nrStr;
    int indiceIntrare=0;

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
