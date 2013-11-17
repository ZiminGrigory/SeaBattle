
QT += core gui network multimedia widgets

DEFINES += QT5

TARGET = client
TEMPLATE = app

# here we choose view mode
# QML_VIEW - qml view
# WIDGETS_VIEW - simple qt widgets
DEFINES += QML_VIEW

# here we choose qml size mode
# QML_VIEW_DESKTOP - qml view on PC
# QML_VIEW_PHONE  - qml view on Phone
DEFINES += QML_VIEW_DESKTOP

SOURCES += src/main.cpp

INCLUDEPATH += src/view src/iView src/qmlView src/gameLogics src/appLogics src/tcpClient src/audioPlayer ../

include(src/appLogics/appLogics.pri)
include(src/audioPlayer/audioPlayer.pri)
include(src/gameLogics/gameLogics.pri)
include(src/iView/iView.pri)
include(src/view/view.pri)
include(src/qmlView/qmlView.pri)
include(src/tcpClient/tcpClient.pri)

