import QtQuick 2.0

Rectangle {
	id: main

	width: 240
	height: 320

	// сигналы для внешнего мира :)
	signal vsAiSimpleClicked()
	signal vsAihardClicked()
	signal quitClicked()

	Menu {
		id: menu

		width: parent.width
		height: parent.height

		topShipButtonType: 2
		bottomShipButtonType: 3
		//leftBombButtonType: 9
		rightBombButtonType: 1

		Component.onCompleted: {
			menu.topShipButton.clicked.connect(vsAiSimpleClicked)
			menu.bottomShipButton.clicked.connect(vsAihardClicked)
			menu.rightBombButton.clicked.connect(quitClicked)
		}
	}
}
