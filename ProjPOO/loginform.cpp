#include "loginform.h"
#include "ui_loginform.h"

Tree* fetchTree(QString company){

    User *u ; Node* n;
    n= new Node;
    std::vector<QString> userii;
    std::vector <QString> cititi;
    QString companyAdministrator=UserManager::getAdmin(company);
    userii.push_back(companyAdministrator);
    //u7(compaNyAdministrator);
    User u7(companyAdministrator);
    n->user = u7;
    Tree *f = new Tree(n);



        std::vector<QString>::size_type size = userii.size();
        for (std::vector<QString>::size_type i = 0; i < size; ++i)
        {
                 cititi = UserManager::fetchCopii(company,userii[i]);
                 for(QString level2 : cititi){
                     u = new User(level2,userii[i]);
                     n->user = *u;
                     f->add(n,userii[i]);
                     n = new Node ;
                     userii.push_back(level2);
                        ++size;
                 }
            }
   /* for(QString user : userii){
        cititi = UserManager::fetchCopii(company,user);
        for (QString q : cititi)
            qDebug()<<q <<" CITIT !";
        for(QString level2 : cititi){

            u = new User(level2,user);
            n->user = *u;
            f->add(n,user);
            n = new Node ;
        }
        userii.insert(std::end(userii),std::begin(cititi),std::end(cititi));
    }*/
    return f;
}

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


                                        User* u1 = new User(ui->nameTb->text());
                                        Tree *send ;
                                        send = fetchTree(u1->getCompanyName());


                                        Objective buget("Bugetul pe luna curenta",120, 160);
                                        Objective cifra("Cifra de afaceri",16241,25554);
                                        Objective destinatie("Produse ajunse la destinatie",0.66,1);
                                        Objective plecare("Produse plecate spre destinatie",0.80,1);
                                        Objective ocupare("Gradul de ocupare al depozitului",40,100);


                                        Firma *f8 = new Firma(send);
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
                                        pr = new principalForm(u1);
                }
                pr->show();
                logger->addLog(USER_LOGIN(ui->nameTb->text()));
                this->close();
                return true;
            }
        }

    return false;
}
