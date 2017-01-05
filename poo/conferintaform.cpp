#include "conferintaform.h"
#include "ui_conferintaform.h"
#include <QMessageBox>

conferintaForm::conferintaForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::conferintaForm)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ui->graphics_View_table->setScene(scene);

    drawElipse();

}
void conferintaForm::drawElipse()
{
  scene->clear();
    elipse=scene->addEllipse(ui->graphics_View_table->width()/14,ui->graphics_View_table->height()/14,ui->graphics_View_table->width()*1.4,ui->graphics_View_table->height()*1.4,pen,brush);

}

conferintaForm::~conferintaForm()
{
    delete ui;
}

void conferintaForm::on_conferintaForm_iconSizeChanged(const QSize &iconSize)//nu merge asta
{
    drawElipse();
    QMessageBox msg;
    msg.setText("ceva");
    msg.exec();
}
