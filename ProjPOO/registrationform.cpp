#include "registrationform.h"
#include "ui_registrationform.h"
#include "smtphandler/SmtpMime"

RegistrationForm::RegistrationForm(QMainWindow *qm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButton()));
    startWindow = qm;
    setFixedSize(this->size());
    connect(ui->regBtn, SIGNAL(clicked()), this, SLOT(registerUser()));
    connect(ui->emailconfTb, SIGNAL(returnPressed()), this, SLOT(registerUser()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(openPersonal()));
}

RegistrationForm::~RegistrationForm() {
    delete ui;
}

void RegistrationForm::cancelButton() {
    startWindow->show();
    this->close();
}

void RegistrationForm::registerUser() {
    ui->userError->setStyleSheet("color: rgba(255, 0, 0, 0);");
    ui->passError->setStyleSheet("color: rgba(255, 0, 0, 0);");
    ui->emError->setStyleSheet("color: rgba(255, 0, 0, 0);");
    ui->confError->setStyleSheet("color: rgba(255, 0, 0, 0);");
    ui->emcoError->setStyleSheet("color: rgba(255, 0, 0, 0);");

    if (!Operations::isValidUser(ui->userTb->text())) {
        ui->userError->setText("Username must have 3+ characters; alphanumerical allowed.");
        ui->userError->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else if (!Operations::isValidPassword(ui->passTb->text())) {
        ui->passError->setText("Password must be 6+ characters; alphanumerical, minimum a digit.");
        ui->passError->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else if (ui->passcTb->text() != ui->passTb->text()) {
        ui->confError->setText("The two passwords are not identical.");
        ui->confError->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else if (!Operations::isValidEmail(ui->emailTb->text())) {
        ui->emError->setText("Please insert a valid email address.");
        ui->emError->setStyleSheet("color:rgba(255, 0, 0, 1);");
        qDebug() << "invalid mail";
    }

    else if (ui->emailconfTb->text() != ui->emailTb->text()) {
        ui->emcoError->setText("The two email addresses must be identical.");
        ui->emcoError->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else {
        if (UserManager::findUserByName(ui->userTb->text())) {
            ui->userError->setText("This username was taken by another user.");
            ui->userError->setStyleSheet("color: rgba(255, 0, 0, 1);");
        } else if (UserManager::findUserByMail(ui->emailTb->text())) {
            ui->emError->setText("There is already a user registered with this email.");
            ui->emError->setStyleSheet("color: rgba(255, 0, 0, 1);");
        } else {
            UserManager::openDatabaseConn();
            UserManager::registerUser(ui->userTb->text(), ui->passTb->text(), ui->emailTb->text());
            ui->emcoError->setText("Registration succesful! Check your inbox...");
            ui->emcoError->setStyleSheet("color: rgba(0, 180, 0, 1);");
            ui->regBtn->setEnabled(false);
            ui->cancelBtn->setEnabled(false);
            logger.addLog(SUCCEEDED_REGISTRATION(ui->userTb->text()));
            sendConfirmationMail();
        }
    }
}

void RegistrationForm::sendConfirmationMail() {
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("benchmark.testing.team@gmail.com");
    smtp.setPassword("bentestteam");

    MimeMessage message;
    message.setSender(new EmailAddress("benchmark.testing.team@gmail.com", "Benchmark Testing Team"));
    message.addRecipient(new EmailAddress(ui->emailTb->text(), ui->userTb->text()));

    MimeText text;
    text.setText("Hi,\nWe're sending this e-mail as a confirmation of your account registration for our product, Benchmark Testing. We hope you'll enjoy your experience! Please do not reply to this mail. Here are your account details:\n\nUsername: " + ui->userTb->text() + "\nPassword: " + ui->passTb->text() + "\nE-Mail Address: " + ui->emailTb->text() + "\n\nBest regards,\nBenchmark Testing Team.");
    message.addPart(&text);
    message.setSubject("Your registration confirmation");


    if (!smtp.connectToHost()) {
        logger.addLog(FAILED_CONNECTION_EMAILHOST);
    }
    if (!smtp.login()) {
        logger.addLog(FAILED_LOGIN_EMAILHOST);
    }
    if (!smtp.sendMail(message)) {
        logger.addLog(FAILED_EMAIL_SEND(ui->emailTb->text()));
    }
    smtp.quit();

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(redirect()));
    timer->setSingleShot(true);
    timer->start(3000);
}

void RegistrationForm::redirect() {
    startWindow->show();
    this->close();
}

void RegistrationForm::openPersonal() {

}
