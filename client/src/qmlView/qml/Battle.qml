import QtQuick 2.0

Rectangle {
	id: main
	width: 320
	height: 480

	function switchToPlayerField() {
		enemyField.visible = false;
		plrField.visible = true;
		arrowButton.currentPicture ="right"
		countOfShip.currentNumber = countOfPlr;
		plrField.fieldStatus = "enemy_turn"
	}

	function switchToEnemyField() {
		plrField.visible = false;
		enemyField.visible = true;
		arrowButton.currentPicture ="left"
		countOfShip.currentNumber = countOfEnemy;
		enemyField.fieldStatus = "you_turn"
	}

	signal arrowPressed()
	signal deleteMode(bool isActive)
	signal buttonBackPressed();


	property int countOfFleet: 10;
	property int countOfPlr: 10;
    property int countOfEnemy: 10;

    onCountOfPlrChanged: {
        if (plrField.visible == true) {
            countOfShip.currentNumber = countOfPlr
        }
    }

    onCountOfEnemyChanged: {
        if (enemyField.visible == true) {
            countOfShip.currentNumber = countOfEnemy
        }
    }

	property bool isFight: false;



	Dialog{
		id: dialogs
		objectName: "dialogs"
		visible: false
		z: 10
	}

	EndDialog{
		id: endDialog
		objectName: "endDialogs"
		visible: false
		z: 8
		onToMainMenu: visible = false
	}

	Text{
		id:lableCountOfShip
		anchors.top: main.top
		width: main.width / 4 * 2
		height: main.height / 10
		style: Text.Outline; styleColor: "black"
		text: "Корабли: "
		font.family: "Helvetica"
		font.pixelSize: height * 0.8
		color: "white"
	}

	Text{
		objectName: "mCountOfShip"
		id:countOfShip
		property int currentNumber: 10
		property alias uncompletedFleetAnimationRun: uncompletedFleetAnimation.running


		width: lableCountOfShip.width / 2
		height: main.height / 10
		anchors.left: lableCountOfShip.right
		anchors.leftMargin: 5
		style: Text.Outline; styleColor: "black"
		text: "10"
		font.family: "Helvetica"
		font.pixelSize: height * 0.8
		color: "white"
		onCurrentNumberChanged: {countOfShip.text = currentNumber.toString()}
		z: 8;

		SequentialAnimation {
			id: uncompletedFleetAnimation
			running: false
			loops: 2

			ParallelAnimation {
				ColorAnimation { target: countOfShip; property: "color"; to: "red"; duration: 300 }
				NumberAnimation { target: countOfShip; property: "font.pointSize"; to: countOfShip.height; duration: 300 }
			}
			ParallelAnimation {
				ColorAnimation { target: countOfShip; property: "color"; to: "white"; duration: 300 }
				NumberAnimation { target: countOfShip; property: "font.pointSize"; to: lableCountOfShip.font.pointSize; duration: 300 }
			}
		}
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
		id: timerText
		visible: false
		width:height
		height: countOfShip.height
		anchors.left: countOfShip.right
		property int currentTime: 22;
		style: Text.Outline; styleColor: "white"
		text: currentTime.toString()
		font.family: "Helvetica"
		font.pointSize: height / 1.5
		color: "black"
		onVisibleChanged: {
			timer.running = true
		}
		onCurrentTimeChanged: text = currentTime.toString()
	}


	Timer {
		id: timer
		interval: 1000; running: false; repeat: true
		onTriggered:{
			if (timerText.currentTime != 0)
				timerText.currentTime = timerText.currentTime - 1
		}
	}

	Field{
		objectName:"mPlrField"
		id: plrField
		z: 1
		//enabled: true
		visible: true
		mSize: main.width * 0.9 - (main.width % 10)
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: lableCountOfShip.bottom
		anchors.topMargin: 3
	}

	Field{
		objectName:"mEnemyField"
		id: enemyField
		visible: false
		z: 1
		//enabled: true
		mSize: main.width * 0.9 - (main.width % 10)
		anchors.horizontalCenter: main.horizontalCenter
		anchors.top: lableCountOfShip.bottom
		anchors.topMargin: 3
	}

	BombButton {
		id: backButton
		type: 3
		z: 9
		anchors.right: parent.right
		anchors.bottom: parent.bottom

		MouseArea {
			id: backMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				backMouseArea.clicked.connect(main.buttonBackPressed)
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
		onEnabledChanged: {
			if (buttonReady.enabled == false){
				readyState.visible = true
			}
		}
	}

	Image{
		id: readyState
		width: main.width
		height: main.height
		source: "qrc:/qml/qml/ready_state.png"
		visible: false
		z : 2
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
            onClicked: {
                parent.changePicture()
                girl.visible = true
            }
		}
		function changePicture(){
			currentPicture = (currentPicture + 1) % 2
		}
	}

    InfoGirl{
        id: girl
		z: 15
        visible: false
        mCurrentState: 0
        currentState: mCurrentState.toString()
        onCloseMe: {
            infoButton.changePicture()
            girl.visible = false
            girl.mCurrentState = 0
            girl.currentState = girl.mCurrentState.toString()
        }
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
		property string currentPicture: "right"
		anchors.horizontalCenter: main.horizontalCenter
		anchors.bottom: main.bottom
		anchors.bottomMargin: height / 4
		states:[
			State {name: "right";PropertyChanges { target: arrowButton; source: "qrc:/qml/arrow right.png"}},
			State {name: "left";PropertyChanges { target: arrowButton; source: "qrc:/qml/arrow left.png"}}
		]
		onCurrentPictureChanged: {arrowButton.state = currentPicture.toString()}
		MouseArea {
			id: arrowButtonMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				parent.analizeArrow();
			}

		}
		function changePicture(){
			if (currentPicture == "right"){
				currentPicture ="left"
			} else{
				currentPicture = "right"
			}
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

	function prepareWelcomeMode(){
		arrowButton.visible = false;
		infoButton.visible = true;
		buttonReady.visible = true;
		autoButton.visible = true;
		plrField.visible = true;
		enemyField.visible = false;
		//plrField.enabled = true
		deleteModeButton.visible = true;
		deleteModeButton.currentPicture = 0;
		infoButton.currentPicture = 0
		timer.visible = false;
		countOfShip.currentNumber = countOfFleet;
		timer.running = false;
		readyState.visible = false; endDialog.visible = false
	}

	function prepareToFight(){
		arrowButton.visible = true; infoButton.visible = false; buttonReady.visible = false;
		autoButton.visible = false; /*plrField.enabled = false;*/ deleteModeButton.visible = false;
		arrowButton.currentPicture = 0; countOfShip.currentNumber = countOfPlr;
		readyState.visible = false; endDialog.visible = false
	}
}
