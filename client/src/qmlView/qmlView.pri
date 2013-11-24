
folder_01.source = qml
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

include(qtquick2applicationviewer/qtquick2applicationviewer.pri)

qtcAddDeployment()

HEADERS += \
    src/qmlView/qmlMainWindow.h \
    src/qmlView/qmlStartMenu.h \
    src/qmlView/qmlAiLvlList.h \
    src/qmlView/qmlBattleWidget.h \
    src/qmlView/qmlField.h \
    src/qmlView/qmlChatAndStatus.h \
    src/qmlView/qmlConnectWidget.h \
    src/qmlView/qmlInfoTab.h \
    src/qmlView/qmlSettingsMenu.h \
    src/qmlView/imageprovider.h \
    src/qmlView/qmlViewTypes.h \
    src/qmlView/qmlRootWidget.h \
    src/qmlView/qmlWidgetAppender.h

SOURCES += \
    src/qmlView/qmlMainWindow.cpp \
    src/qmlView/qmlStartMenu.cpp \
    src/qmlView/qmlAiLvlList.cpp \
    src/qmlView/qmlBattleWidget.cpp \
    src/qmlView/qmlField.cpp \
    src/qmlView/qmlChatAndStatus.cpp \
    src/qmlView/qmlConnectWidget.cpp \
    src/qmlView/qmlInfoTab.cpp \
    src/qmlView/qmlSettingsMenu.cpp \
    src/qmlView/qmlWidgetAppender.cpp

OTHER_FILES += \
    src/qmlView/qml/StartMenu.qml \
    src/qmlView/qml/ShipButton.qml \
    src/qmlView/qml/BombButton.qml \
    src/qmlView/qml/AiLvlMenu.qml \
    src/qmlView/qml/ConnectWidget.qml \
    src/qmlView/qml/SettingsMenu.qml \
    src/qmlView/qml/Menu.qml \
    src/qmlView/qml/Cell.qml \
    src/qmlView/qml/Field.qml \
    src/qmlView/qml/FieldBuilder.js \
    src/qmlView/qml/Battle.qml \
    src/qmlView/qml/FieldMessage.qml \
    src/qmlView/qml/Main.qml \
    src/qmlView/qml/Dialog.qml \
    src/qmlView/qml/InfoGirl.qml
