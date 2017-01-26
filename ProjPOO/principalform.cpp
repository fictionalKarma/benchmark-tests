#include "principalform.h"



principalForm::principalForm(User *u,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principalForm)
{

    user = *u;
    qDebug()<< u->getEmail()<<" AICI";
    marker = 1;
    ui->setupUi(this);
    ui->previous_button->setEnabled(false);
    ui->boss_frame->setFrameShadow(QFrame::Sunken);
    ui->children_frame->setFrameShadow(QFrame::Sunken);
    QString welcome = "Welcome,\n   ";
    welcome.append(user.getUserName());
    welcome.append(" !");
    ui->username_label->setText(welcome);//get nume_user from database
    isUserFormShown=false;

    actualBoss = user.getTree()->getNode();//name=getNameofUser();
    actualBoss->user = *u;


    childrenUser = user.getTree()->getChildren();
    //std::vector<Node*> children=getChildren();
    //get names and put in a vector: and defines the variable "actualBoss"
    setGeometry(0,30,this->width(),this->height());
    ui->info_button->setText("About "+actualBoss->user.getUserName());
     //qDebug() << user.getTree()->find("Denis")->user.getEmail()<<"CNP-UL";
    createBossButton();
    createButons();
    //----CREATE INFOFORM
    infoForm = new userinfo(actualBoss->user
                            ,QPoint(this->pos().x()+this->width()+70,this->pos().y()));

    setWindowTitle("Principal Window");
    qDebug()<<u->getUserName()<<":"<<u->checkAdmin();
    qDebug()<<actualBoss->user.getUserName()<<":"<<actualBoss->user.checkAdmin();
    if(actualBoss->user.checkAdmin()==false)
    {
        ui->buget_button->hide();
        ui->procese_button->hide();
    }


}

principalForm::principalForm(Administrator *admin,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principalForm)
{
    this->installEventFilter(this);
    administrator = *admin;
    user = *admin;
    copy = *admin;
    marker = 2;
    ui->setupUi(this);
    ui->previous_button->setEnabled(false);
    ui->boss_frame->setFrameShadow(QFrame::Sunken);
    ui->children_frame->setFrameShadow(QFrame::Sunken);
    ui->username_label->setText(administrator.getUserName());//get nume_user from database



    newNode = new Node; User u1(admin->getUserName());
    newNode->user = u1;
    newNode->children = admin->getTree()->getNode1()->children;
    newNode->user.setTree(admin->getTree());
    newNode->user.getTree()->setBoss(newNode);
    qDebug() << newNode->user.getTree()->getNode()->user.getUserName() << "BOSS-UL !!!";

   // qDebug() << newNode->user.getTree()->find("Vasile")->user.getUserName() << " User !!";

    actualBoss = newNode;
    actualBoss1= administrator.getTree()->getNode1() ;//name=getNameofUser();
    //actualBoss->user.getTree()->traverse();
    //administrator.getTree()->traverse();
    //administrator.getTree()->traverse("Denis");
   //qDebug() << actualBoss->user.getTree()->find("Vasile")->user.getUserName();

    createBossButton();
    createButons();
    setWindowTitle("Principal Window");


}

principalForm::~principalForm()
{
    delete ui;
}



void principalForm::on_pushButton_clicked()//buton de formfeed
{


}


void principalForm::on_pushButton_2_clicked()//buton de afiseaza firma
{



}


void principalForm::modifyButtonsTree()
{
    btnPrincipal->setText(actualBoss->user.getUserName());
    btnPrincipal->show();
     QListIterator<QPushButton*> iter(btnCopii);
    int i=0;
    while(iter.hasNext())
    {
        QPushButton *pb=iter.next();
        pb->hide();
        pb->setText(childrenNames[i++]);
        pb->show();
    }
}
void principalForm::handleButton()
{
    //qDebug() << newNode->user.getTree()->getNode1()->user->getUserName();
    //qDebug() << newNode->user.getTree()->find("Vasile")->user.getUserName() << " User !!";
    //qDebug() <<newNode->user.getTree()->getNode()->user.getUserName()<<" AICI BOSS";
    if(hasNoChildren_actualBoss())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"bool","An error has occured !");
        messageBox.exec();
    }
    else {
    //----get the name of the object that the user has clicked on --which is going to be the texton the button/
    //the name of the user
    bossiStack.append(actualBoss);
    ui->previous_button->setEnabled(true);
    QObject *senderObj = sender();
    QString objName=senderObj->objectName();
    //qDebug() << newNode->user.getTree()->find("Vasile")->user.getUserName() << " User !!";
    if(marker == 1){
    actualBoss = user.getTree()->find(objName);
    actualBoss->user = user.getTree()->find(objName)->user;
    }
    int k= 0;
    if(isUserFormShown) k =1;

    //delete infoForm;


    if ( k == 1)
       infoForm->hide();

    infoForm = new userinfo(actualBoss->user
                            ,QPoint(this->pos().x()+this->width()+70,this->pos().y()));
    if( k == 1)
        infoForm->show();
    qDebug() << actualBoss->user.getCnp()<<"CNP-UL";
    //qDebug() << user.getTree()->find(objName)->user.getEmail()<<"CNP-UL";
    }


    //actualBoss = newNode->user.getTree()->find(objName);
    //qDebug() << newNode->user.getTree()->find(objName)->user.getUserName()<<" USER!!";
    btnPrincipal->setText(actualBoss->user.getUserName());
    btnPrincipal->setObjectName(actualBoss->user.getUserName());


    //btnCopii.removeAll();
     QListIterator <QPushButton*> iter(btnCopii);
     while(iter.hasNext())
     {
         QPushButton *some=iter.next();
         ui->children_frame->layout()->removeWidget(some);
        ui->children_frame->update();
         some->hide();
     }
     /*if(!(ui->children_frame->findChild<QWidget*>("Silviu")))
         close();*/
     btnCopii.clear();

    //------------
  //get the next one
  update_childrenNames();
   delete ui->children_frame->layout();
  createButons();
   ui->info_button->setText("About "+actualBoss->user.getUserName());
  QWidget::update();
  QMessageBox mb;
  mb.setText(/*actualBoss*/QString("%1").arg(btnCopii.count()));
  mb.exec();

}




