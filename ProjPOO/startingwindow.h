#ifndef STARTINGWINDOW_H
#define STARTINGWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "loginform.h"
#include "registrationform.h"

namespace Ui {
class StartingWindow;
}

class StartingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartingWindow(QWidget *parent = 0);
    ~StartingWindow();

private slots:
    void launchLoginForm();
    void launchSignUp();

private:
    Ui::StartingWindow *ui;
    LoginForm *log;
    RegistrationForm *reg;
};

#endif // STARTINGWINDOW_H
