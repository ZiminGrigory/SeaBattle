#include "qmlInfoTab.h"
#include "QDebug"


QmlInfoTab::QmlInfoTab(const QSharedPointer<QObject> &_buttonAutoSetting
					   , const QSharedPointer<QObject> &_buttonReady
					   , const QSharedPointer<QObject> &_shipCounter):
	buttonAutoSetting(_buttonAutoSetting), buttonReady(_buttonReady), shipCounter(_shipCounter), countOfShip(10)
{
	connect(buttonAutoSetting.data(), SIGNAL(needAutoSet()), SIGNAL(needAutoSetting()));
	connect(buttonReady.data(), SIGNAL(ready()), SLOT(handleReadyButton()));
}

void QmlInfoTab::clearItself()
{
	countOfShip = 10;
}

void QmlInfoTab::changeCounter(NameOfShips ship, int difference)
{
	countOfShip += difference;
	shipCounter->setProperty("currentNumber", countOfShip);
}

void QmlInfoTab::playerReady(Players player)
{
	Q_UNUSED(player)
}

void QmlInfoTab::handleReadyButton()
{
	if (shipCounter->property("currentNumber").toInt() == 0){
		qDebug() << "ready";
		emit readyToFight();
	}
}

