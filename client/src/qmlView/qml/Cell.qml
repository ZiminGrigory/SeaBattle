import QtQuick 2.0

Rectangle {
	id: main
	property int mSize: 45
	property int currentState: 0
	property string mId: "12"
	property int coordinates: 0
	width: mSize
	height: mSize
	border.color: "gray"
	color: "transparent"

	signal clickedOnCell(int id)
	signal pressedOnCell(int id)
	signal releasedOnCell(int x, int y)

	AnimatedImage{
		id: mId
		state: currentState.toString()
		width: parent.width
		height: parent.height
		states: [
			State {
				name: "0"
				PropertyChanges { target: mId; source: ""}
			 },
			 State {
				name: "1"
				PropertyChanges { target: mId; source: "qrc:/pictures/boat scout.png"}
			},
			State {
			   name: "2"
			   PropertyChanges { target: mId; source: "qrc:/pictures/bottom_hor.jpg"}
			},
			State {
				name: "3"
				PropertyChanges { target: mId; source: "qrc:/pictures/head_hor.jpg"}
			 },
			State {
				name: "4"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle part_hor.jpg"}
			},
			State {
				name: "5"
				PropertyChanges { target: mId; source: "qrc:/pictures/bottom.jpg"}
			 },
			State {
				name: "6"
				PropertyChanges { target: mId; source: "qrc:/pictures/head.jpg"}
			 },
			State {
				name: "7"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle part.jpg"}
			 },
			State {
				name: "8"
				PropertyChanges { target: mId; source: "qrc:/pictures/splash.jpg"}
			 },
			State {
				name: "9"
				PropertyChanges { target: mId; source: "qrc:/pictures/smoke_animation.gif"}
			 },
			State {
				name: "8"
				PropertyChanges { target: mId; source: "qrc:/pictures/bottom_burning.gif"}
			 },
			State {
				name: "10"
				PropertyChanges { target: mId; source: "qrc:/pictures/bottom-burning-animation_hor.gif"}
			 },
			State {
				name: "11"
				PropertyChanges { target: mId; source: "qrc:/pictures/head_burning.gif"}
			 },
			State {
				name: "12"
				PropertyChanges { target: mId; source: "qrc:/pictures/head-burning-animation_hor.gif"}
			 },
			State {
				name: "13"
				PropertyChanges { target: mId; source: "qrc:/pictures/head-burning-animation_hor.gif"}
			 },
			State {
				name: "14"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle-part-burning-animation.gif"}
			 },
			State {
				name: "15"
				PropertyChanges { target: mId; source: "image://provider/pictures/middle-part-burning-animation.gif"}
			 },
			State {
				name: "16"
				PropertyChanges { target: mId; source: "image://provider/pictures/wreck.jpg"}
			 }
		 ]
	}
	MouseArea {
		id: cellMouseArea
		width: parent.width
		height: parent.height
		onClicked: {clickedOnCell(coordinates)}
		onPressed: {pressedOnCell(coordinates)}
		onReleased: {releasedOnCell(mouseX, mouseY)}
	}
}
