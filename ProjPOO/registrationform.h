#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QMainWindow>
#include <usermanager.h>
#include <operations.h>
#include <QDebug>
#include <QTimer>
#include<personal.h>
#include <QDesktopWidget>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QMainWindow
{
    Q_OBJECT

public:
    QRect position ;
    explicit RegistrationForm(QMainWindow *qm, QWidget *parent = 0);
    ~RegistrationForm();

private slots:
    void cancelButton();
    void registerUser();
    void redirect();

    void on_pushButton_clicked();

private:
    Ui::RegistrationForm *ui;
    QMainWindow *startWindow;
    personal *personalForm;
};

#endif // REGISTRATIONFORM_H
