#ifndef QMLFIELD_H
#define QMLFIELD_H

#include "InterfaceField.h"
#include <QQuickWindow>
#include <QQuickItem>
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"
#include "types.h"

class QmlField : public InterfaceField
{
	Q_OBJECT
public:
	QmlField(const QSharedPointer<QObject> &fieldWidget);

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

private:
	static const QString componentUrl;

	QSharedPointer<QQuickItem> mFieldWidget;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
	QSharedPointer<QObject> mFieldWidgetObject;
	QVariantList mField;
};

#endif // QMLFIELD_H
