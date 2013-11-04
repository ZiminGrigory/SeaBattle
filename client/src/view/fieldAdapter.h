#ifndef FIELDADAPTER_H
#define FIELDADAPTER_H

#include "InterfaceField.h"
#include "field.h"

class FieldAdapter : public InterfaceField
{
	Q_OBJECT
public:
	FieldAdapter(const QSharedPointer<Field> adaptee);

	void showAttackStatus(AttackStatus status) = 0;
	void showResult(Players player) = 0;
	void addImage(int id, ImageID iD);
	void removeImageFromCell(int id);
	void clearItself();
	void setAttackable(bool attackable);

public slots:
	void setEnabledItself(bool switcher);
	void repaint(int id, Textures texture);

signals:
	void attack(int id);
	void placeShip(int firstId, int secondId);
	void deleteShip(int id);
	void setFirstArrows(int id);
	void setNextArrow(int id);

private:
	QSharedPointer<FieldAdapter> mAdaptee;
};

#endif // FIELDADAPTER_H
