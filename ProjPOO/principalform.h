#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QMainWindow>
#include <conferintaform.h>

namespace Ui {
class principalForm;
}

class principalForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit principalForm(QWidget *parent = 0);
    ~principalForm();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::principalForm *ui;
    conferintaForm *conf;
};

#endif // PRINCIPALFORM_H
