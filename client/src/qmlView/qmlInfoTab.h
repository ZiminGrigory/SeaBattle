#ifndef QMLINFOTAB_H
#define QMLINFOTAB_H

#include "InterfaceInfoTab.h"

class QmlInfoTab : public InterfaceInfoTab
{
	Q_OBJECT
public:
	QmlInfoTab();

	void clearItself();
public slots:
	void changeCounter(NameOfShips ship, int difference);
	void playerReady(Players player);

signals:
	void readyToFight();
	void needAutoSetting();
};

#endif // QMLINFOTAB_H
