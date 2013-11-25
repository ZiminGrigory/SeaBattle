import QtQuick 2.0

Image {
	id: dialog
	width: parent.width
	height: parent.height
	signal toMainMenu
	property alias picture: dialog.state
	states:[
		State{name: "winner";PropertyChanges{target: dialog; source:"qrc:/qml/qml/girl/victory.jpg"}},
		State{name: "looser";PropertyChanges{target: dialog; source:"qrc:/qml/qml/girl/defeat.jpg"}}
	]
	MouseArea{
		id: mouseArea
		width: parent.width
		height: parent.height
		Component.onCompleted: {
			mouseArea.clicked.connect(parent.toMainMenu)
		}
		onClicked: toMainMenu
	}
}
