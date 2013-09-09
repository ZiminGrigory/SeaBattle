#ifndef INFOTABVIEW_H
#define INFOTABVIEW_H
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
    QSharedPointer<TabOfInformation> getInfoTab();
public slots:
	void changeCounter(NameOfShips ship, int difference);
private slots:
	void reEmitSignal();
private:
	QSharedPointer<TabOfInformation> mInfoTab;
signals:
	void readyToFight();
};

#endif // INFOTABVIEW_H
