import QtQuick 2.0

Rectangle {
	id: main
	width: 240
	height: 320

	signal ready()
	signal backPressed()
	signal infoPressed()
	signal arrowPressed()

	Image {
		id: background
		width: main.width
		height: main.height
		source: "qrc:/qml/background.jpg"
	}

	Image{
		id:lableCountOfShip
		anchors.top: main.top
		width: main.width / 4 * 2
		height: main.height / 10
		source: "qrc:/qml/qml/countOfShip.png"
	}

	Image{
		id:countOfShip
		property int currentNumber: 10
		width: lableCountOfShip.width / 2
		height: lableCountOfShip.height
		source: "qrc:/qml/qml/10.png"
		anchors.left: lableCountOfShip.right
		states:[
			State {name: "10";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "9";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/9.png"}},
			State {name: "8";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "7";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "6";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "5";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "4";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "3";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "2";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "1";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}},
			State {name: "0";PropertyChanges { target: countOfShip; source: "qrc:/qml/qml/10.png"}}
		]
		onCurrentNumberChanged: {countOfShip.state = currentNumber.toString()}
	}

	Image{
		id: buttonReady
		width: lableCountOfShip.width / 2
		height: lableCountOfShip.height
		source: "qrc:/qml/qml/ready.png"
		anchors.left: countOfShip.right
		MouseArea{
			id:buttonReadyMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				buttonReadyMouseArea.clicked.connect(main.ready)
			}
		}
	}

	Field{
		id: plrField
		z: 1
		visible: true
		mSize: main.width * 0.9 - (main.width % 10)
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: lableCountOfShip.bottom
		anchors.topMargin: 5
	}

	Field{
		visible: false
		z: 1
		id: enemyField
		mSize: main.width * 0.9 - (main.width % 10)
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: lableCountOfShip.bottom
		anchors.topMargin: 5
	}

	BombButton {
		id: backButton
		type: 1
		startX: parent.width - width - 10
		startY: parent.height - height - 10

		MouseArea {
			id: backMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				backMouseArea.clicked.connect(main.backPressed)
			}
		}
	}

	Image{
		id: infoButton
		width: main.width / 2.3
		height: width / 3.2
		source: "qrc:/qml/help.png"
		visible: true
		property int currentPicture: 0
		anchors.bottom: main.bottom
		anchors.topMargin: height / 10
		anchors.horizontalCenter: main.horizontalCenter
		states:[
			State {name: "0";PropertyChanges { target: infoButton; source: "qrc:/qml/qml/help.png"}},
			State {name: "1";PropertyChanges { target: infoButton; source: "qrc:/qml/qml/helping.png"}}
		]
		onCurrentPictureChanged: {infoButton.state = currentPicture.toString();}
		MouseArea {
			id: infoButtonMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				infoButtonMouseArea.clicked.connect(main.infoPressed)
			}
		}
	}

	Image{
		id: arrowButton
		width: main.width / 2.3
		height: width / 3.2
		source: "qrc:/qml/arrow right.png"
		property int currentPicture: 0
		states:[
			State {name: "0";PropertyChanges { target: infoButton; source: "qrc:/qml/arrow right.png"}},
			State {name: "1";PropertyChanges { target: infoButton; source: "qrc:/qml/arrow left.png"}}
		]
		onCurrentPictureChanged: {infoButton.state = currentPicture.toString()}
		MouseArea {
			id: arrowButtonMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				arrowButtonMouseArea.clicked.connect(main.arrowPressed)
			}
		}
		anchors.horizontalCenter: main.horizontalCenter
		anchors.bottom: infoButton.top
		anchors.topMargin: height / 10
	}
}
