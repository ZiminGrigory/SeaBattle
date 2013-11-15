import QtQuick 2.0

Rectangle {
	id: main
	width: 240
	height: 320

	signal backPressed()
	signal arrowPressed()

	property int countOfFleet: 10;
	property int countOfPlr: 10;
	property int countOfEnemy: 10;

//	import QtQuick 2.0

//	Item {
//	    width: 100; height: 100

//	    Rectangle {
//	        anchors.fill: parent
//	        objectName: "rect"
//	    }
//	}
//	The child could be located like this:
//	QObject *rect = object->findChild<QObject*>("rect");
//	if (rect)
//	    rect->setProperty("color", "red");

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
		objectName: "mCountOfShipn"
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
		objectName: "mAutoButton"
		signal needAutoSet()
		id:autoButton
		width:countOfShip.width
		height: countOfShip.height
		anchors.left: countOfShip.right
		source: "qrc:/qml/qml/auto.png"
		visible: true

		MouseArea{
			id:autoButtonMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				autoButton.needAutoSet
			}
		}
	}

	Field{
		objectName:"mPlrField"
		id: plrField
		z: 1
		visible: true
		mSize: main.width * 0.9 - (main.width % 10)
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: lableCountOfShip.bottom
		anchors.topMargin: 5
	}

	Field{
		objectName:"mEnemyField"
		visible: false
		z: 1
		id: enemyField
		mSize: main.width * 0.9 - (main.width % 10)
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: lableCountOfShip.bottom
		anchors.topMargin: 5
		Component.onCompleted: {
			update
		}
	}

	BombButton {
		id: backButton
		type: 3
		startX: parent.width - width - 10
		startY: parent.height - height - 10

		MouseArea {
			id: backMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				backMouseArea.clicked.connect(main.backPressed)
			}
		}
	}


	BombButton{
		objectName:"mButtonReady"
		signal ready()
		id: buttonReady
		startX: 10
		startY: parent.height - height - 10
		type: 2
		visible: true

		MouseArea{
			id:buttonReadyMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				buttonReadyMouseArea.clicked.connect(buttonReady.ready)
			}
		}
	}

	Image{
		objectName:"mInfoButton"
		signal infoPressed()
		id: infoButton
		width: main.width / 2.3
		height: width / 2
		source: "qrc:/qml/help.png"
		visible: true
		property int currentPicture: 0
		anchors.bottom: main.bottom
		anchors.bottomMargin: height / 4
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
				infoButton.infoPressed
			}
		}
	}

	Image{
		visible: false
		id: arrowButton
		width: main.width / 2.3
		height: width / 2
		source: "qrc:/qml/arrow right.png"
		property int currentPicture: 0
		anchors.horizontalCenter: main.horizontalCenter
		anchors.bottom: main.bottom
		anchors.bottomMargin: height / 4
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
				parent.currentPicture = (parent.currentPicture + 1) % 2
				arrowPressed
			}
		}
	}

	onArrowPressed: {
		if(plrField.visible == true){
			plrField.visible = false;
			enemyField.visible = true;
			countOfShip.currentNumber = countOfEnemy;
		}else{
			plrField.visible = true;
			enemyField.visible = false;
			countOfShip.currentNumber = countOfPlr;
		}
	}
}
