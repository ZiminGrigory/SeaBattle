#ifndef QMLFIELD_H
#define QMLFIELD_H

#include "InterfaceField.h"
#include <QQuickWindow>
#include <QQuickItem>
#include "types.h"

class QmlField : public InterfaceField
{
	Q_OBJECT
public:
	QmlField(QObject* fieldWidget);

	void showAttackStatus(AttackStatus status);
	void showResult(Players player);
	void addImage(int id, ImageID iD);
	void removeImageFromCell(int id);
	void clearItself();
	void setAttackable(bool attackable);

	void setBattleMode(bool isBattle);
	void setDeleteShipMode(bool isDeleteMode);

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

	QObject* mFieldWidget;
	QVariantList mField;
};

#endif // QMLFIELD_H
