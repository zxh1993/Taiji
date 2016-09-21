#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T14:13:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = TaijiUtil

TEMPLATE = lib

CONFIG += c++11

DEFINES += \

INCLUDEPATH += \
    ../../ \
    /opt/devbus/poco/v1.6.0/include

unix {
    target.path = /opt/devbus/taiji/v1.0/lib
    INSTALLS += target
    headfile.files = *.h
    headfile.path = /opt/devbus/taiji/v1.0/include/Taiji/TUtil
    INSTALLS += headfile
}



HEADERS += \
    CLog.h \
    CLogs.h \
    CSingleton.h \
    CTimingThread.h \
    CHttpServer.h \
    CHTTPRequestHandlerFactory.h \
    CServerApplication.h \
    CHTTPRequestHandler.h

SOURCES += \
    CLog.cpp \
    CLogs.cpp \
    CTimingThread.cpp \
    CHttpServer.cpp \
    CHTTPRequestHandlerFactory.cpp \
    CServerApplication.cpp \
    CHTTPRequestHandler.cpp


