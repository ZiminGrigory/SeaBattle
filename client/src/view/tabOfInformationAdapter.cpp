#include "tabOfInformationAdapter.h"

TabOfInformationAdapter::TabOfInformationAdapter(const QSharedPointer<TabOfInformation>& adaptee) :
	mAdaptee(adaptee)
{
	connect(mAdaptee.data(), SIGNAL(needAutoSetting()), this, SIGNAL(needAutoSetting()));
	connect(mAdaptee.data(), SIGNAL(readyToFight()), this, SIGNAL(readyToFight()));
}

void TabOfInformationAdapter::clearItself()
{
	mAdaptee->clearItself();
}

void TabOfInformationAdapter::changeCounter(NameOfShips ship, int difference)
{
	mAdaptee->changeCounter(ship, difference);
}

void TabOfInformationAdapter::playerReady(Players player)
{
	mAdaptee->playerReady(player);
}
