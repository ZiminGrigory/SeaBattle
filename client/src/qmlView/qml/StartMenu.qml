import QtQuick 2.0


Rectangle {
	id: main

	width: 240
	height: 320

	// сигналы для внешнего мира :)
	signal vsAiClicked()
	signal vsPlayerClicked()
	signal settingsClicked()
	signal quitClicked()

//<<<<<<< HEAD
//	// фон
//	Image {
//		id: background
//		width: main.width
//		height: main.height
//		// чтобы подхватить картинку из ресурсов, пишем image://, потом имя имэйдж провайдера (см QmlMainWindow)
//		// потом адрес картинке в ресурсах
//		source: "image://provider/qml/background.jpg"
//	}

//	Image {
//		id: startTitle
//		width: main.width
//		height: main.height / 9
//		anchors.top: main.top
//		anchors.topMargin: height / 1.5
//		source: "qrc:/qml/qml/startTitle.png"
//	}

//	// свои qml компоненты, которые лежат в той же директории, можно спокойно добавлять
//	ShipButton {
//		id: vsPlayerButton
//		// крепим эту кнопку к верху родителя с отступом 1/4 длины родителя
//		anchors.top: parent.top
//		anchors.topMargin: parent.height / 4

//		type: 0
//		angle: 5

//		// чтобы ловить события мыши в этом элементе
//		MouseArea {
//			id: vsPlayerMouseArea
//			width: parent.width
//			height: parent.height
//			Component.onCompleted: {
//				// когда эта штука создасться, коннектим сигнал от маус ареа к нашему сигналу
//				vsPlayerMouseArea.clicked.connect(main.vsPlayerClicked)
//			}
//		}
//	}

//	ShipButton {
//		id: vsAiButton
//		anchors.top: vsPlayerButton.bottom
//		anchors.topMargin: 5
//=======
	Menu {
		id: menu


		width: parent.width
		height: parent.height

		topShipButtonType: 0
		bottomShipButtonType: 1
		leftBombButtonType: 0
		rightBombButtonType: 1

		Component.onCompleted: {
			menu.topShipButton.clicked.connect(vsAiClicked)
			menu.bottomShipButton.clicked.connect(vsPlayerClicked)
			menu.leftBombButton.clicked.connect(settingsClicked)
			menu.rightBombButton.clicked.connect(quitClicked)
		}
	}
}
