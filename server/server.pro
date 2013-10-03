
QT += core network

TARGET = server
TEMPLATE = app

SOURCES += \
    main.cpp \
    server.cpp

HEADERS += \
    server.h \
    ../protocol.h

INCLUDEPATH += ../
