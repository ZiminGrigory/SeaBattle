import QtQuick 2.0


Rectangle {
	id: main
	width: 240
	height: 320

	property alias testText: test.text

	signal vsPlayerClicked()
	signal vsAiClicked()

	Image {
		id: background
		width: main.width
		height: main.height
		source: "/home/evgeniy/projects/qml_helloworld/untitled/background.jpg"
	}

	ShipButton {
		id: vsPlayerButton
		anchors.top: parent.top
		anchors.topMargin: parent.height / 4

		type: 0
		angle: 5

		MouseArea {
			id: vsPlayerMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				vsPlayerMouseArea.clicked.connect(main.vsPlayerClicked)
			}
		}
	}

	ShipButton {
		id: vsAiButton
		anchors.top: vsPlayerButton.bottom
		anchors.topMargin: 5

		type: 1
		angle: -3

		MouseArea {
			id: vsAiMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				vsAiMouseArea.clicked.connect(main.vsAiClicked)
			}
		}
	}

	BombButton {
		id: settingsButton

		type: 0
		startX: 10
		startY: parent.height - height - 10
	}

	BombButton {
		id: quitButton

		type: 1
		startX: parent.width - width - 10
		startY: parent.height - height - 10
	}

	Text {
		text: "test"
		id: test
		color: "white"
		anchors.bottom: parent.bottom
	}
}
