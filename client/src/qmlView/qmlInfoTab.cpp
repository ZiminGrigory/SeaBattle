#include "qmlInfoTab.h"
#include "QDebug"


QmlInfoTab::QmlInfoTab(QObject* _buttonAutoSetting
					   , QObject* _buttonReady
					   , QObject* _shipCounter):
	buttonAutoSetting(_buttonAutoSetting), buttonReady(_buttonReady), shipCounter(_shipCounter), countOfShip(10)
{
	connect(buttonAutoSetting, SIGNAL(needAutoSet()), SIGNAL(needAutoSetting()));
	connect(buttonReady, SIGNAL(ready()), SLOT(handleReadyButton()));
}

void QmlInfoTab::clearItself()
{
	countOfShip = 10;
	shipCounter->setProperty("currentNumber", countOfShip);
	buttonReady->setProperty("enabled", true);
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
		buttonReady->setProperty("enabled", false);
		emit readyToFight();
	}
}

