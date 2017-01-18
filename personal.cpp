#include "personal.h"
#include "ui_personal.h"
#include <QMessageBox>
#include <string>

personal::personal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personal)
{
    ui->setupUi(this);
    Personal.createTable("PERSONAL", "CNP TEXT, NUME TEXT, EMAIL TEXT, FACULTATE TEXT, FILIALA TEXT, CALITATE INT, SALARIU TEXT, MONEDA INT, DEPARTAMENT INT, ADRESA TEXT, T_AERIAN INT, T_MARITIM INT, T_RUTIER INT, T_FEROVIAR INT, T_INTERNATIONAL INT, T_DOMESTIC INT, DEPOZITARE INT, CORMECIAL INT, ACHIZITII INT, MAN_ECHIPA INT, ANALIZA_DATELOR INT, PREZETARE INT, LUARE_DECIZII INT, COMUNICARE INT, MAN_PROIECTE INT, MAN_TIMP INT, LEAN_MAN INT, CENTURA_SIXSIGMA INT, T_ADR INT, T_IATA INT, SIST_INFORMATIC INT, STANDARDE_LUCRU INT");
}
personal::~personal()
{
    delete ui;
}
void personal::on_pushButton_clicked()
{
    //testare v v v
    /*QString filename=(qApp->applicationDirPath() + "personal.txt");
    QFile personal(filename);
    personal.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream persout(&personal);
    QString filename_edit=(qApp->applicationDirPath() + "personal_edit.txt");
    QFile personal_edit(filename_edit);
    personal_edit.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream persout_edit(&personal_edit);*/
    //testare ^ ^ ^
    QString input;
    input+='\'';
    input+=ui->textEdit_4->toPlainText();
    input+='\'';
    input+=',';
    input+='\'';
    input+=ui->textEdit->toPlainText();
    input+='\'';
    input+=',';
    input+='\'';
    input+=ui->textEdit_2->toPlainText();
    input+='\'';
    input+=',';
    input+='\'';
    input+=ui->textEdit_3->toPlainText();
    input+='\'';
    input+=',';
    input+='\'';
    input+=ui->textEdit_5->toPlainText();
    input+='\'';
    input+=',';
    input+=QVariant(ui->comboBox_16->currentIndex()).toString();
    input+=',';
    input+='\'';
    input+=ui->textEdit_7->toPlainText();
    input+='\'';
    input+=',';
    input+=QVariant(ui->comboBox_15->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_17->currentIndex()).toString();
    input+=',';
    input+='\'';
    input+=ui->textEdit_6->toPlainText();
    input+='\'';
    input+=',';
    input+=QVariant(ui->comboBox_6->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_7->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_8->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_9->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_10->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_11->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_12->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_13->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_14->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_2->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_3->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_4->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->comboBox_5->currentIndex()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_2->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_3->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_4->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_5->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_6->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_7->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_8->checkState()).toString();
    input+=',';
    input+=QVariant(ui->checkBox_9->checkState()).toString();
    //testare v v v
    //persout<<input<<endl;
    //testare ^ ^ ^
    //Se introduce functia care preia QString input si adauga informatia in baza de date
    Personal.insertQuery("PERSONAL", input);
    qDebug()<<input;
    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
    {
        widget->clear();
    }
    foreach(QComboBox *widget, this->findChildren<QComboBox*>())
    {
        widget->setCurrentIndex(4);
    }
    ui->comboBox_15->setCurrentIndex(0);
    ui->comboBox_16->setCurrentIndex(0);
    ui->comboBox_17->setCurrentIndex(0);
    foreach(QCheckBox *widget, this->findChildren<QCheckBox*>())
    {
        widget->setChecked(false);
    }
}
void personal::on_pushButton_2_clicked()
{
   foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
   {
       widget->clear();
   }
   foreach(QComboBox *widget, this->findChildren<QComboBox*>())
   {
       widget->setCurrentIndex(4);
   }
   foreach(QCheckBox *widget, this->findChildren<QCheckBox*>())
   {
       widget->setChecked(false);
   }
   ui->comboBox_15->setCurrentIndex(0);
   ui->comboBox_16->setCurrentIndex(0);
   ui->comboBox_17->setCurrentIndex(0);
   close();
}
void personal::on_pushButton_5_clicked()
{
    ui->pushButton_4->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    //testare v v v
    /*QString filename=(qApp->applicationDirPath() + "personal.txt");
    QFile personal(filename);
    personal.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream persout(&personal);*/
    //testare ^ ^ ^
    int k,m,size;
    QString c;
    //nrStr=functie din baza de date care returneaza numarul de intrari
    nrStr = Personal.tableSize("PERSONAL");
    //testare v v v
    //nrStr=2;
    //testare ^ ^ ^
    for(int j=0;j<nrStr;j++){
    k=0;
    m=0;
    //QString c=functie din baza de date care returneaza sub forma de QString o intrare
    //testare v v v
    c = Personal.readQuery("PERSONAL", j);
    /*if(j==0)
        c="'CNP1','nume1','email1','facultate1','filiala1',1,'adresa1',0,3,'salariu1',2,4,2,4,4,4,2,3,4,4,4,2,4,1,2,0,2,0,0,2,0,0";
    if(j==1)
        c="'CNP2','nume2','email2','facultate2','filiala2',2,'adresa2',1,1,'salariu2',0,1,4,0,1,4,4,2,4,0,3,4,2,4,0,0,2,2,2,2,2,0";*/
    //testare ^ ^ ^
    size=c.size();
    for(int i=0;i<size;i++)
    {
        if(c[i]=='\'')
        {
           while(c[i]!=','&&i<size)
           {
                if(c[i]=='\'')
                {
                    i++;
                    continue;
                }
                else
                {
                    inputStr[j].text[k]+=c[i];
                    i++;
                }
            }
            k++;
        }
        else
        {
            inputStr[j].n[m]=c[i].unicode()-48;
            i++;
            m++;
        }
    }}
    //testare v v v
    /*for(int i=0;i<7;i++)
        persout<<inputStr[j].text[i]<<" ";
    for(int i=0;i<25;i++)
        persout<<inputStr[j].n[i]<<" ";
    persout<<endl;}*/
    //testare ^ ^ ^
}
void personal::on_pushButton_4_clicked()
{
    ui->textEdit->setText(inputStr[indiceIntrare].text[1]);
    ui->textEdit_2->setText(inputStr[indiceIntrare].text[2]);
    ui->textEdit_3->setText(inputStr[indiceIntrare].text[3]);
    ui->textEdit_4->setText(inputStr[indiceIntrare].text[0]);
    ui->textEdit_5->setText(inputStr[indiceIntrare].text[4]);
    ui->textEdit_6->setText(inputStr[indiceIntrare].text[5]);
    ui->textEdit_7->setText(inputStr[indiceIntrare].text[6]);
    ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[12]);
    ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[13]);
    ui->comboBox_3->setCurrentIndex(inputStr[indiceIntrare].n[14]);
    ui->comboBox_4->setCurrentIndex(inputStr[indiceIntrare].n[15]);
    ui->comboBox_5->setCurrentIndex(inputStr[indiceIntrare].n[16]);
    ui->comboBox_6->setCurrentIndex(inputStr[indiceIntrare].n[3]);
    ui->comboBox_7->setCurrentIndex(inputStr[indiceIntrare].n[4]);
    ui->comboBox_8->setCurrentIndex(inputStr[indiceIntrare].n[5]);
    ui->comboBox_9->setCurrentIndex(inputStr[indiceIntrare].n[6]);
    ui->comboBox_10->setCurrentIndex(inputStr[indiceIntrare].n[7]);
    ui->comboBox_11->setCurrentIndex(inputStr[indiceIntrare].n[8]);
    ui->comboBox_12->setCurrentIndex(inputStr[indiceIntrare].n[9]);
    ui->comboBox_13->setCurrentIndex(inputStr[indiceIntrare].n[10]);
    ui->comboBox_14->setCurrentIndex(inputStr[indiceIntrare].n[11]);
    ui->comboBox_15->setCurrentIndex(inputStr[indiceIntrare].n[1]);
    ui->comboBox_16->setCurrentIndex(inputStr[indiceIntrare].n[0]);
    ui->comboBox_17->setCurrentIndex(inputStr[indiceIntrare].n[2]);
    ui->checkBox_2->setChecked(inputStr[indiceIntrare].n[17]);
    ui->checkBox_3->setChecked(inputStr[indiceIntrare].n[18]);
    ui->checkBox_4->setChecked(inputStr[indiceIntrare].n[19]);
    ui->checkBox_5->setChecked(inputStr[indiceIntrare].n[20]);
    ui->checkBox_6->setChecked(inputStr[indiceIntrare].n[21]);
    ui->checkBox_7->setChecked(inputStr[indiceIntrare].n[22]);
    ui->checkBox_8->setChecked(inputStr[indiceIntrare].n[23]);
    ui->checkBox_9->setChecked(inputStr[indiceIntrare].n[24]);
    if(indiceIntrare+1==nrStr)
        indiceIntrare=0;
    else
        indiceIntrare++;
}

