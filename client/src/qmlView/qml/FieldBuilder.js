
var maxColumn = 10;
var maxRow = 10;
var maxIndex = maxColumn * maxRow;
var field = new Array(maxIndex);
var sizeOfMain;
var component;
var pressedId;
var cellSize;

function index(column, row) {
	return column + (row * maxColumn);
}

function startNewGame(_sizeOfMain) {
	field = new Array(maxIndex);
	sizeOfMain = _sizeOfMain;
	for (var column = 0; column < maxColumn; column++) {
		for (var row = 0; row < maxRow; row++) {
			field[index(column, row)] = null;
			createBlock(column, row);
		}
	}
	main.array = field;
}

function createBlock(column, row) {
	if (component == null)
		component = Qt.createComponent("Cell.qml");
	// Note that if Block.qml was not a local file, component.status would be
	// Loading and we should wait for the component's statusChanged() signal to
	// know when the file is downloaded and ready before calling createObject().
	if (component.status == Component.Ready) {
		var dynamicObject = component.createObject(sea);
		cellSize = sizeOfMain / 10
		dynamicObject.x = column * cellSize + sea.x;
		dynamicObject.y = row * cellSize + sea.y;
		dynamicObject.width = cellSize;
		dynamicObject.height = cellSize;
		dynamicObject.mId = index(column, row).toString();
		dynamicObject.coordinates = index(column, row);
		dynamicObject.currentState = 0;
		dynamicObject.pressedOnCell.connect(handlePressed);
		dynamicObject.releasedOnCell.connect(handleReleased);
		dynamicObject.clickedOnCell.connect(handleClicked);
		field[index(column, row)] = dynamicObject;
	} else {
		console.log("error loading block component");
		console.log(component.errorString());
		return field
	}
	return true;
}

function handlePressed(id){
	pressedId = id;
}

function handleClicked(id){
	attack(id)
	deleteShip(id)
	console.log(id)
}

function handleReleased(x,y){
	if (x < cellSize && y < cellSize && x > 0 && y > 0){
		placeShip(pressedId, pressedId);
	}
	if (x > cellSize){
		placeShip(pressedId, Math.round(pressedId + integerDivision(x,cellSize)));
		console.log(pressedId, Math.round(pressedId + integerDivision(x,cellSize)));
	} else if (y > cellSize){
		placeShip(pressedId, Math.round(pressedId + integerDivision(y,cellSize)* 10));
		console.log(pressedId, Math.round(pressedId + integerDivision(y,cellSize)* 10));
	} else if (x < 0){
		placeShip(pressedId, Math.round(pressedId + integerDivision(x - cellSize,cellSize)));
		console.log(pressedId, Math.round(pressedId + integerDivision(x - cellSize,cellSize)));
	} else if (y < 0){
		placeShip(pressedId, Math.round(pressedId + integerDivision(y - cellSize,cellSize)* 10));
		console.log(pressedId, Math.round(pressedId + integerDivision(y - cellSize,cellSize)* 10));
	}
}

function integerDivision(x, y){
	return (x-x%y)/y
}
