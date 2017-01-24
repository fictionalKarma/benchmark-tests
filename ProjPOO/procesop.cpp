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
    ui->pushButton_4->setEnabled(0);
    ui->pushButton_3->setEnabled(0);
    editare=0;
    close();
}
void procesop::on_pushButton_clicked()
{
    QString input,test,test2;
    int choice = 0,proc;
    int testsize,adaugat=0,j;
    if(ui->comboBox->currentIndex()==1)
    {
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
    }
    else
    {
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
    }
    if(editare==0)
    {
        if(ui->comboBox->currentIndex()==1)
            //Se introduce functia care preia QString input si adauga informatia in baza de date (proces depozitare)
            Depozitare.insertQuery("DEPOZITARE", input);
        if(choice==1)
            if(ui->comboBox->currentIndex()==0)
            {
                //Se introduce functia care preia QString input si adauga informatia in baza de date (proces rutier)
                Rutier.insertQuery("RUTIER", input);
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
    if(editare==1)
    {
        adaugat=0;
        int nr;
        if(ui->comboBox->currentIndex()==0)
        {
            nr=Rutier.tableSize("RUTIER");
            proc=0;
        }
        if(ui->comboBox->currentIndex()==0)
        {
            nr=1*strsize+Depozitare.tableSize("DEPOZITARE");
            proc=1;
        }
        if(ui->comboBox->currentIndex()==0)
        {
            nr=2*strsize+Maritim.tableSize("MARITIM");
            proc=2;
        }
        if(ui->comboBox->currentIndex()==0)
        {
            nr=3*strsize+Aerian.tableSize("AERIAN");
            proc=3;
        }
        if(ui->comboBox->currentIndex()==0)
        {
            nr=4*strsize+Feroviar.tableSize("FEROVIAR");
            proc=4;
        }
        for(int i=proc*strsize;i<nr;i++)
        {
            test2="";
            test2+=inputStr[i].text[0];
            test2+='.';
            test2+=QVariant(inputStr[i].n[0]).toString();
            //persout<<test2<<" "<<test<<endl;
            if(test.size()==test2.size())
            {
                testsize=test.size();
                for(j=0;j<testsize;j++)
                {
                    if(test[j]!=test2[j])
                        break;
                }
                if(j==testsize)
                {
                    adaugat=1;
                    //update query
                    if(proc==0)
                        Rutier.updateQuery("RUTIER", input,i);
                    else
                    {
                        if(proc==1)
                            Depozitare.updateQuery("DEPOZITARE", input,i);
                        else
                        {
                            if(proc==2)
                                Maritim.updateQuery("MARITIM", input,i);
                            else
                            {
                                if(proc==3)
                                    Aerian.updateQuery("AERIAN", input,i);
                                else
                                {
                                    if(proc==4)
                                        Feroviar.updateQuery("FEROVIAR", input,i);
                                }
                            }
                        }
                    }
                    break;
                }
            }
         }
        if(adaugat==0)
        {
            if(proc==0)
                Rutier.insertQuery("RUTIER", input);
            else
            {
                if(proc==1)
                    Depozitare.insertQuery("DEPOZITARE", input);
                else
                {
                    if(proc==2)
                        Maritim.insertQuery("MARITIM", input);
                    else
                    {
                        if(proc==3)
                            Aerian.insertQuery("AERIAN", input);
                        else
                        {
                            if(proc==4)
                                Feroviar.insertQuery("FEROVIAR", input);
                        }
                    }
                }
            }
        }
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
    int k=0;
    if(indiceIntrare-1==4*strsize-1)
    {indiceIntrare=3*strsize+nrStr4;k=1;}
    if(indiceIntrare+1==3*strsize-1)
    {indiceIntrare=2*strsize+nrStr3;k=1;}
    if(indiceIntrare+1==2*strsize-1)
    {indiceIntrare=1*strsize+nrStr2;k=1;}
    if(indiceIntrare+1==1*strsize-1)
    {indiceIntrare=nrStr1;k=1;}
    if(indiceIntrare-1==-1)
    {indiceIntrare=indiceIntrare;k=1;}
    if(k==0)
        indiceIntrare--;
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
   if(inputStr[indiceIntrare].n[0]==0)
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
       ui->textEdit_7->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_8->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[11]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[12]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(1);
       ui->textEdit_8->setEnabled(1);
   }
   if(inputStr[indiceIntrare].n[0]==2)
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
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(0);
       ui->textEdit_8->setEnabled(0);
   }
   if(inputStr[indiceIntrare].n[0]==3)
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
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(0);
       ui->textEdit_8->setEnabled(0);
   }
   if(inputStr[indiceIntrare].n[0]==4)
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
       ui->textEdit_7->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_8->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[11]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[12]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(1);
       ui->textEdit_8->setEnabled(1);
   }
}

