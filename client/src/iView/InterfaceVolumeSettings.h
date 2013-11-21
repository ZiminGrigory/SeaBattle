#ifndef INTERFACESETTINGS_H
#define INTERFACESETTINGS_H

#include <QWidget>
#include "types.h"

class InterfaceVolumeSettings : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceVolumeSettings() {}
signals:
	void changeVolume(int volume);
	void mute(bool switcher);
	void buttonBackPushed();
};
#endif // INTERFACESETTINGS_H
