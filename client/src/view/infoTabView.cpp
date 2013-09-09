#include "infoTabView.h"

InfoTabView::InfoTabView()
{
	mInfoTab = QSharedPointer<TabOfInformation>(new TabOfInformation);
	connect(mInfoTab.data(), SIGNAL(fieldIsReady()), this, SIGNAL(readyToFight()));
	connect(mInfoTab.data(), SIGNAL(needAutoSetting()), this, SIGNAL(needAutoSetting()));
}

void InfoTabView::changeCounter(NameOfShips ship, int difference)
{
	mInfoTab->changeCountOfShip(ship, difference);
}
