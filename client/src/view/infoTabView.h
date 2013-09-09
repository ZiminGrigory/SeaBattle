#pragma once
#include <QObject>
#include <QSharedPointer>
#include "tabOfInformation.h"
#include "types.h"

class InfoTabView:public QObject
{
Q_OBJECT
public:
	InfoTabView();
public slots:
	void changeCounter(NameOfShips ship, int difference);
private:
	QSharedPointer<TabOfInformation> mInfoTab;
signals:
	void readyToFight();
	void needAutoSetting();
};
