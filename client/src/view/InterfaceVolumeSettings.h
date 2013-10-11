#ifndef INTERFACESETTINGS_H
#define INTERFACESETTINGS_H
#include <QWidget>
#include "types.h"

class InterfaceVolumeSettings: public QWidget
{
public:
	InterfaceVolumeSettings(QWidget *parent = 0): QWidget(parent){}

signals:
	void changeVolume(int volume);
	void mute(bool switcher);
	void buttonBackPushed();
};
#endif // INTERFACESETTINGS_H
