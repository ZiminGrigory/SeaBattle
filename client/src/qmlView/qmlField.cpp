#include "qmlField.h"
#include "QDebug"
#include "types.h"

QmlField::QmlField(QObject* fieldWidget):
	mFieldWidget(fieldWidget)
{
	mField = mFieldWidget->property("array").toList();
	//qDebug() << mField;
	//connect(mFieldWidget.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
	//connect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
	connect(mFieldWidget, SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
}

void QmlField::showAttackStatus(AttackStatus status)
{
	QString state = "";

	switch (status) {
		case MISS:
			state = "miss";
			break;
		case WOUNDED:
			state = "wounded";
			break;
		case KILLED:
			state = "killed";
			break;
	}
	if (state != "") {
		mFieldWidget->setProperty("fieldStatus", state);
	}
}

void QmlField::showResult(Players player)
{

}

void QmlField::addImage(int id, ImageID iD)
{

}

void QmlField::removeImageFromCell(int id)
{

}

void QmlField::clearItself()
{
	for( int i = 0; i < mField.length(); i++){
		repaint(i,EMPTY);
	}
}

void QmlField::setAttackable(bool attackable)
{

}

void QmlField::setBattleMode(bool isBattle)
{
	if(isBattle){
		connect(mFieldWidget, SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		disconnect(mFieldWidget, SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		disconnect(mFieldWidget, SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	} else {
		disconnect(mFieldWidget, SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		disconnect(mFieldWidget, SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		connect(mFieldWidget, SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	}
}

void QmlField::setDeleteShipMode(bool isDeleteMode)
{
	if(isDeleteMode){
		disconnect(mFieldWidget, SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		connect(mFieldWidget, SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		disconnect(mFieldWidget, SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	} else{
		disconnect(mFieldWidget, SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		disconnect(mFieldWidget, SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		connect(mFieldWidget, SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	}
}

void QmlField::setEnabledItself(bool switcher)
{

}

void QmlField::repaint(int id, Textures texture)
{
	QObject * obj = qvariant_cast<QObject *>(mField.at(id));
	obj->setProperty("currentState",int(texture));
}

void QmlField::showPlacementStatus(PlacementStatus res, int firstId, int secondId)
{
	QString resState = "";
	switch (res) {
		case OK:
			resState = "ок";
			break;
		case UNCORRECT_COORDINATES:
			resState = "uncorrect coordinates";
			break;
		case NOT_LINE:
			resState = "not line";
			break;
		case HAVE_NOT_SHIP:
			resState = "have not ship";
			break;
		case CELL_OCCUPIED:
			resState = "cell occupied";
			break;
	}
	QVariant qvarRes = QVariant(resState);
	QVariant qvarId = QVariant(secondId);

	QMetaObject::invokeMethod(mFieldWidget, "showPlacementResult", Q_ARG(QVariant, qvarId), Q_ARG(QVariant, qvarRes));
}
