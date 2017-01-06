#ifndef USER_H
#define USER_H

#include <QString>
#include <QObject>

class User : public QObject {
    Q_OBJECT

public:
    User(QString);

signals:
    void onLogin();

private:
    QString username;
};

#endif // USER_H
