#include "startingwindow.h"
#include "ui_startingwindow.h"

StartingWindow::StartingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartingWindow)
{
    ui->setupUi(this);

    setFixedSize(this->size());
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(launchLoginForm()));
    connect(ui->signupBtn, SIGNAL(clicked()), this, SLOT(launchSignUp()));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::launchLoginForm() {
    log = new LoginForm(this);
    log->show();
    this->close();
}

void StartingWindow::launchSignUp() {
    reg = new RegistrationForm(this);
    reg->show();
    this->close();
}
