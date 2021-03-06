#ifndef FIELDADAPTER_H
#define FIELDADAPTER_H

#include "InterfaceField.h"
#include "field.h"

class FieldAdapter : public InterfaceField
{
	Q_OBJECT
public:
	FieldAdapter(const QSharedPointer<Field>& adaptee);

	void showAttackStatus(AttackStatus status);
	void showResult(Players player);
	void addImage(int id, ImageID iD);
	void removeImageFromCell(int id);
	void clearItself();
	void setAttackable(bool attackable);

public slots:
	void setEnabledItself(bool switcher);
	void repaint(int id, Textures texture);
	void showPlacementStatus(PlacementStatus res, int firstId, int secondId);

signals:
	void attack(int id);
	void placeShip(int firstId, int secondId);
	void deleteShip(int id);
	void setFirstArrows(int id);
	void setNextArrow(int id);

private:
	QSharedPointer<Field> mAdaptee;
};

#endif // FIELDADAPTER_H
