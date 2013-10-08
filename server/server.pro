
QT += core network

TARGET = server
TEMPLATE = app

SOURCES += \
    main.cpp \
    server.cpp \
    playerSocket.cpp

HEADERS += \
    server.h \
    ../protocol.h \
    playerSocket.h

INCLUDEPATH += ../
