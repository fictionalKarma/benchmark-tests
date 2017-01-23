/********************************************************************************
** Form generated from reading UI file 'startingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTINGWINDOW_H
#define UI_STARTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartingWindow
{
public:
    QWidget *centralWidget;
    QPushButton *loginBtn;
    QPushButton *signupBtn;
    QLabel *label;

    void setupUi(QMainWindow *StartingWindow)
    {
        if (StartingWindow->objectName().isEmpty())
            StartingWindow->setObjectName(QStringLiteral("StartingWindow"));
        StartingWindow->resize(241, 241);
        centralWidget = new QWidget(StartingWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loginBtn = new QPushButton(centralWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(0, 0, 241, 111));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        loginBtn->setFont(font);
        signupBtn = new QPushButton(centralWidget);
        signupBtn->setObjectName(QStringLiteral("signupBtn"));
        signupBtn->setGeometry(QRect(0, 130, 241, 111));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        signupBtn->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 120, 150, 10));
        StartingWindow->setCentralWidget(centralWidget);

        retranslateUi(StartingWindow);

        QMetaObject::connectSlotsByName(StartingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartingWindow)
    {
        StartingWindow->setWindowTitle(QApplication::translate("StartingWindow", "Launch Page", 0));
        loginBtn->setText(QApplication::translate("StartingWindow", "Log In", 0));
        signupBtn->setText(QApplication::translate("StartingWindow", "Sign Up", 0));
        label->setText(QApplication::translate("StartingWindow", "<html><head/><body><p><span style=\" font-size:7pt; font-style:italic;\">Don't have an account? Then...</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class StartingWindow: public Ui_StartingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTINGWINDOW_H
