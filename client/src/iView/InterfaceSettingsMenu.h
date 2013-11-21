#ifndef INTERFACESETTINGSMENU_H
#define INTERFACESETTINGSMENU_H
#include <QWidget>
#include "InterfaceNetworkSettings.h"
#include "InterfaceVolumeSettings.h"

class InterfaceSettingsMenu: public QWidget
{
public:
	InterfaceSettingsMenu(QWidget *parent = 0): QWidget(parent){}

signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();
};
#endif // INTERFACESETTINGSMENU_H
