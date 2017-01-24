QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ProjPOO
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        startingwindow.cpp \
    loginform.cpp \
    registrationform.cpp \
    operations.cpp \
    usermanager.cpp \
    principalform.cpp \
    user.cpp \
    event.cpp \
    event_queue.cpp \
    log.cpp \
    logHandler.cpp \
    fileOperations.cpp \ 
	tree.cpp \
    firma.cpp \
    administrator.cpp \
    buget.cpp \
    procesop.cpp \
    personal.cpp \
    table.cpp


HEADERS  += startingwindow.h \
    loginform.h \
    registrationform.h \
    error.hpp \
    operations.h \
    usermanager.h \
    principalform.h \
    user.h \
    event.hpp \
    event_queue.hpp \
    log.hpp \
    logHandler.hpp \
    fileOperations.hpp \
    includes.hpp \
	tree.hpp \
    firma.hpp \
    administrator.hpp \
    buget.h \
    procesop.h \
    personal.h \
    table.h


FORMS    += startingwindow.ui \
    loginform.ui \
    registrationform.ui \
    principalform.ui \
    buget.ui \
    procesop.ui \
    personal.ui