void personal::on_pushButton_3_clicked()
{
    ui->textEdit->setText(inputStr[indiceIntrare].text[1]);
    ui->textEdit_2->setText(inputStr[indiceIntrare].text[2]);
    ui->textEdit_3->setText(inputStr[indiceIntrare].text[3]);
    ui->textEdit_4->setText(inputStr[indiceIntrare].text[0]);
    ui->textEdit_5->setText(inputStr[indiceIntrare].text[4]);
    ui->textEdit_6->setText(inputStr[indiceIntrare].text[5]);
    ui->textEdit_7->setText(inputStr[indiceIntrare].text[6]);
    ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[12]);
    ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[13]);
    ui->comboBox_3->setCurrentIndex(inputStr[indiceIntrare].n[14]);
    ui->comboBox_4->setCurrentIndex(inputStr[indiceIntrare].n[15]);
    ui->comboBox_5->setCurrentIndex(inputStr[indiceIntrare].n[16]);
    ui->comboBox_6->setCurrentIndex(inputStr[indiceIntrare].n[3]);
    ui->comboBox_7->setCurrentIndex(inputStr[indiceIntrare].n[4]);
    ui->comboBox_8->setCurrentIndex(inputStr[indiceIntrare].n[5]);
    ui->comboBox_9->setCurrentIndex(inputStr[indiceIntrare].n[6]);
    ui->comboBox_10->setCurrentIndex(inputStr[indiceIntrare].n[7]);
    ui->comboBox_11->setCurrentIndex(inputStr[indiceIntrare].n[8]);
    ui->comboBox_12->setCurrentIndex(inputStr[indiceIntrare].n[9]);
    ui->comboBox_13->setCurrentIndex(inputStr[indiceIntrare].n[10]);
    ui->comboBox_14->setCurrentIndex(inputStr[indiceIntrare].n[11]);
    ui->comboBox_15->setCurrentIndex(inputStr[indiceIntrare].n[1]);
    ui->comboBox_16->setCurrentIndex(inputStr[indiceIntrare].n[0]);
    ui->comboBox_17->setCurrentIndex(inputStr[indiceIntrare].n[2]);
    ui->checkBox_2->setChecked(inputStr[indiceIntrare].n[17]);
    ui->checkBox_3->setChecked(inputStr[indiceIntrare].n[18]);
    ui->checkBox_4->setChecked(inputStr[indiceIntrare].n[19]);
    ui->checkBox_5->setChecked(inputStr[indiceIntrare].n[20]);
    ui->checkBox_6->setChecked(inputStr[indiceIntrare].n[21]);
    ui->checkBox_7->setChecked(inputStr[indiceIntrare].n[22]);
    ui->checkBox_8->setChecked(inputStr[indiceIntrare].n[23]);
    ui->checkBox_9->setChecked(inputStr[indiceIntrare].n[24]);
    if(indiceIntrare-1==-1)
        indiceIntrare=nrStr-1;
    else
        indiceIntrare--;
}
