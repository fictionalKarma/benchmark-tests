#ifndef LOGSTRINGS_H
#define LOGSTRINGS_H

#define SUCCEEDED_REGISTRATION(name) "User \'" + name + "\' completed the registration process."

#define FAILED_CONNECTION_EMAILHOST "Connection to the email host failed. No connection available?"
#define FAILED_LOGIN_EMAILHOST "Logging in to the email service has failed."
#define FAILED_EMAIL_SEND(address) "Sending the confirmation email to \'" + address + "\' has failed."
#define FAILED_ADMIN_LOGIN(user) "Someone tried to loggin as Administrator \'" + user +"\' but failed."
#define FAILED_USER_NAMECHANGE(user) "Failed to change " + user +"\'s name."
#define FAILED_USER_LEVELCHANGE(user) "Could not change " + user +"\'s level."

#define USER_LOGIN(user) "\'" + user +"\' logged in."
#define USER_NAME_CHANGE(user, newuser) user +"\''s name was changed to newuser."
#define USER_NOT_EXISTS(user) "User \'" + user +"\' does not exist."
#define USERNAME_NOT_VALID(user) "Username \'" + user +"\' is not valid."

#endif // LOGSTRINGS_H
