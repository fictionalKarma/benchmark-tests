QT       += core gui sql network

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
    log.cpp \
    logHandler.cpp \
    fileOperations.cpp \ 
	tree.cpp \
    firma.cpp \
    administrator.cpp \
    buget.cpp \
    procesop.cpp \
    table.cpp \
    smtphandler/emailaddress.cpp \
    smtphandler/mimeattachment.cpp \
    smtphandler/mimecontentformatter.cpp \
    smtphandler/mimefile.cpp \
    smtphandler/mimehtml.cpp \
    smtphandler/mimeinlinefile.cpp \
    smtphandler/mimemessage.cpp \
    smtphandler/mimemultipart.cpp \
    smtphandler/mimepart.cpp \
    smtphandler/mimetext.cpp \
    smtphandler/quotedprintable.cpp \
    smtphandler/smtpclient.cpp \
    userinfo.cpp \
    objective.cpp


HEADERS  += startingwindow.h \
    loginform.h \
    registrationform.h \
    operations.h \
    usermanager.h \
    principalform.h \
    user.h \
    log.hpp \
    logHandler.hpp \
    fileOperations.hpp \
    includes.hpp \
	tree.hpp \
    firma.hpp \
    administrator.hpp \
    buget.h \
    procesop.h \
    table.h \
    application.h \
    userlevels.h \
    logstrings.h \
    smtphandler/emailaddress.h \
    smtphandler/mimeattachment.h \
    smtphandler/mimecontentformatter.h \
    smtphandler/mimefile.h \
    smtphandler/mimehtml.h \
    smtphandler/mimeinlinefile.h \
    smtphandler/mimemessage.h \
    smtphandler/mimemultipart.h \
    smtphandler/mimepart.h \
    smtphandler/mimetext.h \
    smtphandler/quotedprintable.h \
    smtphandler/smtpclient.h \
    smtphandler/smtpexports.h \
    smtphandler/SmtpMime \
    userinfo.h \
    objective.hpp


FORMS    += startingwindow.ui \
    loginform.ui \
    registrationform.ui \
    principalform.ui \
    buget.ui \
    procesop.ui \
    personal.ui \
    userinfo.ui

