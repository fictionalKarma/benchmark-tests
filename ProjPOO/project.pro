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
    formfeed.cpp \
    fileOperations.cpp \ 
	tree.cpp \
    firma.cpp \
    administrator.cpp



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
    formfeed.hpp \
    fileOperations.hpp \
    includes.hpp \
	tree.hpp \
    firma.hpp \
    administrator.hpp


FORMS    += startingwindow.ui \
    loginform.ui \
    registrationform.ui \
    principalform.ui
