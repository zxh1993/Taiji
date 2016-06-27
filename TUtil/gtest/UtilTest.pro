TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
    -lPocoFoundation \
    -lPocoUtil  \
    -lgtest    		\
    -lgtest_main   	\
    -lpthread		\
    -lTaijiExcept \
    -lTaijiUtil



HEADERS += \
    CUtilUnitTest.h \

SOURCES += \
    CUtilUnitTest.cpp \

