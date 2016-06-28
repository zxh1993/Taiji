TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


LIBS +=	\
    -lPocoNet \
    -lPocoFoundation \
    -lpthread

HEADERS += \
    CUDPServer/CUDPServer.h \
    CUDPServer/CUDPRequestBaseHandler.h \
    CUDPServer/CUDPRunable.h \
    CUDPServer/CUDPData.h \
    CUDPRequestHandler.h

SOURCES += \
    CUDPServer/CUDPServer.cpp \
    main.cpp \
    CUDPServer/CUDPRunable.cpp \
    CUDPServer/CUDPData.cpp \
    CUDPRequestHandler.cpp


