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
    ui->username_label->setText(user.getUserName());//get nume_user from database
    isUserFormShown=false;

    actualBoss= user.getTree()->getNode() ;//name=getNameofUser();
    childrenUser = user.getTree()->getChildren();
    //std::vector<Node*> children=getChildren();
    //get names and put in a vector: and defines the variable "actualBoss"


    ui->info_button->setText("About "+actualBoss->user.getUserName());
    createBossButton();
    createButons();
    //----CREATE INFOFORM
    infoForm = new userinfo(actualBoss->user
                            ,QPoint(this->pos().x()+this->width()+70,this->pos().y()));

    setWindowTitle("Principal Window");


}

principalForm::principalForm(Administrator *admin,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principalForm)
{
    administrator = *admin;
    marker = 2;
    ui->setupUi(this);
    ui->previous_button->setEnabled(false);
    ui->boss_frame->setFrameShadow(QFrame::Sunken);
    ui->children_frame->setFrameShadow(QFrame::Sunken);
    ui->username_label->setText(administrator.getUserName());//get nume_user from database


    qDebug() << administrator.getTree()->getNode1()->user->getUserName()<<"AICIIIII";
    actualBoss1= administrator.getTree()->getNode1() ;//name=getNameofUser();
    //qDebug()<<administrator.getUserName()<<"AICI!!!!!";
    childrenUser = administrator.getTree()->getChildren();
     //for(Node* n : childrenUser)
        // qDebug()<< n->user.getUserName()<<"AICI !!!!";
    //std::vector<Node*> children=getChildren();
    //get names and put in a vector: and defines the variable "actualBoss"


    //-----just tests
    childrenNames <<"andrei"<<"catalin"<<"silviu"<<"mircea"<<"victor";
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
    if(hasNoChildren_actualBoss())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error has occured !");
        messageBox.exec();
    }
    else{
    //----get the name of the object that the user has clicked on --which is going to be the texton the button/
    //the name of the user
    bossiStack.append(actualBoss);
    ui->previous_button->setEnabled(true);
    QObject *senderObj = sender();
    QString objName=senderObj->objectName();

    actualBoss = user.getTree()->find(objName);
    //qDebug() << user.getTree()->find(objName)->user.getUserName()<<"AICI!";
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
    qDebug() << "AICI!!!!";
    btnLayout=new QHBoxLayout(this);

    if(marker == 1)
    for( Node* n :actualBoss->children)
    {
        QPushButton *btn=new QPushButton( n->user.getUserName());
        btn->setObjectName( n->user.getUserName());
        btnCopii.append(btn);
        btn->setStyleSheet("QPushButton{background-color:grey; border-style: border; width: 12px; } QPushButton:hover{background-color:black; color:white; }");

        QObject::connect(btn,SIGNAL(clicked()),this,SLOT(handleButton()));
        btnLayout->addWidget(btn);
        btn->show();
    }
    else{
        for( Node* n :actualBoss1->children)
        {
            QPushButton *btn=new QPushButton( n->user.getUserName());
            btn->setObjectName( n->user.getUserName());
            btnCopii.append(btn);
            btn->setStyleSheet("QPushButton{background-color:grey; border-style: border; width: 12px; } QPushButton:hover{background-color:black; color:white; }");

            QObject::connect(btn,SIGNAL(clicked()),this,SLOT(handleButton()));
            btnLayout->addWidget(btn);
            btn->show();
        }
    }

    ui->children_frame->setLayout(btnLayout);//adaug butoanele cu copii
    update();
}
 //std::vector<Node *>principalForm::

void principalForm::on_previous_button_clicked()
{


    actualBoss=bossiStack.pop();

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
