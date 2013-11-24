import QtQuick 2.0

Rectangle {
    id: main
    width: parent.width
    height: parent.height
    property alias currentState: girl.state
    property int mCurrentState: 0;
    signal closeMe
    Image {
        id: girl
        width: parent.width
        height: parent.height
        states:[
            // I made state's names numbers, because I don't split up this easy feature between js and cpp
            State{name:"0"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_begin_1.jpg"}},
            State{name:"1"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_ship1_2.jpg"}},
            State{name:"2"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_ship2_3.jpg"}},
            State{name:"3"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_deleteship_4.jpg"}},
            State{name:"4"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_deleteship2_5.jpg"}},
            State{name:"5"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_auto_6.jpg"}},
            State{name:"6"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_ready_7.jpg"}},
            State{name:"7"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_battle_8.jpg"}},
            State{name:"8"; PropertyChanges {target: girl; source:"qrc:/qml/qml/girl/girl_start battle_bye_9.jpg"}}
        ]
        MouseArea{
            id: imageMouseArea
            width: parent.width
            height: parent.height
            onClicked: {
                mCurrentState++;
                if (mCurrentState == 9){
                    closeMe()
                }
            }
        }
    }
    Image{
        id: closeButton
        width: parent.width / 5
        height: width
        anchors.right: main.right
        anchors.top: main.top
        anchors.topMargin: width * 1.5
        anchors.rightMargin: width / 4
        source: "qrc:/qml/qml/no.png"
        MouseArea{
            id:buttonBackMouseArea
            width: parent.width
            height: parent.height
            onClicked: {
                closeMe()
            }
        }
    }

    onMCurrentStateChanged: {
        girl.state = mCurrentState.toString()
    }
}
