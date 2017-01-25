#include "userinfo.h"
#include "ui_userinfo.h"

userinfo::userinfo(User& person, QPoint location, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userinfo)
{
    ui->setupUi(this);
    setGeometry(location.x(),location.y(),250,450);

    ui->info_edit->setEnabled(false);
    anotherUser=person;
    updateForm();
}
void userinfo::updateForm(){
    QString departament;
    switch (anotherUser.getDepartment()) {
    case 0:
        departament="Rutier";
        break;
    case 1:
        departament="Depozitare";
        break;
    case 2:
        departament="Maritim";
        break;
    case 3:
        departament="Aerian";
        break;
    default:
        departament="Feroviar";
        break;

    }



ui->info_edit->setHtml("<b><u>About "+anotherUser.getUserName()+"</u></b><br /><br />"
                       "<b>EMAIL: </b>"+anotherUser.getEmail()+"<br />"
                       "<b>FIRMA: </b>"+anotherUser.getNumeFirma()+"<br />"
                       "<b>CNP: </b>"+anotherUser.getCnp()+"<br />"
                       "<b>SALARIU: </b>"+QString::number(anotherUser.getSalariu())+"<br />"
                       "<b>ADRESA </b>"+anotherUser.getAddress()+"<br />"
                       "<b>DEPARTAMENT: </b>"+departament+"<br />"
                       "<b>Competemte: </b><br />");
ui->info_edit->moveCursor(QTextCursor::End);
if(anotherUser.getManageProiect())
ui->info_edit->insertHtml("<i>Managementul proiectelor</i><br />");
if(anotherUser.getManageTimp())
    ui->info_edit->insertHtml("<i>Managementul timpului</i><br />");
if(anotherUser.getLeanManage())
    ui->info_edit->insertHtml("<i>Lean Management</i><br />");
if(anotherUser.getSixSigma())
    ui->info_edit->insertHtml("<i>Centura SixSigma</i><br />");
if(anotherUser.getTADR())
    ui->info_edit->insertHtml("<i>Transport ADR</i><br />");
if(anotherUser.getTIATA())
    ui->info_edit->insertHtml("<i>Transport IATA</i><br />");
if(anotherUser.getSisInfo()==0)
    ui->info_edit->insertHtml("<i>Sistem informatic</i><br />");
if(anotherUser.getStandardLucru())
    ui->info_edit->insertHtml("<i>Standarde de lucru</i><br />");


}


 userinfo::~userinfo()
{
    delete ui;
}
