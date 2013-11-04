#include "fieldAdapter.h"

FieldAdapter::FieldAdapter(const QSharedPointer<Field> adaptee) :
	mAdaptee(adaptee)
{
	connect(mAdaptee.data(), SIGNAL(attack(int)), this, SIGNAL(attack(int)));
	connect(mAdaptee.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
	connect(mAdaptee.data(), SIGNAL(placeShip(int,int)), this, SIGNAL(placeShip(int,int)));
	connect(mAdaptee.data(), SIGNAL(setFirstArrows(int)), this, SIGNAL(setFirstArrows(int)));
	connect(mAdaptee.data(), SIGNAL(setNextArrow(int)), this, SIGNAL(setNextArrow(int)));
}

void FieldAdapter::showAttackStatus(AttackStatus status)
{
	mAdaptee->showAttackStatus(status);
}

void FieldAdapter::showResult(Players player)
{
	mAdaptee->showResult(player);
}

void FieldAdapter::addImage(int id, ImageID iD)
{
	mAdaptee->addImage(id, iD);
}

void FieldAdapter::removeImageFromCell(int id)
{
	mAdaptee->removeImageFromCell(id);
}

void FieldAdapter::clearItself()
{
	mAdaptee->clearItself();
}

void FieldAdapter::setAttackable(bool attackable)
{
	mAdaptee->setAttackable(attackable);
}

void FieldAdapter::setEnabledItself(bool switcher)
{
	mAdaptee->setEnabledItself(switcher);
}

void FieldAdapter::repaint(int id, Textures texture)
{
	mAdaptee->repaint(id, texture);
}
