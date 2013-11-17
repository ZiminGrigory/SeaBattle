import QtQuick 2.0

Rectangle {
	id: main

	signal repeat
	signal quitClicked

	Menu {
		id: menu
		width: parent.width
		height: parent.height

		topShipButtonType: -1
		bottomShipButtonType: -1
		leftBombButtonType: 4
		rightBombButtonType: 3

		Component.onCompleted: {
			menu.leftBombButton.clicked.connect(main.repeat)
			menu.rightBombButton.clicked.connect(main.quitClicked)
		}
	}

	AnimatedImage{
		id: loader
		objectName: "loader"
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: main.top
		anchors.topMargin: main.height / 3
		visible: true
		width: parent.width / 1.6
		height: width
		source: "qrc:/qml/qml/Radar.gif"
	}

	Text {
		id: textBrowser
		objectName: "messageBox"
		wrapMode: Text.WordWrap
		width: parent.width / 1.5
		height: loader.height / 4
		anchors.left: main.left
		anchors.leftMargin: main.width / 16
		anchors.bottom: loader.top
		style: Text.Outline; styleColor: "black"
		text: "Connection"
		font.family: "Helvetica"
		font.pointSize: height / 2.4
		color: "white"
	 }
}

