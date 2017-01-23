/********************************************************************************
** Form generated from reading UI file 'principalform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPALFORM_H
#define UI_PRINCIPALFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_principalForm
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *username_label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QFrame *line;
    QFrame *boss_frame;
    QFrame *children_frame;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *previous_button;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *principalForm)
    {
        if (principalForm->objectName().isEmpty())
            principalForm->setObjectName(QStringLiteral("principalForm"));
        principalForm->resize(440, 268);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(principalForm->sizePolicy().hasHeightForWidth());
        principalForm->setSizePolicy(sizePolicy);
        principalForm->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(principalForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        username_label = new QLabel(centralwidget);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setMaximumSize(QSize(16777215, 455));

        verticalLayout->addWidget(username_label);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        boss_frame = new QFrame(centralwidget);
        boss_frame->setObjectName(QStringLiteral("boss_frame"));
        boss_frame->setFrameShape(QFrame::StyledPanel);
        boss_frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(boss_frame);

        children_frame = new QFrame(centralwidget);
        children_frame->setObjectName(QStringLiteral("children_frame"));
        children_frame->setFrameShape(QFrame::StyledPanel);
        children_frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(children_frame);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        previous_button = new QPushButton(frame);
        previous_button->setObjectName(QStringLiteral("previous_button"));

        horizontalLayout->addWidget(previous_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame);

        principalForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(principalForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 440, 21));
        principalForm->setMenuBar(menubar);
        statusbar = new QStatusBar(principalForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        principalForm->setStatusBar(statusbar);

        retranslateUi(principalForm);

        QMetaObject::connectSlotsByName(principalForm);
    } // setupUi

    void retranslateUi(QMainWindow *principalForm)
    {
        principalForm->setWindowTitle(QApplication::translate("principalForm", "MainWindow", 0));
        username_label->setText(QApplication::translate("principalForm", "TextLabel", 0));
        pushButton_2->setText(QApplication::translate("principalForm", "Afiseaza firma", 0));
        pushButton->setText(QApplication::translate("principalForm", "Creaza formular", 0));
        previous_button->setText(QApplication::translate("principalForm", "Previous", 0));
    } // retranslateUi

};

namespace Ui {
    class principalForm: public Ui_principalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPALFORM_H
