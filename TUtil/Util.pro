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
    ../../

LIBS += \
    -lPocoFoundation \
    -lPocoNet \
    -lPocoUtil \
    -lpthread \

unix {
    target.path = ../Lib
    INSTALLS += target
    headfile.files = *.h
    headfile.path = ../Include/Taiji/TUtil
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


