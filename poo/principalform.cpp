#include "principalform.h"
#include "ui_principalform.h"
#include "conferintaform.h"
#include<QDialog>
#include<QMessageBox>


principalForm::principalForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principalForm)
{
    ui->setupUi(this);
}

principalForm::~principalForm()
{
    delete ui;
}

void principalForm::on_pushButton_4_clicked()//buton conferinta
{
    //conf=new conferintaForm(this);
    //conf->show();

}
