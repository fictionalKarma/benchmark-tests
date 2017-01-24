#include "loginform.h"


template<typename Base, typename T>
   inline bool instanceof(const T *ptr) {
       return dynamic_cast<const Base*>(ptr) != NULL;
   }

/*Tree* readTreeFromDatabase(QString firma){
    std::vector<Node*> coada ;

    Node1* newNode = new Node1 ;
    Node* nNode;

    newNode->user = new Administrator("nume administrator");
    Tree *f = new Tree(newNode);



    while(readAdministratorChildrenFromDatabase){
        nNode = new Node;

        nNode->user = administratorChild ;
        coada.push_back(nNode);
        f->add(nNode,newNode->user->getUserName());
    }

    for (Node* n:coada){
        //daca s-au citit copii din baza de date
        //adauga-i pe toti
        if(copii cititi din baza de date){
        nNode = new Node;
        nNode->user = readNChildFromDatabase;
        nNode->father = n;
        f->add(nNode,n->user.getUserName());
        coada.push_back(nNode);
        }
        //

    }
    return f;
}*/

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

                /** de facut citirea levelului user-ului din baza de date (Cosmin)
                 **/
                int level ;
                level = 0;
                // Here comes main program...

                if(level == 0){
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
                pr->show();
                this->close();
                return true;
            }
        }
    }
    return false;
}

}
