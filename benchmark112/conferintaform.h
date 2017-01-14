#ifndef CONFERINTAFORM_H
#define CONFERINTAFORM_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
namespace Ui {
class conferintaForm;
}

class conferintaForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit conferintaForm(QWidget *parent = 0);
    void drawElipse();
    ~conferintaForm();

private slots:
    void on_conferintaForm_iconSizeChanged(const QSize &iconSize);

private:
    Ui::conferintaForm *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *elipse;
    QPen pen;
    QBrush brush;
   // conferintaForm *conf;
};

#endif // CONFERINTAFORM_H
