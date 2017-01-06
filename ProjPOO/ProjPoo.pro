#-------------------------------------------------
#
# Project created by QtCreator 2017-01-02T13:52:23
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjPoo
TEMPLATE = app


SOURCES += main.cpp\
        startingwindow.cpp \
    loginform.cpp \
    registrationform.cpp \
    operations.cpp \
    usermanager.cpp \
    conferintaform.cpp \
    principalform.cpp \
    user.cpp

HEADERS  += startingwindow.h \
    loginform.h \
    registrationform.h \
    error.h \
    operations.h \
    usermanager.h \
    conferintaform.h \
    principalform.h \
    user.h

FORMS    += startingwindow.ui \
    loginform.ui \
    registrationform.ui \
    conferintaform.ui \
    principalform.ui
