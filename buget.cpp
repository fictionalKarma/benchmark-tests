#include "buget.h"
#include "ui_buget.h"

buget::buget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buget)
{
    ui->setupUi(this);
    Buget.createTable("BUGET","DATA CHAR(7), BUGET INT, CIFRA_AFACERI TEXT, COST_CUMPARARE TEXT, PERSONAL TEXT, TEHNOLOGIE TEXT, INFRASTRUCTURA TEXT, INVESTITII TEXT, COST_RUTIER TEXT, COST_DEPOZITARE TEXT, COST_MARITIM TEXT, COST_AERIAN TEXT, COST_FEROVIAR TEXT");
}

buget::~buget()
{
    delete ui;
}

void buget::on_pushButton_clicked()
{


    QString input;
        input+='\'';
        input+=ui->textEdit->toPlainText();
        input+='.';
        input+=QVariant(ui->comboBox_2->currentIndex()).toString();
        input+='\'';
        input+=',';
        input+=QVariant(ui->comboBox->currentIndex()).toString();
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
        input+=ui->textEdit_4->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_5->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_6->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_7->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_8->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_9->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_10->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_11->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_12->toPlainText();
        input+='\'';
    //Se introduce functia care preia QString input si adauga informatia in baza de date
    Buget.insertQuery("BUGET", input);
    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
    {
        widget->clear();
    }
    foreach(QComboBox *widget, this->findChildren<QComboBox*>())
    {
        widget->setCurrentIndex(0);
    }
}
void buget::on_pushButton_2_clicked()
{
    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
    {
        widget->clear();
    }
    foreach(QComboBox *widget, this->findChildren<QComboBox*>())
    {
        widget->setCurrentIndex(0);
    }
    close();
}
void buget::on_pushButton_5_clicked()
{
    ui->pushButton_4->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    int k,m,size;
    QString c;
    //nrStr=functie din baza de date care returneaza numarul de intrari
    nrStr = Buget.tableSize("BUEGT");
    for(int j=0;j<nrStr;j++){
    k=0;
    m=0;
    //QString c=functie din baza de date care returneaza sub forma de QString o intrare
    //testare v v v
    c = Buget.readQuery("BUGET", j);
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
}

void buget::on_pushButton_4_clicked()
{
    ui->textEdit->setText(inputStr[indiceIntrare].text[0]);
    ui->textEdit_2->setText(inputStr[indiceIntrare].text[1]);
    ui->textEdit_3->setText(inputStr[indiceIntrare].text[2]);
    ui->textEdit_4->setText(inputStr[indiceIntrare].text[3]);
    ui->textEdit_5->setText(inputStr[indiceIntrare].text[4]);
    ui->textEdit_6->setText(inputStr[indiceIntrare].text[5]);
    ui->textEdit_7->setText(inputStr[indiceIntrare].text[6]);
    ui->textEdit_8->setText(inputStr[indiceIntrare].text[7]);
    ui->textEdit_9->setText(inputStr[indiceIntrare].text[8]);
    ui->textEdit_10->setText(inputStr[indiceIntrare].text[9]);
    ui->textEdit_11->setText(inputStr[indiceIntrare].text[10]);
    ui->textEdit_12->setText(inputStr[indiceIntrare].text[11]);
    ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[1]);
    ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[0]);
    if(indiceIntrare+1==nrStr)
        indiceIntrare=0;
    else
        indiceIntrare++;
}

void buget::on_pushButton_3_clicked()
{
    ui->textEdit->setText(inputStr[indiceIntrare].text[0]);
    ui->textEdit_2->setText(inputStr[indiceIntrare].text[1]);
    ui->textEdit_3->setText(inputStr[indiceIntrare].text[2]);
    ui->textEdit_4->setText(inputStr[indiceIntrare].text[3]);
    ui->textEdit_5->setText(inputStr[indiceIntrare].text[4]);
    ui->textEdit_6->setText(inputStr[indiceIntrare].text[5]);
    ui->textEdit_7->setText(inputStr[indiceIntrare].text[6]);
    ui->textEdit_8->setText(inputStr[indiceIntrare].text[7]);
    ui->textEdit_9->setText(inputStr[indiceIntrare].text[8]);
    ui->textEdit_10->setText(inputStr[indiceIntrare].text[9]);
    ui->textEdit_11->setText(inputStr[indiceIntrare].text[10]);
    ui->textEdit_12->setText(inputStr[indiceIntrare].text[11]);
    ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[1]);
    ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[0]);
    if(indiceIntrare-1==-1)
        indiceIntrare=nrStr-1;
    else
        indiceIntrare--;
}
