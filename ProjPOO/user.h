#ifndef USER_H
#define USER_H

#include <QString>
#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include "usermanager.h"

class Firma;
class Tree;
struct Node ;

class User : public QObject {
    Q_OBJECT
public:
    User(QString);
    User(QString,QString);
    User(QString ,Firma* ,QString);
    User();
    void readFromDatabase(QString name);
    Firma* getFirma(){
        return firma;
    }
    void setFirma(Firma *f){
        firma = f;
    }
    void setTree(Tree *k){
        copy = k;
    }
    Tree* getTree(){
        return copy;
    }
    void operator= (User &other){
        this->setBossName(other.getBossName());
        this->setUserName(other.getUserName());
        firma = other.getFirma();
        this->data = other.data;
        this->isAdmin = other.checkAdmin();
        copy = other.copy;
    }
    bool operator==(User &other){
        int i ;
        i =  (data["boss"] == other.getBossName()) + (data["username"] == other.getUserName());
        if( i == 2)
            return true;
        return false;
    }

    // Getters
    QString getName() {
        return data["name"];
    }
    QString getCnp() {
        return data["cnp"];
    }
    QString getAddress() {
        return data["address"];
    }
    QString getCompanyName() {
        return data["company"];
    }
    QString getUserName() {
        return data["username"];
    }
    QString getPassword() {
        return data["password"];
    }
    QString getEmail() {
        return data["email"];
    }
    UserLevel getLevel() {
        if (data["level"] == "USER") return UserLevel::User;
        if (data["level"] == "MANAGER") return UserLevel::Manager;
        else return UserLevel::Administrator;
    }
    double getSalary() {
        return data["salary"].toDouble();
    }
    QString getBossName() {
        return data["boss"];
    }
    QString getDepartment() {
        return data["department"];
    }
    QString getTransportCompetence() {
        return data["transport_comp"];
    }
    QString getTeamWorkCompetence() {
        return data["teamwork"];
    }
    QString getNegotiationCompetence() {
        return data["negotiation"];
    }
    QString getDataAnalysisCompetence() {
        return data["analysis"];
    }
    QString getPresentationCompetence() {
        return data["presentation"];
    }
    QString getSocialCompetence() {
        return data["social"];
    }
    QString getDecisionMakingCompetence() {
        return data["decision"];
    }
    QString getTimeManagementCompetence() {
        return data["time_management"];
    }
    bool checkAdmin(){
        return isAdmin;
    }
    bool hasProjectManagementTraining() {
        return data["project_management"] == "true";
    }
    bool hasIATALicence() {
        return data["iata_license"] == "true";
    }
    bool hasADRLicense() {
        return data["adr_license"] == "true";
    }
    bool hasSixSigmaBelt() {
        return data["sixsigma_belt"] == "true";
    }
    bool hasITTraining() {
        return data["it_management"] == "true";
    }
    bool hasTimeManagementTraining() {
        return data["time_training"] == "true";
    }

    // Setters
    void setName(QString name) {
        if (Operations::isValidName(name)) {
            data["name"] = name;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setUserName(QString username) {
        QString oldUser = data["username"];
        if (Operations::isValidUser(username)) {
            data["username"] = username;
            UserManager::setUserData(oldUser, data);
        }
    }
    void setUserEmail(QString mail) {
        if (Operations::isValidEmail(mail)) {
            data["email"] = mail;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setUserLevel(UserLevel level) {
        this->level = level;
        QString v[] = {"USER", "MANAGER", "ADMINISTRATOR"};
        data["level"] = v[(int)level];
        UserManager::setUserData(data["username"], data);
    }
    void setUserCnp(QString cnp) {
        auto isNumber = [cnp]() {
            for (QChar c : cnp) {
                if (c.isDigit()) continue;
                return false;
            }
            return true;
        }();
        if (isNumber) {
            data["cnp"] = cnp;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setUserAddress(QString address) {
        data["address"] = address;
        UserManager::setUserData(data["username"], data);
    }
    void setCompanyName(QString company) {
        if (Operations::isValidName(company)) {
            data["company"] = company;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setSalary(double salary) {
        data["salary"] = QString::number(salary);
        UserManager::setUserData(data["username"], data);
    }
    void setBossName(QString name) {
        if (Operations::isValidName(name)) {
            data["boss"] = name;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setDepartment(QString dep) {
        QStringList vec = {"Road", "Sea", "Railway", "Airway", "International", "Domestic"};
        if (vec.contains(dep)) {
            data["department"] = dep;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setTransportCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["transport_comp"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setTeamWorkCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["teamwork"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setNegotiationCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["negotiation"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }

    void setDataAnalysisCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["analysis"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setPresentationCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["presentation"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setSocializationCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["social"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setDecisionMakingCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["decision"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setTimeManagementCompetenceLevel(QString compLevel) {
        QStringList levels = {"None", "Low", "Medium", "Advanced"};
        if (levels.contains(compLevel)) {
            data["time_management"] = compLevel;
            UserManager::setUserData(data["username"], data);
        }
    }
    void setProjectManagementTraining(bool acquired) {
        data["project_management"] = acquired ? "true":"false";
        UserManager::setUserData(data["username"], data);
    }
    void setIATALicense(bool acquired) {
        data["iata_license"] = acquired ? "true":"false";
        UserManager::setUserData(data["username"], data);
    }
    void setADRLicense(bool acquired) {
        data["adr_license"] = acquired ? "true":"false";
        UserManager::setUserData(data["username"], data);
    }
    void setSixSigmaBelt(bool acquired) {
        data["sixsigma_belt"] = acquired ? "true":"false";
        UserManager::setUserData(data["username"], data);
    }
    void setITManagementTraining(bool acquired) {
        data["it_management"] = acquired ? "true":"false";
        UserManager::setUserData(data["username"], data);
    }
    void setTimeManagementTraining(bool acquired) {
        data["time_training"] = acquired ? "true":"false";
        UserManager::setUserData(data["username"], data);
    }

signals:
    void onLogin();

protected:
    QSqlDatabase db;
    Firma* firma;
    Tree* copy;
    UserLevel level;
    bool isAdmin ;
    QMap<QString, QString> data;
};

#endif // USER_H
