import QtQuick 2.0

Rectangle {
	id: main
	width: 240
	height: 320

	function switchToPlayerField() {
		enemyField.visible = false;
		plrField.visible = true;

	}

	function switchToEnemyField() {
		plrField.visible = false;
		enemyField.visible = true;
	}

	signal backPressed()
	signal arrowPressed()
	signal deleteMode(bool isActive)

	property int countOfFleet: 10;
	property int countOfPlr: 10;
	property int countOfEnemy: 10;
	property bool isFight: false;

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
		objectName: "mCountOfShip"
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
			Component.onCompleted: {
				autoButtonMouseArea.clicked.connect(autoButton.needAutoSet)
			}
		}
	}

	Text{
		objectName: "timer"
		id: timer
		visible: false
		width:height
		height: countOfShip.height
		anchors.left: countOfShip.right
		style: Text.Outline; styleColor: "red"
		text: "22"
		font.family: "Helvetica"
		font.pointSize: height / 1.5
		color: "black"
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
	}

	BombButton {
		id: backButton
		type: 3

		anchors.right: parent.right
		anchors.bottom: parent.bottom

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

		anchors.left: parent.left
		anchors.bottom: parent.bottom

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
		signal infoPressed
		id: infoButton
		width: main.width / 2.5
		height: width / 4
		source: "qrc:/qml/help.png"
		visible: true
		property int currentPicture: 0

		anchors.bottom: main.bottom
		anchors.bottomMargin: height/4
		anchors.horizontalCenter: main.horizontalCenter

		states:[
			State {name: "0";PropertyChanges { target: infoButton; source: "qrc:/qml/help.png"}},
			State {name: "1";PropertyChanges { target: infoButton; source: "qrc:/qml/helping.png"}}
		]
		onCurrentPictureChanged: {infoButton.state = currentPicture.toString();}
		MouseArea {
			id: infoButtonMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				infoButtonMouseArea.clicked.connect(parent.changePicture)
			}
		}
		function changePicture(){
			currentPicture = (currentPicture + 1) % 2
		}
		// to do: make girl
	}

	Image{
		objectName:"mDeleteModeButton"
		id: deleteModeButton
		width: main.width / 2.5
		height: width / 4
		source: "qrc:/qml/qml/delete button.png"
		visible: true
		property int currentPicture: 0

		anchors.bottom: infoButton.top
		anchors.bottomMargin: height/4
		anchors.horizontalCenter: main.horizontalCenter

		states:[
			State {name: "0";PropertyChanges { target: deleteModeButton; source: "qrc:/qml/qml/delete button.png"}},
			State {name: "1";PropertyChanges { target: deleteModeButton; source: "qrc:/qml/qml/deleting.png"}}
		]
		onCurrentPictureChanged: {deleteModeButton.state = currentPicture.toString();}
		MouseArea {
			id: deleteModeButtonMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				deleteModeButtonMouseArea.clicked.connect(parent.analizeDeleteMode)
			}
		}
		function changePicture(){
			currentPicture = (currentPicture + 1) % 2
		}
		function analizeDeleteMode(){
			changePicture()
			if(deleteModeButton.currentPicture == 0){
				main.deleteMode(false)
			} else {
				main.deleteMode(true)
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
			State {name: "0";PropertyChanges { target: arrowButton; source: "qrc:/qml/arrow right.png"}},
			State {name: "1";PropertyChanges { target: arrowButton; source: "qrc:/qml/arrow left.png"}}
		]
		onCurrentPictureChanged: {arrowButton.state = currentPicture.toString()}
		MouseArea {
			id: arrowButtonMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				parent.analizeArrow();
			}

//			Component.onCompleted: {
//				arrowButtonMouseArea.clicked.connect(parent.analizeArrow)
//			}
		}
		function changePicture(){
			currentPicture = (currentPicture + 1) % 2
		}
		function analizeArrow(){
			changePicture()
			main.arrowPressed()
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

	onIsFightChanged: {
		if (isFight){
			arrowButton.visible = true; infoButton.visible = false; buttonReady.visible = false;
			autoButton.visible = false; plrField.enabled = false; deleteModeButton.visible = false;
			arrowButton.currentPicture = 0;

		} else{
			arrowButton.visible = false; infoButton.visible = true; buttonReady.visible = true;
			autoButton.visible = true; plrField.visible = true; enemyField.visible = false; plrField.enabled = true
			deleteModeButton.visible = true; deleteModeButton.currentPicture = 0; infoButton.currentPicture = 0
			timer.visible = false
		}
	}
}
