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
                UserLevel level = UserManager::getUserLevel(ui->nameTb->text());
                if (level == UserLevel::User) {
                    User u("Georgica") , u2("Vasile","Georgica") ,
                                        u3("Ionel","Georgica"), u4("GICA","Vasile");
                                        User u5("IOCLA") , u6("IOI","IOCLA");
                                        User u7("Denis","Vasile") , u8("Adi","GICA") , u9("Ali","Denis");
                                        Node *b ,*ddd,*dddd ,*c , *d , *eee ,*eeee,*eeeee,*eeeeee;
                                        Node1 *pdf;
                                        b = new Node;
                                        b->user = u;
                                        b->father = NULL;

                                        c = new Node ; d = new Node , eee= new Node; ddd = new Node ; dddd = new Node ;
                                        eeee = new Node ; eeeee = new Node ; eeeeee = new Node ;
                                        c->user = u2; d->user = u3; eee->user = u4;
                                        ddd->user = u5; dddd->user = u6;
                                        eeee->user = u7; eeeee->user = u8; eeeeee->user = u9;


                                        User* u1 = new User(ui->nameTb->text());
                                        Node *b1;
                                        b1 = new Node;
                                        b1->user = *u1;
                                        b1->father = NULL;

                                        Tree f(b);
                                        f.add(c,"Georgica");
                                        f.add(d,"Georgica");
                                        f.add(eee,"Vasile");
                                        f.add(eeee,"Vasile");
                                        f.add(eeeee,"GICA");
                                        f.add(eeeeee,"Denis");
                                        f.add(ddd,"GICA");
                                        f.add(dddd,"IOCLA");


                                        Firma *f8 = new Firma(&f);
                                        u1->setFirma(f8);
                                        u1->setTree(new Tree(u1->getFirma()->getTree()->find(u1->getUserName())));
                                        u1->getTree()->traverse();
                                        pr = new principalForm(u1);
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
                    pr = new principalForm(a);
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
