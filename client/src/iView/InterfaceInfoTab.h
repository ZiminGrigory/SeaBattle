#ifndef INTARFACEINFOTAB_H
#define INTARFACEINFOTAB_H

#include <QWidget>
#include "types.h"

class InterfaceInfoTab : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceInfoTab() {}
	virtual void clearItself() = 0;
public slots:
	virtual void changeCounter(NameOfShips ship, int difference) = 0;
	virtual void playerReady(Players player) = 0;

signals:
	void readyToFight();
	void needAutoSetting();
};
#endif // INTARFACEINFOTAB_H
