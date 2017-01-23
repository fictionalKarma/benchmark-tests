#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QMainWindow>
#include "user.h"
#include "administrator.hpp"

namespace Ui {
class principalForm;
}

class principalForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit principalForm(QWidget *parent = 0);
    explicit principalForm(User *u, QWidget *parent = 0);
    explicit principalForm(Administrator *a, QWidget *parent = 0);
    ~principalForm();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::principalForm *ui;
    User currentUser;
    Administrator admin;
};

#endif // PRINCIPALFORM_H
