#include "fieldView.h"

FieldView::FieldView()
{
	mField = QSharedPointer<Field>(new Field);
	connect(mField.data(), SIGNAL(shipOnCells(int,int)), this, SIGNAL(placeShip(int,int)));
	connect(mField.data(), SIGNAL(playerAttackCell(int)), this, SIGNAL(emitAttack(int)));
	connect(mField.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
}

QSharedPointer<Field> FieldView::getField()
{
    return mField;
}

void FieldView::setEnabled(bool enabled)
{
	mField->setEnabled(enabled);
}

void FieldView::repaint(int id, Textures texture)
{
    mField->paintCell(id, texture);
}
