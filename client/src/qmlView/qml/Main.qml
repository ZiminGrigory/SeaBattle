import QtQuick 2.0

Rectangle {
	width: 320
	height: 480
	id: main

	// фон
	Image {
		id: background
		width: main.width
		height: main.height
		source: "image://provider/qml/background.jpg"
	}

	AiLvlMenu{
		id: aiLvlMenu
		width: parent.width
		height: parent.height
		objectName: "AiLvlMenu"
		visible: false
	}

	Battle{
		id: battle
		width: parent.width
		height: parent.height
		objectName: "Battle"
		visible: false
	}

	ConnectWidget{
		id: connectWidget
		width: parent.width
		height: parent.height
		objectName: "ConnectWidget"
		visible: false
	}

	SettingsMenu{
		id: settingsMenu
		width: parent.width
		height: parent.height
		objectName: "SettingsMenu"
		visible: false
	}

	StartMenu{
		id: startMenu
		width: parent.width
		height: parent.height
		objectName: "StartMenu"
		visible: false
	}

	function hideAllWidgets(){
		aiLvlMenu.visible = false;
		battle.visible = false;
		connectWidget.visible = false;
		settingsMenu.visible = false;
		startMenu.visible = false;
	}

	states:[
		State{
			name: "AiLvlMenu"
			PropertyChanges { target: aiLvlMenu; visible: true}
		},
		State{
			name: "Battle"
			PropertyChanges { target: battle; visible: true}
		},
		State{
			name: "ConnectWidget"
			PropertyChanges { target: connectWidget; visible: true}
		},
		State{
			name: "SettingsMenu"
			PropertyChanges { target: settingsMenu; visible: true}
		},
		State{
			name: "StartMenu"
			PropertyChanges { target: startMenu;  visible: true}
		}
	]
}
