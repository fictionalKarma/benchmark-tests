#ifndef FORMFEED_H
#define FORMFEED_H

#include <QMainWindow>
#include "personal.h"
#include "buget.h"
#include "procesop.h"

namespace Ui {
class formfeed;
}

class formfeed : public QMainWindow
{
    Q_OBJECT

public:
    explicit formfeed(QWidget *parent = 0);
    ~formfeed();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::formfeed *ui;
    personal personal;
    buget buget;
    procesop procesop;
};

#endif // FORMFEED_H
