#include "tabOfInformationAdapter.h"

TabOfInformationAdapter::TabOfInformationAdapter()
{
	connect(&mAdaptee, SIGNAL(needAutoSetting()), this, SIGNAL(needAutoSetting()));
	connect(&mAdaptee, SIGNAL(readyToFight()), this, SIGNAL(readyToFight()));
}

void TabOfInformationAdapter::clearItself()
{
	mAdaptee.clearItself();
}

void TabOfInformationAdapter::changeCounter(NameOfShips ship, int difference)
{
	mAdaptee.changeCounter(ship, difference);
}

void TabOfInformationAdapter::playerReady(Players player)
{
	mAdaptee.playerReady(player);
}
