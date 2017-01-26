#include "buget.h"
#include "ui_buget.h"

buget::buget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buget)
{
    ui->setupUi(this);
   // Buget.createTable("BUGET","DATA TEXT, BUGET TEXT, CIFRA_AFACERI REAL, COST_CUMPARARE REAL, COST_PERSONAL REAL, COST_TEHNOLOGIE REAL, COST_INFRASTRUCTURA REAL, COST_INVESTITII REAL, COST_RUTIER REAL, COST_DEPOZITARE REAL");
  //  Buget.tableSize("BUGET");
}

buget::~buget()
{
    delete ui;
}

void buget::on_pushButton_clicked()
{
    std::map<QString,float> floatValues;
    floatValues.insert(std::pair<QString,float>("ca",ui->ca_edit->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costCumparare",ui->cc_edit->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costPersonal",ui->costuri_personal_edit->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costTehnologie",ui->costuri_tehnologie_edit->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costInfrastructura",ui->costuri_infrastructura_edit->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costInvestitii",ui->costuri_infrastructura_edit->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costRutier",ui->cost_procesRutier->toPlainText().toFloat()));
    floatValues.insert(std::pair<QString,float>("costDepozitare",ui->costProces_depozitare->toPlainText().toFloat()));

    Buget.insertQuery(floatValues,ui->dateEdit->text(),ui->buget_combo->currentText());

}
void buget::on_pushButton_2_clicked()
{
    delete ui;
    this->close();
   /* foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
    {
        widget->clear();
    }
    foreach(QComboBox *widget, this->findChildren<QComboBox*>())
    {
        widget->setCurrentIndex(0);
    }
    editare=0;
    indiceIntrare=0;
    ui->pushButton_4->setEnabled(0);
    ui->pushButton_3->setEnabled(0);
    close();*/
}
void buget::on_pushButton_5_clicked()
{
   /* editare=1;
    for(int j=0;j<Buget.tableSize("BUGET");j++)
    {
        for(int i=0;i<12;i++)
            inputStr[j].text[i]="";
        for(int i=0;i<2;i++)
            inputStr[j].n[i]=0;
    }
    ui->pushButton_4->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    int k,m,size;
    QString c;
    //nrStr=functie din baza de date care returneaza numarul de intrari
    //Buget.updateQuery("BUGET","'2013.0',0,'intr1','','','','','','','','','',''",0);
    //nrStr = Buget.tableSize("BUGET");
    QString filename=("D:\\ProjPOO\\personal.txt");
        QFile personal(filename);
        personal.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QTextStream persout(&personal);
        //persout<<nrStr<<"size"<<endl;
    nrStr=Buget.tableSize("BUGET");
    for(int j=0;j<nrStr;j++){
    k=0;
    m=0;
    //QString c=functie din baza de date care returneaza sub forma de QString o intrare
    //testare v v v
    c = Buget.readQuery("BUGET", j);
    if(j==0)
        c="'CNP1','nume1','email1','facultate1','filiala1',1,'adresa1',0,3,'salariu1',2,4,2,4,4,4,2,3,4,4,4,2,4,1,2,0,2,0,0,2,0,0";
    if(j==1)
        c="'CNP2','nume2','email2','facultate2','filiala2',2,'adresa2',1,1,'salariu2',0,1,4,0,1,4,4,2,4,0,3,4,2,4,0,0,2,2,2,2,2,0";
    //testare ^ ^ ^
    size=c.size();
    inputStr[j].n[0]=0;
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
                            inputStr[j].n[0]=inputStr[j].n[0]+c[i+1].unicode()-48;
                            i++;
                        }
                        if(c[i+1]!='\'')
                        {
                            inputStr[j].n[0]=inputStr[j].n[0]*10;
                            inputStr[j].n[0]=inputStr[j].n[0]+c[i+1].unicode()-48;
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
            inputStr[j].n[1]=c[i].unicode()-48;
            i++;
            m++;
        }
    }
    }*/
}

void buget::on_pushButton_4_clicked()
{
   /* if(indiceIntrare+1==nrStr)
        indiceIntrare=nrStr-1;
    else
        indiceIntrare++;
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
    ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[0]);   */
}

void buget::on_pushButton_3_clicked()
{
   /* if(indiceIntrare-1==-1)
        indiceIntrare=0;
    else
        indiceIntrare--;
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
    ui->comboBox_2->setCurrentIndex(inputStr[indiceIntrare].n[0]);  */
}

void buget::on_pushButton_8_clicked()
{
    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>())
    {
        widget->clear();
    }
    foreach(QComboBox *widget, this->findChildren<QComboBox*>())
    {
        widget->setCurrentIndex(0);
    }
}

//void buget::on_pushButton_6_clicked()
//{
    //cautare
    /*crit.n[0]=ui->comboBox_2->currentIndex();
    crit.n[1]=ui->comboBox->currentIndex();
    crit.text[0]=ui->textEdit->toPlainText();
    crit.text[1]=ui->textEdit_2->toPlainText();
    crit.text[2]=ui->textEdit_3->toPlainText();
    crit.text[3]=ui->textEdit_4->toPlainText();
    crit.text[4]=ui->textEdit_5->toPlainText();
    crit.text[5]=ui->textEdit_6->toPlainText();
    crit.text[6]=ui->textEdit_7->toPlainText();
    crit.text[7]=ui->textEdit_8->toPlainText();
    crit.text[8]=ui->textEdit_9->toPlainText();
    crit.text[9]=ui->textEdit_10->toPlainText();
    crit.text[10]=ui->textEdit_11->toPlainText();
    crit.text[11]=ui->textEdit_12->toPlainText();*/
//}

void buget::on_pushButton_7_clicked()
{
    //stergere

}
