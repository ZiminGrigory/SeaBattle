#ifndef QMLFIELD_H
#define QMLFIELD_H

#include "InterfaceField.h"

class QmlField : public InterfaceField
{
	Q_OBJECT
public:
	QmlField();

	void showAttackStatus(AttackStatus status);
	void showResult(Players player);
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
};

#endif // QMLFIELD_H
