#include "userinfo.h"
#include "ui_userinfo.h"

userinfo::userinfo(User& person, QPoint location, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userinfo)
{
    ui->setupUi(this);
    setGeometry(location.x(),location.y(),this->width(),this->height());

    ui->info_edit->setEnabled(false);
    anotherUser=person;
    updateForm();
}
void userinfo::updateForm(){

ui->info_edit->setHtml("<b><u>About "+anotherUser.getUserName()+"</u></b><br /><br />"
                       "<b>EMAIL: </b>"+anotherUser.getEmail()+"<br />"
                       "<b>FIRMA: </b>"+anotherUser.getNumeFirma()+"<br />"
                       "<b>CNP: </b>"+anotherUser.getCnp()+"<br />"
                       "<b>SALARIU: </b>"+"25"/*anotherUser.getSalariu()*/+"<br />"
                       "<b>ADRESA </b>"+anotherUser.getAddress()+"<br />"
                       //"<b>DEPARTAMENT: </b>"++"<br />"
                       //"<b>TRANSPORT </b>"+anotherUser.getEmail()+"<br />"
                       "<b>TRAININGURI: <b></br>");
//aici adaugi ce traininguri are persoana respectiva, faci o lista in html pt fiecare training avut, le iei din anotherUser
//cu functiile de get, la departament trebuie sa verifici din ce departament face parte userul: 0/1/2... , te uiti in personal ui a lu victor
//la transport unde nu e neaplicabil zici daca e junior etc.
// te uiti in personal ui a lu victor ca sa te prinzi de toate info!!!!!!!!



}

 userinfo::~userinfo()
{
    delete ui;
}
