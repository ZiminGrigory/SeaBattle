import QtQuick 2.0

Rectangle {
	id: main

	width: parent.width
	anchors.verticalCenter: parent.verticalCenter
//	anchors.left: parent.left
	visible: false

	Text {
		id: text
		width: main.width
		font.pointSize: 20
		style: Text.Outline
		styleColor: "black"
		horizontalAlignment: Text.AlignHCenter
	}

	states: [
		State {
			name: "ок"
			PropertyChanges {target: text; text: "размещён"; color: "green"}
		},
		State {
			name: "uncorrect coordinates"
			PropertyChanges {target: text; text: "заблокировано"; color: "red"}
		},
		State {
			name: "not line"
			PropertyChanges {target: text; text: "не прямая"; color: "red"}
		},
		State {
			name: "have not ship"
			PropertyChanges {target: text; text: "нет такого корабля"; color: "red"}
		},
		State {
			name: "cell occupied"
			PropertyChanges {target: text; text: "заблокировано"; color: "red"}
		},
		State {
			name: "null"
		}
	]

	ParallelAnimation {
		id: animation
		running: false

		NumberAnimation { target: main; property: "y"; duration: 1000 }

		NumberAnimation { target: main; property: "opacity"; duration: 1000; from: 1.0; to: 0.0 }

		onStopped: {
			main.state = "null"
		}
	}

	onStateChanged: {
		if (main.state == "null") {
			return
		}

		main.visible = true;
		animation.start();
	}
}
