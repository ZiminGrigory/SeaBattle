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

	PlacementResultText {
		id: placementResult
		z: 10
	}

	// int lastId - id of chell on which result will shown
	// string result - result as a string (see PlacementResult states)
	function showPlacementResult(lastId, result) {
//		var cellSize = mSize / 10;
//		var row = Math.floor(lastId / 10);
//		var col = lastId % 10;
//		var x = row * cellSize;
//		var y = col * cellSize;
//		placementResult.x = x;
//		placementResult.y = y;
		placementResult.state = result;
	}
}
