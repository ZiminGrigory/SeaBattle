import QtQuick 2.0
import "FieldBuilder.js" as FieldBuilder

Rectangle {
	id: main
	property int mSize: 150

	width: mSize
	height: mSize

	Component.onCompleted: FieldBuilder.startNewGame(mSize)


	signal attack(int id);
	signal placeShip(int firstId, int secondId);
	signal deleteShip(int id);

	property variant array

	AnimatedImage{
		id: sea
		source: "qrc:/pictures/sea_animation.gif"
		playing: true
		height: mSize
		width: mSize
	}
}
