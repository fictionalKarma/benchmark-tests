#ifndef USERINFO_H
#define USERINFO_H

#include <QMainWindow>
#include<administrator.hpp>
namespace Ui {
class userinfo;
}

class userinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit userinfo(User& person, QPoint location, QWidget *parent = 0);
    void updateForm();
    ~userinfo();

private:
    Ui::userinfo *ui;
    User anotherUser;
};

#endif // USERINFO_H
