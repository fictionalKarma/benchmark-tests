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
    connect(ui->passTb, SIGNAL(returnPressed()), this, SLOT(checkAuth()));
    logger = new Log();
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
            QString encPass = Operations::encode(ui->passTb->text());
            if (ui->nameTb->text() != dataArr[0] || encPass != dataArr[1]) {

               ui->wrongLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
               ui->wrongLbl->setText("Username or password incorrect.");
               if (UserManager::getUserLevel(ui->nameTb->text()) == UserLevel::Administrator) {
                   logger->addLog(FAILED_ADMIN_LOGIN(ui->nameTb->text()));
               }
            }

            else {
                // SUCCESSFULL LOGIN
                ui->wrongLbl->setStyleSheet("color:rgba(0, 180, 0, 1);");
                ui->wrongLbl->setText("Login Succesful!!!!");

                // Here comes main program...
                pr = new principalForm();
                UserLevel level = UserManager::getUserLevel(ui->nameTb->text());
                if (level == UserLevel::User) {
                    User *u1 = new User(ui->nameTb->text());
                    Node *b = new Node;
                    b->user = *u1;
                    b->father = NULL;
                    Tree f(b);
                    Firma *f8 = new Firma(&f);
                    u1->setFirma(f8);
                    u1->setTree(new Tree(u1->getFirma()->getTree()->find(u1->getUserName())));
                } else if (level == UserLevel::Manager) {

                } else if (level == UserLevel::Administrator) {
                    Administrator *a = new Administrator(ui->nameTb->text());
                    Node *b = new Node;
                    b->user = *a;
                    b->father = NULL;
                    Tree f(b);
                    Firma *f8 = new Firma(&f);
                    a->setFirma(f8);
                    a->setTree(new Tree(a->getFirma()->getTree()->find(a->getUserName())));
                }

                pr->show();
                logger->addLog(USER_LOGIN(ui->nameTb->text()));
                this->close();
                return true;
            }
        }
    }
    return false;
}
