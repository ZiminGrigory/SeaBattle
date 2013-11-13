import QtQuick 2.0

Rectangle {
	id: main
	width: 240
	height: 320


	property string port:"12345"
	property string ip:"192.168.0.1"
	property int currentVolumeState: 2

	signal ipAndPort(string ip, string port)
	signal volume(int position)
	signal quitClicked()

	Image {
		id: background
		width: main.width
		height: main.height
		// чтобы подхватить картинку из ресурсов, пишем image://, потом имя имэйдж провайдера (см QmlMainWindow)
		// потом адрес картинке в ресурсах
		source: "image://provider/qml/background.jpg"
	}

	Image{
		id: text
		width: main.width
		height: main.height / 6
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: parent.top
		source: "image://provider/qml/settings.png"
	}

	Image{
		id: plus
		width: main.width/6
		height: main.width/6
		anchors.left: text.left
		anchors.leftMargin: text.width / 7
		anchors.top: text.top
		anchors.topMargin: text.height * 1.3
		source: "image://provider/qml/plus.png"
		MouseArea {
			id: plusMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				if(main.currentVolumeState < 4){
					main.currentVolumeState = main.currentVolumeState + 1
					soundControl.state = soundControl.massivOfStates[main.currentVolumeState]
				}
			}
		}
	}

	Image{
		id: soundControl
		width: main.width/3
		height: main.width/3
		anchors.top: plus.top
		anchors.topMargin: -plus.height / 2
		anchors.left: plus.left
		anchors.leftMargin: plus.width *1.1
		property variant massivOfStates: ["0","1","2","3","4"];

		state: massivOfStates[currentVolumeState]
		states: [
			State {
				name: "0"
				PropertyChanges { target: soundControl; source: "image://provider/qml/sounds_off.png"}
			 },
			 State {
				name: "1"
				PropertyChanges { target: soundControl; source: "image://provider/qml/sounds_0.png"}
			},
			State {
			   name: "2"
			   PropertyChanges { target: soundControl; source: "image://provider/qml/sounds_1.png"}
			},
			State {
				name: "3"
				PropertyChanges { target: soundControl; source: "image://provider/qml/sounds_2.png"}
			 },
			State {
			   name: "4"
			   PropertyChanges { target: soundControl; source: "image://provider/qml/sounds_3.png"}
			}
		 ]
	}

	Image{
		id: minus
		width: main.width/6
		height: main.width/6
		anchors.left: plus.left
		anchors.leftMargin: plus.width* 1.1 + soundControl.width
		anchors.top: text.top
		anchors.topMargin: text.height * 1.3
		source: "image://provider/qml/minus.png"
		MouseArea {
			id: minusMouseArea
			width: parent.width
			height: parent.height
			onClicked: {
				if(main.currentVolumeState != 0){
					main.currentVolumeState = main.currentVolumeState - 1
					soundControl.state = soundControl.massivOfStates[main.currentVolumeState]
				}
			}
		}
	}

	Image{
		id:labelIP
		width: main.width
		height: main.height / 9
		anchors.horizontalCenter: text.horizontalCenter
		anchors.top: text.top
		anchors.topMargin: (text.height + soundControl.height)
		source: "image://provider/qml/label_ip.png"
	 }

	Rectangle{
		id: labelIp_input
		width: labelIP.width / 1.5
		height:	labelIP.height / 1.5
		anchors.horizontalCenter: labelIP.horizontalCenter
		anchors.top: labelIP.top
		anchors.topMargin: labelIP.height * 1.2
		color: "white"
		opacity: 0.6
		TextInput{
			property string _text:"192.168.0.1"
			width: parent.width
			height: parent.height
			id: textInputIP
			color: "black"
			font.pixelSize : height * 0.8
			maximumLength: 15
			text: main.ip
		}
	}

	Image{
		id:labelPort
		width: main.width
		height: main.height / 9
		anchors.horizontalCenter: labelIP.horizontalCenter
		anchors.top: labelIp_input.top
		anchors.topMargin: (labelIp_input.height)* 1.2
		source: "image://provider/qml/label_port.png"
	 }

	Rectangle{
		id: labelPort_input
		width: labelPort.width / 3.5
		height:	labelPort.height / 1.5
		anchors.horizontalCenter: labelPort.horizontalCenter
		anchors.top: labelPort.top
		anchors.topMargin: labelPort.height * 1.2
		color: "white"
		opacity: 0.6
		TextInput{
			width: parent.width
			height: parent.height
			id: textInputPort
			color: "black"
			font.pixelSize : height * 0.8
			maximumLength: 5
			text: main.port
		}
	}

	BombButton {
		id: backButton

		type: 1
		startX: main.width - width - 10
		startY: main.height - height - 10

		MouseArea {
			id: quitMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				quitMouseArea.clicked.connect(main.quitClicked)
			}
			onClicked: {
				ipAndPort(textInputIP.getText(0,textInputIP.maximumLength)
						  , textInputPort.getText(0,textInputPort.maximumLength))
				volume(currentVolumeState)
			}
		}
	}
}




