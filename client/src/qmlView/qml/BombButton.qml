import QtQuick 2.0

Rectangle {
	id: bomb
	width: parent.width / 4
	height: width
	color: "transparent"

	property int type
	property int startX
	property int startY
	x: startX
	y: startY

	function randomAddition(pos) {
		var rand = Math.round(Math.random() * 10);
		var direction = Math.round(Math.random() * 2);
		if (direction) {
			return pos + rand;
		}
		else {
			return pos - rand;
		}
	}

	SequentialAnimation {
		running: true
		loops: Animation.Infinite
		ParallelAnimation {
			NumberAnimation { target: bomb; property: "x"; to: randomAddition(startX) ; duration: 2000; }
			NumberAnimation { target: bomb; property: "y"; to: randomAddition(startY) ; duration: 2000; }
		}
		ParallelAnimation {
			NumberAnimation { target: bomb; property: "x"; to: startX; duration: 2000; }
			NumberAnimation { target: bomb; property: "y"; to: startY; duration: 2000; }
		}
	}

	Image {
		id: bombImg
		width: parent.width
		height: parent.height
		property string quitPath: "image://imageProvider/quit_button.png"
		property string settingPath: "image://imageProvider/settings_button.png"
		source: parent.type == 1 ? quitPath : settingPath
	}
}
