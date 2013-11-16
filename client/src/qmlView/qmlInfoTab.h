#ifndef QMLINFOTAB_H
#define QMLINFOTAB_H

#include "InterfaceInfoTab.h"
#include <QSharedPointer>

class QmlInfoTab : public InterfaceInfoTab
{
	Q_OBJECT
public:
	QmlInfoTab(QObject* _buttonAutoSetting
			   , QObject* _buttonReady
			   , QObject* _shipCounter);

	void clearItself();
public slots:
	void changeCounter(NameOfShips ship, int difference);
	void playerReady(Players player);

signals:
	void readyToFight();
	void needAutoSetting();

private:
	QObject* buttonAutoSetting;
	QObject* buttonReady;
	QObject* shipCounter;
	int countOfShip;

private slots:
	void handleReadyButton();
};

#endif // QMLINFOTAB_H