void principalForm::update_childrenNames()
{
    childrenNames.clear();
    childrenNames<<"cineva1"<<"cineva2";
    /*childrenNames[0]="Catalin";
    btnCopii.at(0)->setText("Catalin");
    btnCopii.at(0)->setObjectName("Catalin");
    childrenNames.remove(4);
    btnCopii.removeAt(4);*/
}

void principalForm::createBossButton()
{

    btnLayout=new QHBoxLayout(this);

    if(marker == 1){
    btnPrincipal=new QPushButton(actualBoss->user.getUserName());
    btnPrincipal->setStyleSheet("QPushButton{background-color:white; border-style: border; width: 12px}");
    btnLayout->addWidget(btnPrincipal);
    }
    else{
        qDebug()<<actualBoss1->user->getUserName()<<"AICI!!!!";
        btnPrincipal=new QPushButton(actualBoss1->user->getUserName());
            btnPrincipal->setStyleSheet("QPushButton{background-color:white; border-style: border; width: 12px}");
            btnLayout->addWidget(btnPrincipal);
    }
    ui->boss_frame->setLayout(btnLayout);//adaug BUTONUL CU seful
}

//OBS! FUNCTIA DE CREATE SI UPDATEAZA PRIMII USERI
void principalForm::createButons()
{

    btnLayout=new QHBoxLayout(this);


    for( Node* n :actualBoss->children)
    {
        qDebug()<<n->user.getUserName();
        QPushButton *btn=new QPushButton( n->user.getUserName());
        btn->setObjectName( n->user.getUserName());
        btnCopii.append(btn);
        btn->setStyleSheet("QPushButton{background-color:grey; border-style: border; width: 12px; } QPushButton:hover{background-color:black; color:white; }");

        QObject::connect(btn,SIGNAL(clicked()),this,SLOT(handleButton()));
        btnLayout->addWidget(btn);
        btn->show();
    }



    ui->children_frame->setLayout(btnLayout);//adaug butoanele cu copii
    update();
}
 //std::vector<Node *>principalForm::

void principalForm::on_previous_button_clicked()
{


    actualBoss=bossiStack.pop();

    int k= 0;
    if(isUserFormShown) k =1;
    if (k ==1)
        infoForm->hide();
    infoForm = new userinfo(actualBoss->user
                            ,QPoint(this->pos().x()+this->width()+70,this->pos().y()));
    if( k == 1)
        infoForm->show();
    btnPrincipal->setText(actualBoss->user.getUserName());
    btnPrincipal->setObjectName(actualBoss->user.getUserName());
    ui->info_button->setText("About "+actualBoss->user.getUserName());
     QListIterator <QPushButton*> iter(btnCopii);
     while(iter.hasNext())
     {
         QPushButton *some=iter.next();
         ui->children_frame->layout()->removeWidget(some);
        ui->children_frame->update();
         some->hide();
     }

     btnCopii.clear();

    //------------
  //get the next one
  update_childrenNames();
   delete ui->children_frame->layout();
  createButons();
  if(bossiStack.isEmpty())
  {
      ui->previous_button->setEnabled(false);
  }
    }

bool principalForm::hasNoChildren_actualBoss()
{
    return false;
}

void principalForm::on_pushButton_4_button_clicked()
{

}
void principalForm::on_pushButton_2_clicked(bool vari)
{

}
void principalForm::on_pushButton_4_clicked(){}

void principalForm::on_info_button_clicked()
{
    if(isUserFormShown)
    {
        infoForm->hide();
        isUserFormShown=false;
    }
    else{
            infoForm->show();
            isUserFormShown=true;
        }

}

void principalForm::on_procese_button_clicked()
{
    procesForm=new procesop;
    procesForm->show();
}

void principalForm::on_buget_button_clicked()
{
    bugetForm =new buget;
    bugetForm->show();
}
