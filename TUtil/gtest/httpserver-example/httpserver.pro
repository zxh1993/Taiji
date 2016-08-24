TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CSerApp.cpp \
    CHttpHandler1.cpp \
    CHttpHandler2.cpp \
    CHttpHandler3.cpp \
    CHttpHandler4.cpp

HEADERS += \
    CSerApp.h \
    CHttpHandler1.h \
    CHttpHandler2.h \
    CHttpHandler3.h \
    CHttpHandler4.h


LIBS += \
    -lPocoFoundation \
    -lPocoUtil \
    -lPocoNet \
    -lPocoJSON \
    -lTaijiRedis \
    -lTaijiUtil \
    -lpthread \
