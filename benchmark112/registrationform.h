#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QMainWindow>
#include <usermanager.h>
#include <operations.h>
#include <QDebug>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistrationForm(QMainWindow *qm, QWidget *parent = 0);
    ~RegistrationForm();

private slots:
    void cancelButton();
    void registerUser();

private:
    Ui::RegistrationForm *ui;
    QMainWindow *startWindow;
};

#endif // REGISTRATIONFORM_H
