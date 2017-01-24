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
    log = new LoginForm(this);
    reg = new RegistrationForm(this);
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::launchLoginForm() {
    log->show();
    this->close();
}

void StartingWindow::launchSignUp() {
    reg->show();
    this->close();
}
