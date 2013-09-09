#include "fieldView.h"

FieldView::FieldView()
{
	mField = QSharedPointer<Field>(new Field);
    connect(mField.data(), SIGNAL(shipOnCells(int,int)), this, SLOT(reEmitPlaceShip(int,int)));
    connect(mField.data(), SIGNAL(playerAttackCell(int)), this, SLOT(reEmitAttack(int)));
    connect(mField.data(), SIGNAL(deleteShip(int)), this, SLOT(reEmitDeleteShip(int)));
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

void FieldView::reEmitAttack(int id)
{
    emit attack(id);
}

void FieldView::reEmitPlaceShip(int firstId, int secondId)
{
    emit placeShip(firstId, secondId);
}

void FieldView::reEmitDeleteShip(int id)
{
    emit deleteShip(id);
}
