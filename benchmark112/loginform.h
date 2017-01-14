#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QMainWindow>
#include <usermanager.h>
#include <principalform.h>

namespace Ui {
class LoginForm;
}

class LoginForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginForm(QMainWindow *qm, QWidget *parent = 0);
    ~LoginForm();
private slots:
    bool checkAuth();
    void onTextChanged();
    void cancelButton();

private:
    Ui::LoginForm *ui;
    QMainWindow *startWindow;
    principalForm *pr;
};

#endif // LOGINFORM_H
