
QT += core gui network multimedia widgets

DEFINES += QT5

TARGET = client
TEMPLATE = app

SOURCES += src/main.cpp

INCLUDEPATH += src/view src/iView src/qmlView src/gameLogics src/appLogics src/tcpClient src/audioPlayer ../

include(src/appLogics/appLogics.pri)
include(src/audioPlayer/audioPlayer.pri)
include(src/gameLogics/gameLogics.pri)
include(src/iView/iView.pri)
include(src/view/view.pri)
include(src/qmlView/qmlView.pri)
include(src/tcpClient/tcpClient.pri)
include(src/qmlView/qtquick2applicationviewer/qtquick2applicationviewer.pri)