void procesop::on_pushButton_4_clicked()
{
    int k=0;
    if(indiceIntrare+1==nrStr1)
    {indiceIntrare=60;k=1;}
    if(indiceIntrare+1==nrStr2+1*strsize)
    {indiceIntrare=120;k=1;}
    if(indiceIntrare+1==nrStr3+2*strsize)
    {indiceIntrare=180;k=1;}
    if(indiceIntrare+1==nrStr4+3*strsize)
    {indiceIntrare=240;k=1;}
    if(indiceIntrare+1==nrStr5+4*strsize)
    {indiceIntrare=indiceIntrare;k=1;}
    if(k==0)
        indiceIntrare++;
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
   if(inputStr[indiceIntrare].n[0]==0)
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
       ui->textEdit_7->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_8->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[11]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[12]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(1);
       ui->textEdit_8->setEnabled(1);
   }
   if(inputStr[indiceIntrare].n[0]==2)
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
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(0);
       ui->textEdit_8->setEnabled(0);
   }
   if(inputStr[indiceIntrare].n[0]==3)
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
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(0);
       ui->textEdit_8->setEnabled(0);
   }
   if(inputStr[indiceIntrare].n[0]==4)
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
       ui->textEdit_7->setText(inputStr[indiceIntrare].text[7]);
       ui->textEdit_8->setText(inputStr[indiceIntrare].text[8]);
       ui->textEdit_9->setText(inputStr[indiceIntrare].text[9]);
       ui->textEdit_10->setText(inputStr[indiceIntrare].text[10]);
       ui->textEdit_17->setText(inputStr[indiceIntrare].text[11]);
       ui->textEdit_18->setText(inputStr[indiceIntrare].text[12]);
       ui->textEdit->setEnabled(1);
       ui->textEdit_2->setEnabled(1);
       ui->textEdit_3->setEnabled(1);
       ui->textEdit_4->setEnabled(1);
       ui->textEdit_5->setEnabled(1);
       ui->textEdit_6->setEnabled(1);
       ui->textEdit_9->setEnabled(1);
       ui->textEdit_10->setEnabled(1);
       ui->textEdit_11->setEnabled(0);
       ui->textEdit_12->setEnabled(0);
       ui->textEdit_13->setEnabled(0);
       ui->textEdit_14->setEnabled(0);
       ui->textEdit_15->setEnabled(0);
       ui->textEdit_16->setEnabled(0);
       ui->textEdit_7->setEnabled(1);
       ui->textEdit_8->setEnabled(1);
   }
}

void procesop::on_pushButton_5_clicked()
{
    editare=1;
    ui->pushButton_4->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    int k,m,p,size,indici[5]={0,0,0,0,0};
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
    p=j;
    //c=functie din baza de date care returneaza sub forma de QString o intrare (orice format)
    //testare v v v
    /*if(j==0)
        c="'CNP1','nume1','email1','facultate1','filiala1',1,'adresa1',0,3,'salariu1',2,4,2,4,4,4,2,3,4,4,4,2,4,1,2,0,2,0,0,2,0,0";
    if(j==1)
        c="'CNP2','nume2','email2','facultate2','filiala2',2,'adresa2',1,1,'salariu2',0,1,4,0,1,4,4,2,4,0,3,4,2,4,0,0,2,2,2,2,2,0";*/
    //testare ^ ^ ^
    if(p<nrStr1)
    {
        //c=functie din baza de date care returneaza sub forma de QString o intrare rutier
        c = Rutier.readQuery("RUTIER", indici[0]);
        inputStr[j].n[0]=0;
        indici[0]++;
        j=p;
    }
    else
    {
        if(p<nrStr2)
        {
            //c=functie din baza de date care returneaza sub forma de QString o intrare depozitare
            c = Depozitare.readQuery("DEPOZITARE", indici[1]);
            inputStr[j*1*strsize].n[0]=1;
            indici[1]++;
            j=p+1*strsize;
        }
        else
        {
            if(p<nrStr3)
            {
                //c=functie din baza de date care returneaza sub forma de QString o intrare maritim
                c = Maritim.readQuery("MARITIM", indici[2]);
                inputStr[j*2*strsize].n[0]=2;
                indici[2]++;
                j=p+2*strsize;
            }
            else
            {
                if(p<nrStr4)
                {
                    //c=functie din baza de date care returneaza sub forma de QString o intrare aerian
                    c = Aerian.readQuery("AERIAN", indici[3]);
                    inputStr[j*3*strsize].n[0]=3;
                    indici[3]++;
                    j=p+3*strsize;
                }
                else
                {
                    if(p<nrStr5)
                    {
                        //c=functie din baza de date care returneaza sub forma de QString o intrare feroviar
                        c = Feroviar.readQuery("FEROVIAR", indici[4]);
                        inputStr[j*4*strsize].n[0]=4;
                        indici[4]++;
                        j=p+4*strsize;
                    }
                }
            }
        }
    }
    size=c.size();
    for(int i=0;i<19;i++)
        inputStr[j].text[i]="";
    for(int i=0;i<2;i++)
        inputStr[j].n[i]=0;
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
                        if(c[i+1]!='\'')
                        {
                            inputStr[j].n[1]=inputStr[j].n[1]*10;
                            inputStr[j].n[1]=inputStr[j].n[1]+c[i+1].unicode()-48;
                            i++;
                        }
                        i++;
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
    }
    j=p;
    }
}
