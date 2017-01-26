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
    connect(ui->depCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateTrans()));
    initializeComponents();
}

RegistrationForm::~RegistrationForm() {
    delete ui;
}

void RegistrationForm::cancelButton() {
    startWindow->show();
    this->close();
}

void RegistrationForm::registerUser() {
    ui->errorLbl->setStyleSheet("color: rgba(255, 0, 0, 0);");

    if (!Operations::isValidUser(ui->userTb->text())) {
        ui->errorLbl->setText("Username must have 3+ characters; alphanumerical allowed.");
        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else if (!Operations::isValidPassword(ui->passTb->text())) {
        ui->errorLbl->setText("Password must be 6+ characters; alphanumerical, minimum a digit.");
        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else if (ui->passcTb->text() != ui->passTb->text()) {
        ui->errorLbl->setText("The two passwords are not identical.");
        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    else if (!Operations::isValidEmail(ui->emailTb->text())) {
        ui->errorLbl->setText("Please insert a valid email address.");
        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
        qDebug() << "invalid mail";
    }

    else if (ui->emailconfTb->text() != ui->emailTb->text()) {
        ui->errorLbl->setText("The two email addresses must be identical.");
        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }

    //  Checks whether the textboxes are empty or not and for correct data input :D trust me
    else if (ui->fnameTb->text().isEmpty() || ui->lnameTb->text().isEmpty() || ui->cnptb->text().isEmpty()
            || ui->addressTb->text().isEmpty() || ui->companyTb->text().isEmpty() || ui->salaryTb->text().isEmpty()
            || ui->bossTb->text().isEmpty() || !Operations::isValidName(ui->fnameTb->text()) ||
               !Operations::isValidName(ui->lnameTb->text()) || !Operations::isValidName(ui->bossTb->text()) || !ui->salaryTb->text().toInt()
            || !ui->cnptb->text().toLongLong() || !Operations::isValidName(ui->companyTb->text())) {

            ui->errorLbl->setText("The personal data or business data input is bad.\n\
- First name must not contain special characters, digits or spaces\n\
- Last name must not contain special characters, digits or spaces\n\
- Company must not contain special characters, digits or spaces\n\
- Salary, CNP must be only digits\n\
- Supervisor must not contain special characters, digits or spaces\n\
- Address must respect the placeholder format");
           ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
    }


    else {
        if (UserManager::findUserByName(ui->userTb->text())) {
            ui->errorLbl->setText("This username was taken by another user.");
            ui->errorLbl->setStyleSheet("color: rgba(255, 0, 0, 1);");
        } else if (UserManager::findUserByMail(ui->emailTb->text())) {
            ui->errorLbl->setText("There is already a user registered with this email.");
            ui->errorLbl->setStyleSheet("color: rgba(255, 0, 0, 1);");
        } else {
            if(!UserManager::checkExistance(ui->companyTb->text())){
                    if(ui->admin_check->isChecked())
                        {
                            UserManager::createTableFirma(ui->companyTb->text());
                            UserManager::insertIntoFirma(ui->userTb->text(),"",ui->companyTb->text());
                            UserManager::openDatabaseConn();
                            getUserData();
                            UserManager::registerUser(ui->userTb->text(), ui->passTb->text(), ui->emailTb->text());
                            UserManager::registerUserData(ui->userTb->text(), userData);
                            ui->errorLbl->setText("Registration succesful! Check your inbox...");
                            ui->errorLbl->setStyleSheet("color: rgba(0, 180, 0, 1);");
                            ui->regBtn->setEnabled(false);
                            ui->cancelBtn->setEnabled(false);
                            logger.addLog(SUCCEEDED_REGISTRATION(ui->userTb->text()));
                            sendConfirmationMail();

                        }
                    else {
                        ui->errorLbl->setText("The company is not register in our database. Please wait for the admin to register");
                        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
                    }

            }
            else {
                if(!ui->admin_check->isChecked()){
                    if(!UserManager::existaSupervisor(ui->bossTb->text(),ui->companyTb->text())){
                        ui->errorLbl->setText("Your superviser has not registered yet !");
                        ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
                    }
                    else{
                    UserManager::insertIntoFirma(ui->userTb->text(),ui->bossTb->text(),ui->companyTb->text());
                    UserManager::openDatabaseConn();
                    getUserData();
                    UserManager::registerUser(ui->userTb->text(), ui->passTb->text(), ui->emailTb->text());
                    UserManager::registerUserData(ui->userTb->text(), userData);
                    ui->errorLbl->setText("Registration succesful! Check your inbox...");
                    ui->errorLbl->setStyleSheet("color: rgba(0, 180, 0, 1);");
                    ui->regBtn->setEnabled(false);
                    ui->cancelBtn->setEnabled(false);
                    logger.addLog(SUCCEEDED_REGISTRATION(ui->userTb->text()));
                    sendConfirmationMail();
                    }
                }
                else{
                    ui->errorLbl->setText("The company has already registered !");
                    ui->errorLbl->setStyleSheet("color:rgba(255, 0, 0, 1);");
                }
            }

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
    QString mailMsg = "Hi, " + ui->fnameTb->text() + "\n\
We are sending this message to confirm your account creation for our product, Benchmark Testing. We hope you'll enjoy your experience! Please do not reply to this message. Here are your account details, in order to check for mistakes:\n\
    \n\
    Name: " + ui->fnameTb->text() + " " + ui->lnameTb->text() + "\n\
    Username: " + ui->userTb->text() + "\n\
    CNP: " + ui->cnptb->text() + "\n\
    Address: " + ui->addressTb->text() + "\n\
    E-Mail Address: " + ui->emailTb->text() + "\n\
    Working Place: " + ui->companyTb->text() + "\n\
    Direct Supervisor: " + ui->bossTb->text() + "\n\
    \nPlease take note that we're not including your profile information in this message. You may review and edit those stats later in the client's Profile page.\n\
    \nBest regards,\nBenchmark Testing Team.";

    text.setText(mailMsg);
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

void RegistrationForm::initializeComponents() {
    ui->depCombo->addItem("Road");
    ui->depCombo->addItem("Sea");
    ui->depCombo->addItem("Airway");
    ui->depCombo->addItem("Railway");
    ui->depCombo->addItem("International");
    ui->depCombo->addItem("Domestic");
    ui->compsLbl->setText("Driving");

    map.insert("Road", "Driving");
    map.insert("Sea", "Sailing");
    map.insert("Airway", "Piloting");
    map.insert("Railway", "Driving");
    map.insert("International", "Driving");
    map.insert("Domestic", "Driving");

    //Transport comboBox
    ui->transCombo->addItem("None");
    ui->transCombo->addItem("Low");
    ui->transCombo->addItem("Medium");
    ui->transCombo->addItem("Advanced");
    //Negotiation comboBox
    ui->negCombo->addItem("None");
    ui->negCombo->addItem("Low");
    ui->negCombo->addItem("Medium");
    ui->negCombo->addItem("Advanced");
    //Teamwork ComboBox
    ui->teamCombo->addItem("None");
    ui->teamCombo->addItem("Low");
    ui->teamCombo->addItem("Medium");
    ui->teamCombo->addItem("Advanced");
    //Data Analysis ComboBox
    ui->dataCombo->addItem("None");
    ui->dataCombo->addItem("Low");
    ui->dataCombo->addItem("Medium");
    ui->dataCombo->addItem("Advanced");
    //Presentation ComboBox
    ui->presCombo->addItem("None");
    ui->presCombo->addItem("Low");
    ui->presCombo->addItem("Medium");
    ui->presCombo->addItem("Advanced");
    //Social ComboBox
    ui->socialCombo->addItem("None");
    ui->socialCombo->addItem("Low");
    ui->socialCombo->addItem("Medium");
    ui->socialCombo->addItem("Advanced");
    //Decision ComboBox
    ui->decCombo->addItem("None");
    ui->decCombo->addItem("Low");
    ui->decCombo->addItem("Medium");
    ui->decCombo->addItem("Advanced");
    //Time ComboBox
    ui->timeCombo->addItem("None");
    ui->timeCombo->addItem("Low");
    ui->timeCombo->addItem("Medium");
    ui->timeCombo->addItem("Advanced");
}

void RegistrationForm::updateTrans() {
    ui->compsLbl->setText(map[ui->depCombo->currentText()]);
}

void RegistrationForm::getUserData() {
    userData.insert("name", ui->fnameTb->text() + " " + ui->lnameTb->text());
    userData.insert("cnp", ui->cnptb->text());
    userData.insert("address", ui->addressTb->text());
    userData.insert("company", ui->companyTb->text());
    userData.insert("salary", ui->salaryTb->text());
    userData.insert("boss", ui->bossTb->text());
    userData.insert("department", ui->depCombo->currentText());
    userData.insert("drivingComp", ui->transCombo->currentText());
    userData.insert("teamwork", ui->teamCombo->currentText());
    userData.insert("negotiation", ui->negCombo->currentText());
    userData.insert("analysis", ui->dataCombo->currentText());
    userData.insert("presentation", ui->presCombo->currentText());
    userData.insert("social", ui->socialCombo->currentText());
    userData.insert("decision", ui->decCombo->currentText());
    userData.insert("timemanage", ui->timeCombo->currentText());
    userData.insert("projmanage", ui->projBox->isChecked() ? "true" : "false");
    userData.insert("iata", ui->iataBox->isChecked() ? "true" : "false");
    userData.insert("adr", ui->adrBox->isChecked() ? "true" : "false");
    userData.insert("sixsigma", ui->sigmaBox->isChecked() ? "true" : "false");
    userData.insert("itman", ui->itBox->isChecked() ? "true" : "false");
    userData.insert("timeman", ui->timeBox->isChecked() ? "true" : "false");
    userData.insert("admin",ui->admin_check->isChecked() ? "true" : "false");
}

