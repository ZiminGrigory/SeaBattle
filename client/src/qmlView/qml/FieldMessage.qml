import QtQuick 2.0

Rectangle {
	id: fieldMessage
	width: parent.width * 0.9
	height: parent.height * 0.6

	color: "transparent"

	anchors.verticalCenter: parent.verticalCenter
	anchors.horizontalCenter: parent.horizontalCenter

	Image {
		id: img

		width: parent.width
		height: parent.height

		opacity: 0.0
		visible: false

		SequentialAnimation {
			id: opacityAnimation
			running: false
			NumberAnimation { target: img; property: "opacity"; duration: 1000; from: 1.0; to: 0.0}
		}

//		SequentialAnimation {
//			id: opacityAnimationForPlr
//			running: false
//            NumberAnimation { target: img; property: "opacity"; duration: 800; from: 1.0; to: 0.0}
//		}

		onSourceChanged: {
//			if (img.source != "qrc:/pictures/you_turn.png" &&
//					img.source != "qrc:/pictures/enemy_turn.png"){
				opacityAnimation.start()
//			} else {
//				opacityAnimationForPlr.start()
//			}
		}
	}

	states: [
		State {
			name: "invisible"
			when: img.opacity == 0.0
			PropertyChanges {target: img; visible: false}
		},
		State {
			name: "miss"
			PropertyChanges { target: img; source: "qrc:/pictures/miss.png"; visible: true}
		},
		State {
			name: "wounded"
			PropertyChanges { target: img; source: "qrc:/pictures/wounded.png"; visible: true}
		},
		State {
			name: "killed"
			PropertyChanges { target: img; source: "qrc:/pictures/killed.png"; visible: true }
		},
		State {
			name: "you_turn"
			PropertyChanges { target: img; source: "qrc:/pictures/you_turn.png"; visible: true }
		},
		State {
			name: "enemy_turn"
			PropertyChanges { target: img; source: "qrc:/pictures/enemy_turn.png"; visible: true }
		}
	]
}
