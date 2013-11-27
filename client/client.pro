
QT += core gui network multimedia widgets

DEFINES += QT5

TARGET = client
TEMPLATE = app

# here we choose view mode
# qml_view - qml view
# widgets_view - simple qt widgets
CONFIG += widgets_view

# define some macroses
qml_view {
    DEFINES += QML_VIEW
}
widgets_view {
    DEFINES += WIDGETS_VIEW
}

# here we choose qml size mode
# QML_VIEW_DESKTOP - qml view on PC
# QML_VIEW_PHONE  - qml view on Phone
#DEFINES += QML_VIEW_DESKTOP

SOURCES += src/main.cpp

INCLUDEPATH += src/view src/iView src/qmlView src/gameLogics src/appLogics src/tcpClient src/audioPlayer ../

include(src/appLogics/appLogics.pri)
include(src/audioPlayer/audioPlayer.pri)
include(src/gameLogics/gameLogics.pri)
include(src/iView/iView.pri)
include(src/tcpClient/tcpClient.pri)

widgets_view {
    include(src/view/view.pri)
}
qml_view {
    include(src/qmlView/qmlView.pri)
}
