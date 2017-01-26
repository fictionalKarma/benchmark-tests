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
    QString department = anotherUser.getDepartment();



ui->info_edit->setHtml("<b><u>About "+anotherUser.getUserName()+"</u></b><br /><br />"
                       "<b>EMAIL: </b>"+anotherUser.getEmail()+"<br />"
                       "<b>COMPANY: </b>"+anotherUser.getCompanyName()+"<br />"
                       "<b>CNP: </b>"+anotherUser.getCnp()+"<br />"
                       "<b>SALARY: </b>"+QString::number(anotherUser.getSalary())+"<br />"
                       "<b>ADDRESS: </b>"+anotherUser.getAddress()+"<br />"
                       "<b>DEPARTMENT: </b>"+department+"<br />"
                       "<b>Competences: </b><br />");
    ui->info_edit->moveCursor(QTextCursor::End);
if(anotherUser.hasProjectManagementTraining())
    ui->info_edit->insertHtml("<i>Managementul proiectelor</i><br />");
if(anotherUser.hasTimeManagementTraining())
    ui->info_edit->insertHtml("<i>Managementul timpului</i><br />");
if(anotherUser.hasSixSigmaBelt())
    ui->info_edit->insertHtml("<i>Centura SixSigma</i><br />");
if(anotherUser.hasADRLicense())
    ui->info_edit->insertHtml("<i>Transport ADR</i><br />");
if(anotherUser.hasIATALicence())
    ui->info_edit->insertHtml("<i>Transport IATA</i><br />");
if(anotherUser.hasITTraining())
    ui->info_edit->insertHtml("<i>Sistem informatic</i><br />");

}


 userinfo::~userinfo()
{
    delete ui;
}
