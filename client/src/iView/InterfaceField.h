#ifndef INTERFACEFIELD_H
#define INTERFACEFIELD_H

#include <QWidget>
#include "types.h"

class InterfaceField : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceField() {}
	virtual void showAttackStatus(AttackStatus status) = 0;
	virtual void showResult(Players player) = 0;
	virtual void addImage(int id, ImageID iD) = 0;
	virtual void removeImageFromCell(int id) = 0;
	virtual void clearItself() = 0;
	virtual void setAttackable(bool attackable) = 0;

public slots:
	virtual void setEnabledItself(bool switcher) = 0;
	virtual void repaint(int id, Textures texture) = 0;

signals:
	void attack(int id);
	void placeShip(int firstId, int secondId);
	void deleteShip(int id);
	void setFirstArrows(int id);
	void setNextArrow(int id);
};
#endif // INTERFACEFIELD_H
