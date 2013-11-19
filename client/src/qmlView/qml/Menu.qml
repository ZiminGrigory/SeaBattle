import QtQuick 2.0

Rectangle {
	id: menu

	property alias topShipButtonType: topShipButton.type
	property alias bottomShipButtonType: bottomShipButton.type
	property alias leftBombButtonType: leftBombButton.type
	property alias rightBombButtonType: rightBombButton.type

	property alias topShipButton: topShipButtonMouseArea
	property alias bottomShipButton: bottomShipButtonMouseArea
	property alias leftBombButton: leftBombButtonMouseArea
	property alias rightBombButton: rightBombButtonMouseArea

		Image {
			id: startTitle
			width: menu.width
			height: menu.height / 5
			anchors.top: menu.top
			source: "qrc:/qml/qml/sea_battle_title.png"
		}

	// свои qml компоненты, которые лежат в той же директории, можно спокойно добавлять
	ShipButton {
		id: topShipButton
		// крепим эту кнопку к верху родителя с отступом 1/4 длины родителя
		anchors.top: parent.top
		anchors.topMargin: parent.height / 4

		angle: 5

		// чтобы ловить события мыши в этом элементе
		MouseArea {
			id: topShipButtonMouseArea
			width: parent.width
			height: parent.height
		}
	}

	ShipButton {
		id: bottomShipButton
		anchors.top: topShipButton.bottom
		anchors.topMargin: 5

		angle: -3

		MouseArea {
			id: bottomShipButtonMouseArea
			width: parent.width
			height: parent.height
		}
	}

	BombButton {
		id: leftBombButton

//		startX: 10
//		startY: parent.height - height - 10

		anchors.left: parent.left
		anchors.bottom: parent.bottom

		MouseArea {
			id: leftBombButtonMouseArea
			width: parent.width
			height: parent.height
		}
	}

	BombButton {
		id: rightBombButton

//		startX: parent.width - width - 10
//		startY: parent.height - height - 10

		anchors.right: parent.right
		anchors.bottom: parent.bottom

		MouseArea {
			id: rightBombButtonMouseArea
			width: parent.width
			height: parent.height
		}
	}
}
