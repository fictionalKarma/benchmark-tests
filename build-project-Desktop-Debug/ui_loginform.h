/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

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

class Ui_LoginForm
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *mainGrid;
    QPushButton *loginBtn;
    QPushButton *cancelBtn;
    QLineEdit *passTb;
    QLabel *label_2;
    QLineEdit *nameTb;
    QLabel *label;
    QLabel *wrongLbl;

    void setupUi(QMainWindow *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->setWindowModality(Qt::NonModal);
        LoginForm->resize(212, 221);
        LoginForm->setStyleSheet(QLatin1String("LoginForm {\n"
"background: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop: 0.534091 rgba(226, 226, 226, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        centralwidget = new QWidget(LoginForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 191, 221));
        mainGrid = new QGridLayout(gridLayoutWidget);
        mainGrid->setObjectName(QStringLiteral("mainGrid"));
        mainGrid->setContentsMargins(0, 0, 0, 0);
        loginBtn = new QPushButton(gridLayoutWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background: lightgray;\n"
"	border: 1px solid black;\n"
"	border-radius: 10px;\n"
"	height:30px;\n"
"}\n"
"QPushButton#cancelBtn:hover {\n"
"	background: rgba(240, 240, 240, 1);\n"
"}"));

        mainGrid->addWidget(loginBtn, 5, 0, 1, 1);

        cancelBtn = new QPushButton(gridLayoutWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background: lightgray;\n"
"	border: 1px solid black;\n"
"	border-radius: 10px;\n"
"	height:30px;\n"
"}\n"
"QPushButton#cancelBtn:hover {\n"
"	background: rgba(240, 240, 240, 1);\n"
"}"));

        mainGrid->addWidget(cancelBtn, 5, 1, 1, 1);

        passTb = new QLineEdit(gridLayoutWidget);
        passTb->setObjectName(QStringLiteral("passTb"));
        QFont font;
        font.setPointSize(15);
        passTb->setFont(font);
        passTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border: 1px solid black;\n"
"	border-radius: 10px;\n"
"}"));
        passTb->setEchoMode(QLineEdit::Password);

        mainGrid->addWidget(passTb, 4, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        mainGrid->addWidget(label_2, 3, 0, 1, 2);

        nameTb = new QLineEdit(gridLayoutWidget);
        nameTb->setObjectName(QStringLiteral("nameTb"));
        nameTb->setFont(font);
        nameTb->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border: 1px solid black;\n"
"	border-radius: 10px;\n"
"}"));

        mainGrid->addWidget(nameTb, 2, 0, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        mainGrid->addWidget(label, 1, 0, 1, 2);

        wrongLbl = new QLabel(gridLayoutWidget);
        wrongLbl->setObjectName(QStringLiteral("wrongLbl"));
        QFont font1;
        font1.setItalic(true);
        wrongLbl->setFont(font1);
        wrongLbl->setStyleSheet(QLatin1String("color: rgba(0, 0, 0, 0);\n"
""));
        wrongLbl->setAlignment(Qt::AlignCenter);

        mainGrid->addWidget(wrongLbl, 7, 0, 1, 2);

        LoginForm->setCentralWidget(centralwidget);
        QWidget::setTabOrder(nameTb, passTb);
        QWidget::setTabOrder(passTb, loginBtn);
        QWidget::setTabOrder(loginBtn, cancelBtn);

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QMainWindow *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Log in", 0));
        loginBtn->setText(QApplication::translate("LoginForm", "Log in", 0));
        cancelBtn->setText(QApplication::translate("LoginForm", "Cancel", 0));
        label_2->setText(QApplication::translate("LoginForm", "Password", 0));
        label->setText(QApplication::translate("LoginForm", "Username", 0));
        wrongLbl->setText(QApplication::translate("LoginForm", "Incorrect username or password", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
