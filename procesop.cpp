#include "procesop.h"
#include "ui_procesop.h"
#include "table.h"
#include <QDebug>
procesop::procesop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::procesop)
{
    ui->setupUi(this);
    Rutier.createTable("RUTIER", "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI, RATA_KM_PARCURSI TEXT, GRAD_INCARCARE_DISTRIBUTIE TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");
    Depozitare.createTable("DEPOZITARE", "DATA TEXT, RESPECTARE_LIMITE_COMANDA TEXT, ACURATETE_PREGATIRE_COMENZI TEXT, RATA_DAUNE_LIPSURI TEXT, ACURATETE_STOC TEXT, GRAD_OCUPARE_DEPOZIT TEXT, DSO TEXT, DPO TEXT");
    Maritim.createTable("MARITIM", "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");
    Aerian.createTable("AERIAN",   "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");
    Feroviar.createTable("FEROVIAR", "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI, RATA_KM_PARCURSI TEXT, GRAD_INCARCARE_DISTRIBUTIE TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");
}


procesop::~procesop()
{
    delete ui;
}

void procesop::on_pushButton_2_clicked()
{
     close();
}
void procesop::on_pushButton_clicked()
{
    int choice = 0;
    if(ui->comboBox->currentIndex()==1)
    {
        QString input;
        input+='\'';
        input+=ui->textEdit_19->toPlainText();
        input+='.';
        input+=QVariant(ui->comboBox_2->currentIndex()).toString();
        input+='\'';
        //input+=QVariant(ui->comboBox->currentIndex()).toString();
        input+=',';
        input+='\'';
        input+=ui->textEdit_11->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_12->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_13->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_14->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_15->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_16->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_17->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_18->toPlainText();
        input+='\'';
        //Se introduce functia care preia QString input si adauga informatia in baza de date (proces depozitare)
        Depozitare.insertQuery("DEPOZITARE", input);
    }
    else
    {
        QString input;
        choice=0;
        input+=QVariant(ui->comboBox->currentIndex()).toString();
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
        if(ui->comboBox->currentIndex()==0||ui->comboBox->currentIndex()==4)
        {
            choice=1;
            input+='\'';
            input+=ui->textEdit_7->toPlainText();
            input+='\'';
            input+=',';
            input+='\'';
            input+=ui->textEdit_8->toPlainText();
            input+='\'';
            input+=',';
        }
        input+='\'';
        input+=ui->textEdit_9->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_10->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_17->toPlainText();
        input+='\'';
        input+=',';
        input+='\'';
        input+=ui->textEdit_18->toPlainText();
        input+='\'';
        if(choice==1)
            if(ui->comboBox->currentIndex()==0){
                //Se introduce functia care preia QString input si adauga informatia in baza de date (proces rutier)
                Rutier.insertQuery("RUTIER", input);
                qDebug()<<input;
            }
            else
                //Se introduce functia care preia QString input si adauga informatia in baza de date (proces feroviar)
                Feroviar.insertQuery("FEROVIAR", input);
        if(choice==0)
            if(ui->comboBox->currentIndex()==2)
                //Se introduce functia care preia QString input si adauga informatia in baza de date (proces maritim)
                Maritim.insertQuery("MARITIM", input);
            else
                //Se introduce functia care preia QString input si adauga informatia in baza de date (proces aerian)
                Aerian.insertQuery("AERIAN", input);
    }

    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
    {
        widget->clear();
    }
    ui->comboBox->setCurrentIndex(0);
}

void procesop::on_comboBox_activated(int index)
{
    if(index==1)
    {
        ui->textEdit->setEnabled(0);
        ui->textEdit_2->setEnabled(0);
        ui->textEdit_3->setEnabled(0);
        ui->textEdit_4->setEnabled(0);
        ui->textEdit_5->setEnabled(0);
        ui->textEdit_6->setEnabled(0);
        ui->textEdit_7->setEnabled(0);
        ui->textEdit_8->setEnabled(0);
        ui->textEdit_9->setEnabled(0);
        ui->textEdit_10->setEnabled(0);
        ui->textEdit_11->setEnabled(1);
        ui->textEdit_12->setEnabled(1);
        ui->textEdit_13->setEnabled(1);
        ui->textEdit_14->setEnabled(1);
        ui->textEdit_15->setEnabled(1);
        ui->textEdit_16->setEnabled(1);
    }
    else
    {
        ui->textEdit->setEnabled(1);
        ui->textEdit_2->setEnabled(1);
        ui->textEdit_3->setEnabled(1);
        ui->textEdit_4->setEnabled(1);
        ui->textEdit_5->setEnabled(1);
        ui->textEdit_6->setEnabled(1);
        if(index==2||index==3)
        {
            ui->textEdit_7->setEnabled(0);
            ui->textEdit_8->setEnabled(0);
        }
        else
        {
            ui->textEdit_7->setEnabled(1);
            ui->textEdit_8->setEnabled(1);
        }
        ui->textEdit_9->setEnabled(1);
        ui->textEdit_10->setEnabled(1);
        ui->textEdit_11->setEnabled(0);
        ui->textEdit_12->setEnabled(0);
        ui->textEdit_13->setEnabled(0);
        ui->textEdit_14->setEnabled(0);
        ui->textEdit_15->setEnabled(0);
        ui->textEdit_16->setEnabled(0);
    }
}

