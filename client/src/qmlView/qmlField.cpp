#include "qmlField.h"
#include "QDebug"
#include "types.h"
const QString QmlField::componentUrl = "qml/qml/Field.qml";

QmlField::QmlField(QSharedPointer<QObject> fieldWidget):mFieldWidget(fieldWidget)
{
	mField = mFieldWidget->property("array").toList();
	connect(mFieldWidget.data(), SIGNAL(attack(int)), this, SLOT(attack(int)));
	connect(mFieldWidget.data(), SIGNAL(deleteShip(int)), this, SLOT(deleteShip(int)));
	connect(mFieldWidget.data(), SIGNAL(placeShip(int, int)), this, SLOT(placeShip(int,int)));
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

void QmlField::setEnabledItself(bool switcher)
{

}

void QmlField::repaint(int id, Textures texture)
{
	QObject * obj = qvariant_cast<QObject *>(mField.at(id));
	obj->setProperty("currentState",int(texture));
	delete obj;
}
