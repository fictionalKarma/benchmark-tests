/********************************************************************************
** Form generated from reading UI file 'registrationform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONFORM_H
#define UI_REGISTRATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationForm
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *mainGrid;
    QLineEdit *passTb;
    QLabel *label_2;
    QLineEdit *emailconfTb;
    QPushButton *regBtn;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *userTb;
    QLineEdit *passcTb;
    QPushButton *cancelBtn;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *emailTb;
    QLabel *userError;
    QLabel *passError;
    QLabel *emcoError;
    QLabel *emError;
    QLabel *confError;

    void setupUi(QMainWindow *RegistrationForm)
    {
        if (RegistrationForm->objectName().isEmpty())
            RegistrationForm->setObjectName(QStringLiteral("RegistrationForm"));
        RegistrationForm->resize(391, 286);
        RegistrationForm->setStyleSheet(QLatin1String("RegistrationForm {\n"
"background: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop: 0.534091 rgba(226, 226, 226, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        centralwidget = new QWidget(RegistrationForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 271));
        mainGrid = new QGridLayout(gridLayoutWidget);
        mainGrid->setObjectName(QStringLiteral("mainGrid"));
        mainGrid->setContentsMargins(0, 0, 0, 0);
        passTb = new QLineEdit(gridLayoutWidget);
        passTb->setObjectName(QStringLiteral("passTb"));
        passTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));
        passTb->setEchoMode(QLineEdit::Password);

        mainGrid->addWidget(passTb, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        mainGrid->addWidget(label_2, 2, 0, 1, 1);

        emailconfTb = new QLineEdit(gridLayoutWidget);
        emailconfTb->setObjectName(QStringLiteral("emailconfTb"));
        emailconfTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));

        mainGrid->addWidget(emailconfTb, 8, 1, 1, 1);

        regBtn = new QPushButton(gridLayoutWidget);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-radius:5px;\n"
"	background: rgba(200, 200, 200, 1);\n"
" 	height: 25px;\n"
"	border: 1px solid black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background:rgba(240, 240, 240, 1);\n"
"}"));

        mainGrid->addWidget(regBtn, 10, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        mainGrid->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        mainGrid->addWidget(label_3, 4, 0, 1, 1);

        userTb = new QLineEdit(gridLayoutWidget);
        userTb->setObjectName(QStringLiteral("userTb"));
        userTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));

        mainGrid->addWidget(userTb, 0, 1, 1, 1);

        passcTb = new QLineEdit(gridLayoutWidget);
        passcTb->setObjectName(QStringLiteral("passcTb"));
        passcTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));
        passcTb->setEchoMode(QLineEdit::Password);

        mainGrid->addWidget(passcTb, 4, 1, 1, 1);

        cancelBtn = new QPushButton(gridLayoutWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	border-radius:5px;\n"
"	background: rgba(200, 200, 200, 1);\n"
" 	height: 25px;\n"
"	border: 1px solid black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background:rgba(240, 240, 240, 1);\n"
"}"));

        mainGrid->addWidget(cancelBtn, 10, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        mainGrid->addWidget(label_4, 6, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        mainGrid->addWidget(label_5, 8, 0, 1, 1);

        emailTb = new QLineEdit(gridLayoutWidget);
        emailTb->setObjectName(QStringLiteral("emailTb"));
        emailTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));

        mainGrid->addWidget(emailTb, 6, 1, 1, 1);

        userError = new QLabel(gridLayoutWidget);
        userError->setObjectName(QStringLiteral("userError"));
        userError->setStyleSheet(QStringLiteral("color: rgba(0, 0, 0, 0);"));
        userError->setAlignment(Qt::AlignCenter);

        mainGrid->addWidget(userError, 1, 0, 1, 2);

        passError = new QLabel(gridLayoutWidget);
        passError->setObjectName(QStringLiteral("passError"));
        passError->setStyleSheet(QStringLiteral("color: rgba(0, 0, 0, 0);"));
        passError->setAlignment(Qt::AlignCenter);

        mainGrid->addWidget(passError, 3, 0, 1, 2);

        emcoError = new QLabel(gridLayoutWidget);
        emcoError->setObjectName(QStringLiteral("emcoError"));
        emcoError->setStyleSheet(QStringLiteral("color: rgba(0, 0, 0, 0);"));
        emcoError->setAlignment(Qt::AlignCenter);

        mainGrid->addWidget(emcoError, 9, 0, 1, 2);

        emError = new QLabel(gridLayoutWidget);
        emError->setObjectName(QStringLiteral("emError"));
        emError->setStyleSheet(QStringLiteral("color: rgba(0, 0, 0, 0);"));
        emError->setAlignment(Qt::AlignCenter);

        mainGrid->addWidget(emError, 7, 0, 1, 2);

        confError = new QLabel(gridLayoutWidget);
        confError->setObjectName(QStringLiteral("confError"));
        confError->setStyleSheet(QStringLiteral("color: rgba(0, 0, 0, 0);"));
        confError->setAlignment(Qt::AlignCenter);

        mainGrid->addWidget(confError, 5, 0, 1, 2);

        RegistrationForm->setCentralWidget(centralwidget);
        QWidget::setTabOrder(userTb, passTb);
        QWidget::setTabOrder(passTb, passcTb);
        QWidget::setTabOrder(passcTb, emailTb);
        QWidget::setTabOrder(emailTb, emailconfTb);
        QWidget::setTabOrder(emailconfTb, regBtn);
        QWidget::setTabOrder(regBtn, cancelBtn);

        retranslateUi(RegistrationForm);

        QMetaObject::connectSlotsByName(RegistrationForm);
    } // setupUi

    void retranslateUi(QMainWindow *RegistrationForm)
    {
        RegistrationForm->setWindowTitle(QApplication::translate("RegistrationForm", "Registry Form", 0));
        label_2->setText(QApplication::translate("RegistrationForm", "Password", 0));
        regBtn->setText(QApplication::translate("RegistrationForm", "Register", 0));
        label->setText(QApplication::translate("RegistrationForm", "Username", 0));
        label_3->setText(QApplication::translate("RegistrationForm", "Confirm Pass.", 0));
        cancelBtn->setText(QApplication::translate("RegistrationForm", "Cancel", 0));
        label_4->setText(QApplication::translate("RegistrationForm", "E-Mail", 0));
        label_5->setText(QApplication::translate("RegistrationForm", "Confirm E-Mail", 0));
        userError->setText(QApplication::translate("RegistrationForm", "TextLabel", 0));
        passError->setText(QApplication::translate("RegistrationForm", "TextLabel", 0));
        emcoError->setText(QApplication::translate("RegistrationForm", "TextLabel", 0));
        emError->setText(QApplication::translate("RegistrationForm", "TextLabel", 0));
        confError->setText(QApplication::translate("RegistrationForm", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class RegistrationForm: public Ui_RegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONFORM_H
