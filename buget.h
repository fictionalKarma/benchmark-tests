#ifndef BUGET_H
#define BUGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "table.h"
namespace Ui {
class buget;
}

class buget : public QWidget
{
    Q_OBJECT

public:
    explicit buget(QWidget *parent = 0);
    Table Buget;
    ~buget();
    struct pers
    {
        QString text[12];
        int n[2];
    }inputStr[60];//60 este numarul maxim de intrari, poate fi modificat
    int nrStr;
    int indiceIntrare=0;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::buget *ui;
};

#endif // BUGET_H
