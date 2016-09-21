#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T14:13:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = TaijiExcept

TEMPLATE = lib

CONFIG += c++11

DEFINES += \

INCLUDEPATH += \
    ../../


unix {
    headfile.files = *.h
    headfile.path = /opt/devbus/taiji/v1.0/include/Taiji/TExcept
    INSTALLS += headfile
}

HEADERS += \
    Except.h

