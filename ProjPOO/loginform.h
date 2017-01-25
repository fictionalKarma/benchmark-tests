#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QMainWindow>
#include <usermanager.h>
#include <principalform.h>
#include <administrator.hpp>
#include <QFile>
#include <log.hpp>
#include <tree.hpp>
#include <firma.hpp>
#include "objective.hpp"

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
    Log *logger;
};

#endif // LOGINFORM_H
