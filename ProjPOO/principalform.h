#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QMainWindow>
#include "formfeed.hpp"
//#include "firmewindow.h"
#include <QDialog>
#include<QObject>
#include<QWidget>
#include<QtGui>
#include<QStack>
#include<QTreeWidgetItem>
#include <QtCore>
#include "administrator.hpp"
#include "ui_principalform.h"
#include <qdebug.h>
#include<QMessageBox>
#include "tree.hpp"
#include "user.h"


namespace Ui {
class principalForm;
}

class principalForm : public QMainWindow
{
    Q_OBJECT
    void addRoot(QString name,QString descriere);
    void addChild(QTreeWidgetItem *parent,QString name,QString descriere);
    void modifyButtonsTree();
    void update_childrenNames();
    void createButons();
    void createBossButton();



public:
    explicit principalForm(User* u , QWidget *parent = 0);
    explicit principalForm(Administrator* admin , QWidget *parent = 0);
    explicit principalForm(QWidget *parent = 0);
    ~principalForm();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_2_clicked(bool checked);
    void handleButton();
    void on_pushButton_4_button_clicked();
    bool hasNoChildren_actualBoss();
    void on_previous_button_clicked();

private:
    Ui::principalForm *ui;
    QLayout *btnLayout;
    QVector<QString> childrenNames;
    std::vector<Node*> childrenUser;
    Node* actualBoss;
    User user;
    Administrator administrator;
    QStack<Node*> bossiStack;
    QPushButton *btnPrincipal;
    QList<QPushButton*> btnCopii;  //copii segfului
    //QVector<QPushButton> buttons;
   };

#endif // PRINCIPALFORM_H
