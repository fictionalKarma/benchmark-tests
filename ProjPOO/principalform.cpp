#include "principalform.h"
#include "ui_principalform.h"
#include <QDialog>
#include <QMessageBox>


principalForm::principalForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principalForm)
{
    ui->setupUi(this);
}
principalForm::principalForm(Administrator *a, QWidget *parent) : QMainWindow(parent), ui(new Ui::principalForm) {
    ui->setupUi(this);
    this->admin = *a;
}

principalForm::principalForm(User *u, QWidget *parent) : QMainWindow(parent), ui(new Ui::principalForm) {
    ui->setupUi(this);
    this->currentUser = *u;
}

principalForm::~principalForm()
{
    delete ui;
}

void principalForm::on_pushButton_4_clicked()//buton conferinta
{

}