void procesop::on_pushButton_3_clicked()
{
    if(inputStr[indiceIntrare].n[0]==1)
        {
            ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[0]);
            ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[1]);
            ui->textEdit_19->setText(inputStr[indiceIntrare].text[0]);
            ui->textEdit_11->setText(inputStr[indiceIntrare].text[1]);
            ui->textEdit_12->setText(inputStr[indiceIntrare].text[2]);
            ui->textEdit_13->setText(inputStr[indiceIntrare].text[3]);
            ui->textEdit_14->setText(inputStr[indiceIntrare].text[4]);
            ui->textEdit_15->setText(inputStr[indiceIntrare].text[5]);
            ui->textEdit_16->setText(inputStr[indiceIntrare].text[6]);
            ui->textEdit_17->setText(inputStr[indiceIntrare].text[7]);
            ui->textEdit_18->setText(inputStr[indiceIntrare].text[8]);
        }
        else
        {
            ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[0]);
            ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[1]);
            ui->textEdit_19->setText(inputStr[indiceIntrare].text[0]);
            ui->textEdit->setText(inputStr[indiceIntrare].text[1]);
            ui->textEdit_2->setText(inputStr[indiceIntrare].text[2]);
            ui->textEdit_3->setText(inputStr[indiceIntrare].text[3]);
            ui->textEdit_4->setText(inputStr[indiceIntrare].text[4]);
            ui->textEdit_5->setText(inputStr[indiceIntrare].text[5]);
            ui->textEdit_6->setText(inputStr[indiceIntrare].text[6]);
            if(inputStr[indiceIntrare].n[0]==0||inputStr[indiceIntrare].n[0]==4)
            {
                ui->textEdit_7->setText(inputStr[indiceIntrare].text[7]);
                ui->textEdit_8->setText(inputStr[indiceIntrare].text[8]);
                ui->textEdit_9->setText(inputStr[indiceIntrare].text[9]);
                ui->textEdit_10->setText(inputStr[indiceIntrare].text[10]);
                ui->textEdit_17->setText(inputStr[indiceIntrare].text[11]);
                ui->textEdit_18->setText(inputStr[indiceIntrare].text[12]);
            }
            else
            {
                ui->textEdit_9->setText(inputStr[indiceIntrare].text[7]);
                ui->textEdit_10->setText(inputStr[indiceIntrare].text[8]);
                ui->textEdit_17->setText(inputStr[indiceIntrare].text[9]);
                ui->textEdit_18->setText(inputStr[indiceIntrare].text[10]);
            }
        }
    if(indiceIntrare-1==-1)
        indiceIntrare=nrStr-1;
    else
        indiceIntrare--;
}

void procesop::on_pushButton_4_clicked()
{
    if(inputStr[indiceIntrare].n[0]==1)
        {
            ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[0]);
            ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[1]);
            ui->textEdit_19->setText(inputStr[indiceIntrare].text[0]);
            ui->textEdit_11->setText(inputStr[indiceIntrare].text[1]);
            ui->textEdit_12->setText(inputStr[indiceIntrare].text[2]);
            ui->textEdit_13->setText(inputStr[indiceIntrare].text[3]);
            ui->textEdit_14->setText(inputStr[indiceIntrare].text[4]);
            ui->textEdit_15->setText(inputStr[indiceIntrare].text[5]);
            ui->textEdit_16->setText(inputStr[indiceIntrare].text[6]);
            ui->textEdit_17->setText(inputStr[indiceIntrare].text[7]);
            ui->textEdit_18->setText(inputStr[indiceIntrare].text[8]);
        }
        else
        {
            ui->comboBox->setCurrentIndex(inputStr[indiceIntrare].n[0]);
            ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[1]);
            ui->textEdit_19->setText(inputStr[indiceIntrare].text[0]);
            ui->textEdit->setText(inputStr[indiceIntrare].text[1]);
            ui->textEdit_2->setText(inputStr[indiceIntrare].text[2]);
            ui->textEdit_3->setText(inputStr[indiceIntrare].text[3]);
            ui->textEdit_4->setText(inputStr[indiceIntrare].text[4]);
            ui->textEdit_5->setText(inputStr[indiceIntrare].text[5]);
            ui->textEdit_6->setText(inputStr[indiceIntrare].text[6]);
            if(inputStr[indiceIntrare].n[0]==0||inputStr[indiceIntrare].n[0]==4)
            {
                ui->textEdit_7->setText(inputStr[indiceIntrare].text[7]);
                ui->textEdit_8->setText(inputStr[indiceIntrare].text[8]);
                ui->textEdit_9->setText(inputStr[indiceIntrare].text[9]);
                ui->textEdit_10->setText(inputStr[indiceIntrare].text[10]);
                ui->textEdit_17->setText(inputStr[indiceIntrare].text[11]);
                ui->textEdit_18->setText(inputStr[indiceIntrare].text[12]);
            }
            else
            {
                ui->textEdit_9->setText(inputStr[indiceIntrare].text[7]);
                ui->textEdit_10->setText(inputStr[indiceIntrare].text[8]);
                ui->textEdit_17->setText(inputStr[indiceIntrare].text[9]);
                ui->textEdit_18->setText(inputStr[indiceIntrare].text[10]);
            }
        }
    if(indiceIntrare+1==nrStr)
        indiceIntrare=0;
    else
        indiceIntrare++;
}

