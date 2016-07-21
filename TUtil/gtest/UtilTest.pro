TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



LIBS += \
    -lPocoFoundation \
    -lPocoUtil \
    -lPocoNet \
    -lPocoJSON \
    -lTaijiUtil \
    -lgtest \
    -lgtest_main \
    -lpthread \

HEADERS += \
    CUtilTest.h

SOURCES += \
    CUtilTest.cpp
