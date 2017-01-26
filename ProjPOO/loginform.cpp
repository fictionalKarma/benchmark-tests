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
        QMap<QString, QString> userData = UserManager::getUserData(ui->nameTb->text());
            QString encPass = Operations::encode(ui->passTb->text());
            if (ui->nameTb->text() != userData["username"] || encPass != userData["password"]) {

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
                UserLevel level = UserLevel::User;
               //UserLevel level = UserLevel::Administrator;
                //UserLevel level = UserManager::getUserLevel(ui->nameTb->text());
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

                                       // qDebug()<<f.getNode()->user.getUserName()<<"AICI BOSS";
                                        Objective buget("Bugetul pe luna curenta",120, 160);
                                        Objective cifra("Cifra de afaceri",16241,25554);
                                        Objective destinatie("Produse ajunse la destinatie",0.66,1);
                                        Objective plecare("Produse plecate spre destinatie",0.80,1);
                                        Objective ocupare("Gradul de ocupare al depozitului",40,100);

                                        /*qDebug()<<buget.toString();
                                        buget.addToValue(20);
                                        qDebug()<<buget.passed();
                                        qDebug()<<buget.toString();*/
                                        Firma *f8 = new Firma(&f);
                                        f8->setObjective(&buget);
                                        f8->setObjective(&cifra);
                                        f8->setObjective(&destinatie);
                                        f8->setObjective(&plecare);
                                        f8->setObjective(&ocupare);
                                        f8->printObjectives();
                                        qDebug()<<" ";
                                        for(Objective* o: f8->getObjectives())
                                            o->addToValue(20);

                                        f8->updateObjectives();
                                        f8->printObjectivesPassed();
                                        qDebug()<<" ";
                                        f8->printObjectives();
                                        u1->setFirma(f8);
                                        u1->setTree(new Tree(u1->getFirma()->getTree()->find(u1->getUserName())));
                                       //qDebug() << u1->getTree()->find("Denis")->user.getEmail()<<"EMAIL-UL";
                                        //u1->getTree()->traverse();
                                        //qDebug() << u7.getEmail() << "EMAIL-UL";
                                        //qDebug()<< eeee->user.getEmail()<<"EMAIL-UL";
                                        int count = 0;
                                        f8->getTree()->traverse(count);
                                        qDebug()<<"Numarul de noduri: "<<count;
                                        pr = new principalForm(u1);
                } else if (level == UserLevel::Manager) {

                } else if (level == UserLevel::Administrator) {


                    Administrator *a = new Administrator(ui->nameTb->text());
                    Node1 *b = new Node1;
                    b->user = a;
                    b->father = NULL;

                     Tree f(b);

                     User u2("Vasile",b->user->getUserName()) , u3("Ionel") , u4("GICA","Vasile") , u5("IOCLA"), u6("IOI","IOCLA");
                     User  u7("Denis","Vasile") , u8("Adi","GICA") , u9("Ali","Denis");

                     Node *c = new Node , *d = new Node , *eee = new Node , *ddd = new Node , *dddd = new Node;
                     Node *abc = new Node , *abcd = new Node , *abcde = new Node;

                     c->user = u2; d->user = u3; eee->user = u4;ddd->user = u5; dddd->user = u6;
                     abc->user = u7;abcd->user = u8; abcde->user = u9;

                     f.add(c,b->user->getUserName());
                     f.add(d,b->user->getUserName());
                     f.add(eee,"Vasile");
                     f.add(ddd,"GICA");
                     f.add(dddd,"IOCLA");
                     f.add(abc,"GICA");
                     f.add(abcd,"Denis");
                     f.add(abcde,"IOCLA");
                     //f.traverse();





                    Firma *f8 = new Firma(&f);


                    a->setFirma(f8);
                    a->setTree(&f);
                    //a->getTree()->traverse();
                   // qDebug() << a->getTree()->find("Vasile")->user.getUserName() <<"ACI BOSS";
                     pr = new principalForm(a);
                }

                pr->show();
                logger->addLog(USER_LOGIN(ui->nameTb->text()));
                this->close();
                return true;
            }
        }

    return false;
}
