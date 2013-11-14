import QtQuick 2.0

Rectangle {
	id: main
	width: 240
	height: 320

	// сигналы для внешнего мира :)
	signal vsAiSimpleClicked()
	signal vsAihardClicked()
	signal quitClicked()

	// фон
	Image {
		id: background
		width: main.width
		height: main.height
		// чтобы подхватить картинку из ресурсов, пишем image://, потом имя имэйдж провайдера (см QmlMainWindow)
		// потом адрес картинке в ресурсах
		source: "image://provider/qml/background.jpg"
	}

	// свои qml компоненты, которые лежат в той же директории, можно спокойно добавлять
	ShipButton {
		id: vsAiSimpleButton
		// крепим эту кнопку к верху родителя с отступом 1/4 длины родителя
		anchors.top: parent.top
		anchors.topMargin: parent.height / 4

		type: 2
		angle: 5

		// чтобы ловить события мыши в этом элементе
		MouseArea {
			id: vsPlayerMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				// когда эта штука создасться, коннектим сигнал от маус ареа к нашему сигналу
				vsPlayerMouseArea.clicked.connect(main.vsAiSimpleClicked)
			}
		}
	}

	ShipButton {
		id: vsAiHardButton
		anchors.top: vsAiSimpleButton.bottom
		anchors.topMargin: 5

		type: 3
		angle: -3

		MouseArea {
			id: vsAiMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				vsAiMouseArea.clicked.connect(main.vsAihardClicked)
			}
		}
	}

	BombButton {
		id: quitButton

		type: 3
		startX: parent.width - width - 10
		startY: parent.height - height - 10

		MouseArea {
			id: quitMouseArea
			width: parent.width
			height: parent.height
			Component.onCompleted: {
				quitMouseArea.clicked.connect(main.quitClicked)
			}
		}
	}
}
