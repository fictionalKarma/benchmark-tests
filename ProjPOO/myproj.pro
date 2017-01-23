QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ProjPoo
TEMPLATE = app

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
    formfeed.cpp \
    fileOperations.cpp \ 
    tree.cpp \
    firma.cpp \
    administrator.cpp \
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
    smtphandler/smtpclient.cpp



HEADERS  += startingwindow.h \
    loginform.h \
    registrationform.h \
    error.hpp \
    operations.h \
    usermanager.h \
    principalform.h \
    user.h \
    log.hpp \
    logHandler.hpp \
    formfeed.hpp \
    fileOperations.hpp \
    includes.hpp \
	tree.hpp \
    firma.hpp \
    administrator.hpp \
    logstrings.h \
    userlevels.h \
    application.h \
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
    smtphandler/SmtpMime


FORMS    += startingwindow.ui \
    loginform.ui \
    registrationform.ui \
    conferintaform.ui \
    principalform.ui

