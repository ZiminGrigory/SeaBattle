import QtQuick 2.0


Rectangle {
	id: shipButton

	// Specifies the game mode that activates the button
	// 0 - vs ai (int start menu)
	// 1 - vs player
	// 2 - vs simple ai
	// 3 - vs hard ai
	property int type

	property int angle

	width: parent.width * 0.8
	height: width / 4

	color: "transparent"
	anchors.horizontalCenter: parent.horizontalCenter

	Image {
		id: ship
		width: parent.width
		height: parent.height
		property string vsAiPath: "image://provider/qml/vs_computer_button.png"
		property string vsPlrPath: "image://provider/qml/vs_player_button.png"
        property string vsAiSimplePath: "image://provider/qml/qml/vs_computer_button_simple.png"
		property string vsAiHardPath: "image://provider/qml/vs_computer_button_hard.png"
		property variant texture:[vsAiPath, vsPlrPath, vsAiSimplePath, vsAiHardPath]
		source: texture[parent.type]
	}

	SequentialAnimation {
		running: true
		loops: Animation.Infinite
		NumberAnimation { target: shipButton; property: "rotation"; to: angle;
				duration: 2000 }
		NumberAnimation { target: shipButton; property: "rotation"; to: -angle;
			duration: 2000 }
		NumberAnimation { target: shipButton; property: "rotation"; to: 0;
			duration: 2000 }
	}
}