void procesop::on_pushButton_5_clicked()
{
    ui->pushButton_4->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    int k,m,size,nrStr1,nrStr2,nrStr3,nrStr4,nrStr5,indici[5]={0,0,0,0,0};
    //nrStr1=functie din baza de date care returneaza numarul de intrari rutier
    nrStr1 = Rutier.tableSize("RUTIER");
    //nrStr2=functie din baza de date care returneaza numarul de intrari depozitare
    nrStr2 = Depozitare.tableSize("DEPOZITARE");
    //nrStr3=functie din baza de date care returneaza numarul de intrari maritim
    nrStr3 = Maritim.tableSize("MARITIM");
    //nrStr4=functie din baza de date care returneaza numarul de intrari aerian
    nrStr4 = Aerian.tableSize("AERIAN");
    //nrStr5=functie din baza de date care returneaza numarul de intrari feroviar
    nrStr5 = Feroviar.tableSize("FEROVIAR");
    nrStr=nrStr1+nrStr2+nrStr3+nrStr4+nrStr5;
    QString c;
    for(int j=0;j<nrStr;j++){
    k=0;
    m=0;
    //c=functie din baza de date care returneaza sub forma de QString o intrare (orice format)
    //testare v v v
    /*if(j==0)
        c="'CNP1','nume1','email1','facultate1','filiala1',1,'adresa1',0,3,'salariu1',2,4,2,4,4,4,2,3,4,4,4,2,4,1,2,0,2,0,0,2,0,0";
    if(j==1)
        c="'CNP2','nume2','email2','facultate2','filiala2',2,'adresa2',1,1,'salariu2',0,1,4,0,1,4,4,2,4,0,3,4,2,4,0,0,2,2,2,2,2,0";*/
    //testare ^ ^ ^
    if(j<nrStr1)
    {
        //c=functie din baza de date care returneaza sub forma de QString o intrare rutier
        c = Rutier.readQuery("RUTIER", indici[0]);
        inputStr[j].n[0]=0;
        indici[0]++;
    }
    else
    {
        if(j<nrStr2)
        {
            //c=functie din baza de date care returneaza sub forma de QString o intrare depozitare
            c = Depozitare.readQuery("DEPOZITARE", indici[1]);
            inputStr[j].n[0]=1;
            indici[1]++;
        }
        else
        {
            if(j<nrStr3)
            {
                //c=functie din baza de date care returneaza sub forma de QString o intrare maritim
                c = Maritim.readQuery("MARITIM", indici[2]);
                inputStr[j].n[0]=2;
                indici[2]++;
            }
            else
            {
                if(j<nrStr4)
                {
                    //c=functie din baza de date care returneaza sub forma de QString o intrare aerian
                    c = Aerian.readQuery("AERIAN", indici[3]);
                    inputStr[j].n[0]=3;
                    indici[3]++;
                }
                else
                {
                    if(j<nrStr5)
                    {
                        //c=functie din baza de date care returneaza sub forma de QString o intrare feroviar
                        c = Feroviar.readQuery("FEROVIAR", indici[4]);
                        inputStr[j].n[0]=4;
                        indici[4]++;
                    }
                }
            }
        }
    }
    size=c.size();
    inputStr[j].n[1]=0;
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
                    if(c[i]=='.')
                    {
                        if(c[i+1]!='\'')
                        {
                            inputStr[j].n[1]=inputStr[j].n[1]+c[i+1].unicode()-48;
                            i++;
                        }
                        if(c[i+2]!='\'')
                        {
                            inputStr[j].n[1]=inputStr[j].n[1]*10;
                            inputStr[j].n[1]=inputStr[j].n[1]+c[i+2].unicode()-48;
                            i++;
                        }
                        continue;
                    }
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
