#include "qmlField.h"
#include "QDebug"
#include "types.h"
const QString QmlField::componentUrl = "qml/qml/Field.qml";

QmlField::QmlField(const QSharedPointer<QObject> &fieldWidget):
	mFieldWidgetObject(fieldWidget)
{
	mFieldWidget = QSharedPointer<QObject>(qobject_cast<QObject*>(mFieldWidgetObject.data()));
	mField = mFieldWidget->property("array").toList();
	//qDebug() << mField;
	//connect(mFieldWidget.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
	//connect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
	connect(mFieldWidget.data(), SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	//repaint(22, WRECK);
}

void QmlField::showAttackStatus(AttackStatus status)
{

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
		connect(mFieldWidget.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		disconnect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		disconnect(mFieldWidget.data(), SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	} else {
		disconnect(mFieldWidget.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		disconnect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		connect(mFieldWidget.data(), SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	}
}

void QmlField::setDeleteShipMode(bool isDeleteMode)
{
	if(isDeleteMode){
		disconnect(mFieldWidget.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		connect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		disconnect(mFieldWidget.data(), SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
	} else{
		disconnect(mFieldWidget.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
		disconnect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
		connect(mFieldWidget.data(), SIGNAL(placeShip(int, int)), this, SIGNAL(placeShip(int,int)));
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
