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
	property  variant mStates: ["0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18"]

	AnimatedImage{
		id: mId
		state: currentState.toString()
		width: parent.width
		height: parent.height
		states: [
//			EMPTY,
//		    MISS_CELL,1
//		    SHIP_POOP_VERTICAL,2
//		    SHIP_BOW_VERTICAL,3
//		    SHIP_DECK_VERTICAL,4
//		    SHIP_POOP_HORIZONTAL,5
//		    SHIP_BOW_HORIZONTAL,6
//		    SHIP_DECK_HORIZONTAL,7
//			SHIP_POOP_VERTICAL_BURN,8
//			SHIP_BOW_VERTICAL_BURN,9
//			SHIP_DECK_VERTICAL_BURN,10
//			SHIP_POOP_HORIZONTAL_BURN,11
//			SHIP_BOW_HORIZONTAL_BURN,12
//			SHIP_DECK_HORIZONTAL_BURN,13
//			SHIP_SINGLE_BURN,14
//			SHIP_SINGLE,15
//		    SHIP_DAMAGED,16
//			SHIP_KILLED,17
//			WRECK 18
			State {
				name: "0"
				PropertyChanges { target: mId; source: ""}
			 },
			 State {
				name: "15"
				PropertyChanges { target: mId; source: "qrc:/pictures/small ship.jpg"}
			},
			State {
			   name: "5"
			   PropertyChanges { target: mId; source: "qrc:/pictures/bottom_hor.jpg"}
			},
			State {
				name: "6"
				PropertyChanges { target: mId; source: "qrc:/pictures/head_hor.jpg"}
			 },
			State {
				name: "7"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle part_hor.jpg"}
			},
			State {
				name: "2"
				PropertyChanges { target: mId; source: "qrc:/pictures/bottom.jpg"}
			 },
			State {
				name: "3"
				PropertyChanges { target: mId; source: "qrc:/pictures/head.jpg"}
			 },
			State {
				name: "4"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle part.jpg"}
			 },
			State {
				name: "1"
				PropertyChanges { target: mId; source: "qrc:/pictures/splash.jpg"}
			 },
			State {
				name: "16"
				PropertyChanges { target: mId; source: "qrc:/pictures/smoke_animation.gif"}
			 },
			State {
				name: "8"
				PropertyChanges { target: mId; source: "qrc:/pictures/bottom_burning.gif"}
			 },
			State {
				name: "12"
				PropertyChanges { target: mId; source: "qrc:/pictures/bottom-burning-animation_hor.gif"}
			 },
			State {
				name: "9"
				PropertyChanges { target: mId; source: "qrc:/pictures/head_burning.gif"}
			 },
			State {
				name: "11"
				PropertyChanges { target: mId; source: "qrc:/pictures/head-burning-animation_hor.gif"}
			 },
			State {
				name: "10"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle-part-burning-animation.gif"}
			 },
			State {
				name: "13"
				PropertyChanges { target: mId; source: "qrc:/pictures/middle-part-burning-animation_hor.gif"}
			 },
			State {
				name: "18"
				PropertyChanges { target: mId; source: "qrc:/pictures/wreck.jpg"}
			 },
			State {
				name: "14"
				PropertyChanges { target: mId; source: "qrc:/pictures/small-ship-burning-animation.gif"}
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

	onCurrentStateChanged: {
		console.log("current state is ",currentState)
		mId.state = mStates[currentState]
	}
}
