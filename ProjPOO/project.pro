QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++0x
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
    user.cpp \
    event.cpp \ 
    event_queue.cpp \
    log.cpp \
    logHandler.cpp \
    formfeed.cpp \
    fileOperations.cpp

HEADERS  += startingwindow.h \
    loginform.h \
    registrationform.h \
    error.hpp \
    operations.h \
    usermanager.h \
    conferintaform.h \
    principalform.h \
    user.h \
    event.hpp \
    event_queue.hpp \
    log.hpp \
    logHandler.hpp \
    formfeed.hpp \
    fileOperations.hpp \
    includes.hpp

FORMS    += startingwindow.ui \
    loginform.ui \
    registrationform.ui \
    conferintaform.ui \
    principalform.ui

