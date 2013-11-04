#ifndef INTERFACESETTINGSMENU_H
#define INTERFACESETTINGSMENU_H

#include "InterfaceNetworkSettings.h"
#include "InterfaceVolumeSettings.h"

class InterfaceSettingsMenu : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceSettingsMenu() {}
signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();
};
#endif // INTERFACESETTINGSMENU_H
