#include "procesop.h"
#include "ui_procesop.h"
#include "table.h"
#include <QDebug>
procesop::procesop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::procesop)
{
    //Depozitare =new Table;
    ui->setupUi(this);
    //Rutier.createTable("RUTIER", "DATA TEXT, RESPECTARE_INCARCARE BOOLEAN, RESPECTARE_DESCARCARE BOOLEAN, RATA_DAUNE_LIPSURI REAL, CONFORMITATE_EXHIPAMENT BOOLEAN, RATA_ANUNT_INTARZIERI REAL, NR_DOSARE_TRANSPORT_PERSOANE_ZI INT, RATA_KM_PARCURSI INT, GRAD_INCARCARE_DISTRIBUTIE REAL, PROFIT_BRUT REAL, RATA_SUCCES_LICITATII REAL, DSO REAL, DPO REAL");
    //Depozitare.createTable("DEPOZITARE", "DATA TEXT, RESPECTARE_LIMITE_COMANDA BOOLEAN, ACURATETE_PREGATIRE_COMENZI REAL, RATA_DAUNE_LIPSURI REAL, ACURATETE_STOC REAL, GRAD_OCUPARE_DEPOZIT REAL, DSO REAL, DPO REAL");
    //Maritim.createTable("MARITIM", "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");
    //Aerian.createTable("AERIAN",   "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");
    //Feroviar.createTable("FEROVIAR", "DATA TEXT, RESPECTARE_INCARCARE TEXT, RESPECTARE_DESCARCARE TEXT, RATA_DAUNE_LIPSURI TEXT, CONFORMITATE_EXHIPAMENT TEXT, RATA_ANUNT_INTARZIERI TEXT, NR_DOSARE_TRANSPORT_PERSOANE_ZI, RATA_KM_PARCURSI TEXT, GRAD_INCARCARE_DISTRIBUTIE TEXT, PROFIT_BRUT TEXT, RATA_SUCCES_LICITATII TEXT, DSO TEXT, DPO TEXT");

}


procesop::~procesop()
{
    delete ui;
}

void procesop::on_pushButton_2_clicked()
{

    editare=0;
    close();
}
void procesop::on_pushButton_clicked()
{
    QString data;
    std::map<QString,float> floatValues;
    std::map<QString, bool> boolValues;
    if(ui->comboBox->currentIndex()==1)
    {


        //PT DEPOZITARE

        floatValues.clear();
        boolValues.clear();
        data=ui->dateEdit->text();
        bool respectare_limite_comanda=ui->respecatare_termene_preg_check->isChecked();
        floatValues.insert(std::pair<QString,float>("acuratete_preg_comenzi",ui->acuratete_preg_comenzi_edit->toPlainText().toFloat()));
        floatValues.insert(std::pair<QString,float>("rata_daune",ui->rata_daune_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("acuratete_stoc",ui->acuratetete_stoc_edit->toPlainText().toFloat()));
        floatValues.insert(std::pair<QString,float>("grad_ocupare_depozit",ui->grad_ocupare_depozit_edit->toPlainText().toFloat()));
        floatValues.insert(std::pair<QString,float>("dso",ui->dso_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("dpo",ui->dpo_edit->text().toFloat()));

        //---------------
        //Se introduce functia care preia QString input si adauga informatia in baza de date (proces depozitare)
        //qDebug()<<stringValues["data"];
        Depozitare.insertQuery("DEPOZITARE",data,floatValues,respectare_limite_comanda);
        //Depozitare.readQuery("DEPOZITARE",12); <--just for tests


    }
    if(ui->comboBox->currentIndex()==0)
    {

        floatValues.clear();
        boolValues.clear();
       data=ui->dateEdit->text();
        boolValues.insert(std::pair<QString,bool>("respectare_termene_incarcare",ui->termene_incaracare_check->isChecked()));
        boolValues.insert(std::pair<QString,bool>("respectare_termene_descarcare",ui->termene_descarcare_check->isChecked()));
        floatValues.insert(std::pair<QString,float>("rata_daune",ui->rata_daune_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("rata_anunt_intarzieri",ui->rata_anunt_intarzieri_edit->text().toFloat()));
        boolValues.insert(std::pair<QString,bool>("conformitate_echipament",ui->conformitate_echipament_check->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("nr_dosare",ui->nr_transport_doasare_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("rata_km",ui->rata_km_parcursi_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("grad_incarcare_distributie",ui->grad_incarcare_distributie_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("profit_brut",ui->profit_brut_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("rata_succes_licitatii",ui->rata_succes_licitatii_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("dso",ui->dso_edit->text().toFloat()));
        floatValues.insert(std::pair<QString,float>("dpo",ui->dpo_edit->text().toFloat()));
        Rutier.insertQuery("RUTIER",data,floatValues,boolValues);

    }


}

void procesop::on_comboBox_activated(int index)
{
    if(index==1)
    {
       ui->respecatare_termene_preg_check->setEnabled(true);
       ui->termene_incaracare_check->setEnabled(false);
       ui->termene_descarcare_check->setEnabled(false);
       ui->rata_daune_edit->setEnabled(true);
       ui->conformitate_echipament_check->setEnabled(false);
       ui->rata_anunt_intarzieri_edit->setEnabled(false);
       ui->nr_transport_doasare_edit->setEnabled(false);
       ui->rata_km_parcursi_edit->setEnabled(false);
       ui->grad_incarcare_distributie_edit->setEnabled(false);
       ui->profit_brut_edit->setEnabled(false);
       ui->rata_succes_licitatii_edit->setEnabled(false);
       ui->acuratete_preg_comenzi_edit->setEnabled(true);
       ui->rata_daune_depozit_edit->setEnabled(true);
       ui->acuratetete_stoc_edit->setEnabled(true);
       ui->grad_ocupare_depozit_edit->setEnabled(true);
       ui->disponibilitate_personal_depozit_edit->setEnabled(false);
       ui->dso_edit->setEnabled(true);
       ui->dpo_edit->setEnabled(true);

    }
    if(index==0)
    {
        foreach(QWidget *wid,this->findChildren<QWidget*>())
            wid->setEnabled(true);
        ui->respecatare_termene_preg_check->setEnabled(false);
        ui->acuratete_preg_comenzi_edit->setEnabled(false);
        ui->rata_daune_depozit_edit->setEnabled(false);
        ui->acuratetete_stoc_edit->setEnabled(false);
        ui->grad_ocupare_depozit_edit->setEnabled(false);
        ui->disponibilitate_personal_depozit_edit->setEnabled(false);

    }

}

void procesop::on_pushButton_3_clicked()
{

}

void procesop::on_pushButton_4_clicked()
{

}

void procesop::on_pushButton_5_clicked()
{

}
