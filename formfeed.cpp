#include "formfeed.h"
#include "ui_formfeed.h"

formfeed::formfeed(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::formfeed)
{
    ui->setupUi(this);
}

formfeed::~formfeed()
{
    delete ui;
}

void formfeed::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
}

void formfeed::on_pushButton_3_clicked()
{
    personal.show();
}
void formfeed::on_pushButton_4_clicked()
{
    buget.show();
}

void formfeed::on_pushButton_clicked()
{
    procesop.show();
}
