import QtQuick 2.0

Rectangle {
	id: main

	width: 320
	height: 480

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
		leftBombButtonType: 9
		rightBombButtonType: 3

		Component.onCompleted: {
			menu.topShipButton.clicked.connect(vsAiSimpleClicked)
			menu.bottomShipButton.clicked.connect(vsAihardClicked)
			menu.rightBombButton.clicked.connect(quitClicked)
		}
	}
}
