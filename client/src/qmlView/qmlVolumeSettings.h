#ifndef QMLVOLUMESETTINGS_H
#define QMLVOLUMESETTINGS_H

#include "InterfaceVolumeSettings.h"

class QmlVolumeSettings : public InterfaceVolumeSettings
{
	Q_OBJECT
public:
	QmlVolumeSettings();

signals:
	void changeVolume(int volume);
	void mute(bool switcher);
	void buttonBackPushed();
};

#endif // QMLVOLUMESETTINGS_H
