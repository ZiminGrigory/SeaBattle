#ifndef FIELDVIEW_H
#define FIELDVIEW_H
#pragma once
#include <QObject>
#include <QSharedPointer>
#include "field.h"
#include "types.h"

class FieldView: public QObject
{
Q_OBJECT
public:
	FieldView();
    QSharedPointer<Field> getField();
public slots:
	void setEnabled(bool enabled);
    void repaint(int id, Textures texture);
private slots:
    void reEmitAttack(int id);
    void reEmitPlaceShip(int firstId, int secondId);
    void reEmitDeleteShip(int id);
private:
	QSharedPointer<Field> mField;
signals:
	void attack(int id);
	void placeShip(int firstId, int secondId);
	void deleteShip(int id);
};

#endif // FIELDVIEW_H
