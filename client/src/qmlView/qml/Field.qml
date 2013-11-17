import QtQuick 2.0
import "FieldBuilder.js" as FieldBuilder

Rectangle {
	id: main
	property int mSize: 150
	property alias fieldStatus: status.state

	width: mSize
	height: mSize

	Component.onCompleted: FieldBuilder.startNewGame(mSize)

	signal attack(int id);
	signal placeShip(int firstId, int secondId);
	signal deleteShip(int id);

	property variant array

	/*Animated*/Image{
		id: sea
		source: "qrc:/pictures/sea_animation.gif"
		height: mSize
		width: mSize
	}

	FieldMessage {
		id: status
	}
}
