#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QMainWindow>
#include <usermanager.h>
#include <operations.h>
#include <QTimer>
#include <loghandler.hpp>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>

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
    void redirect();
    void updateTrans();

private:
    Ui::RegistrationForm *ui;
    QMainWindow *startWindow;
    Log logger;
    QLineEdit *textBoxes;
    QLabel *tbLabels;
    QComboBox *combos;
    QCheckBox *checks;
    QMap<QString, QString> map;
    QMap<QString, QString> userData;
    void sendConfirmationMail();
    void initializeComponents();
    void getUserData();
};

#endif // REGISTRATIONFORM_H
