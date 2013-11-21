#ifndef QMLINFOTAB_H
#define QMLINFOTAB_H

#include "InterfaceInfoTab.h"
#include <QSharedPointer>

class QmlInfoTab : public InterfaceInfoTab
{
	Q_OBJECT
public:
	QmlInfoTab(const QSharedPointer<QObject> &_buttonAutoSetting
			   , const QSharedPointer<QObject> &_buttonReady
			   , const QSharedPointer<QObject> &_shipCounter);

	void clearItself();
public slots:
	void changeCounter(NameOfShips ship, int difference);
	void playerReady(Players player);

signals:
	void readyToFight();
	void needAutoSetting();

private:
	QSharedPointer<QObject> buttonAutoSetting;
	QSharedPointer<QObject> buttonReady;
	QSharedPointer<QObject> shipCounter;
	int countOfShip;

private slots:
	void handleReadyButton();
};

#endif // QMLINFOTAB_H
