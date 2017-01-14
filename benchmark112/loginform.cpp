#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QMainWindow *qm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    setFixedSize(this->size());
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(checkAuth()));
    ui->loginBtn->setEnabled(false);
    connect(ui->nameTb, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged()));
    connect(ui->passTb, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged()));
    startWindow = qm;
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButton()));
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::onTextChanged() {
    if (ui->nameTb->text().length() < 3 || ui->passTb->text().length() < 3) {
        ui->loginBtn->setEnabled(false);
    }

    else ui->loginBtn->setEnabled(true);
}

void LoginForm::cancelButton() {
    startWindow->show();
    this->close();
}

bool LoginForm::checkAuth() {
    if (!UserManager::findUserByName(ui->nameTb->text())) {
        ui->wrongLbl->setStyleSheet("color: rgba(255, 0, 0, 1);");
        ui->wrongLbl->setText("Username not found.");
        return false;
    } else {
        QString userData = UserManager::getUserData(ui->nameTb->text());
        if (userData != "404") {
            QStringList dataArr = userData.split(",");
            QString encName = Operations::encode(ui->nameTb->text());
            QString encPass = Operations::encode(ui->passTb->text());
            if (encName != dataArr[0] || encPass != dataArr[1]) {

               ui->wrongLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
               ui->wrongLbl->setText("Username or password incorrect.");
            }

            else {
                // SUCCESSFULL LOGIN!!!!!
                qDebug() << "Login succesfull!!!!!!!!!";
                ui->wrongLbl->setStyleSheet("color:rgba(0, 180, 0, 1);");
                ui->wrongLbl->setText("Login Succesful!!!!");

                // Here comes main program...
                pr = new principalForm();
                pr->show();
                this->close();
                return true;
            }
        }
    }
    return false;
}
