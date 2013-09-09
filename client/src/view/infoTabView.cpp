#include "infoTabView.h"

InfoTabView::InfoTabView()
{
	mInfoTab = QSharedPointer<TabOfInformation>(new TabOfInformation);
    connect(mInfoTab.data(), SIGNAL(fieldIsReady()), this, SLOT(reEmitSignal()));
}

QSharedPointer<TabOfInformation> InfoTabView::getInfoTab()
{
    return mInfoTab;
}

void InfoTabView::changeCounter(NameOfShips ship, int difference)
{
	mInfoTab->changeCountOfShip(ship, difference);
}

void InfoTabView::reEmitSignal()
{
	emit readyToFight();
}

