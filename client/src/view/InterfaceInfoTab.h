#ifndef INTARFACEINFOTAB_H
#define INTARFACEINFOTAB_H
#include <QWidget>
#include "types.h"

class InterfaceInfoTab: public QWidget
{
public:
	InterfaceInfoTab(QWidget *parent = 0): QWidget(parent){}

public slots:
	virtual void changeCounter(NameOfShips ship, int difference) = 0;

signals:
	void readyToFight();
	void needAutoSetting();
};
#endif // INTARFACEINFOTAB_H
