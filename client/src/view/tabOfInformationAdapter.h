#ifndef TABOFINFORMATIONADAPTER_H
#define TABOFINFORMATIONADAPTER_H

#include <InterfaceInfoTab.h>
#include <tabOfInformation.h>

class TabOfInformationAdapter : public InterfaceInfoTab
{
public:
	TabOfInformationAdapter();

	void clearItself();
public slots:
	void changeCounter(NameOfShips ship, int difference);
	void playerReady(Players player);

signals:
	void readyToFight();
	void needAutoSetting();
private:
	TabOfInformation mAdaptee;
};

#endif // TABOFINFORMATIONADAPTER_H
