#ifndef SETTINGSADAPTER_H
#define SETTINGSADAPTER_H
#include "InterfaceVolumeSettings.h"
#include "Settings.h"
#include <QSharedPointer>
class SettingsAdapter : public InterfaceVolumeSettings
{
public:
	SettingsAdapter(QSharedPointer<Settings> _mAdaptee);

signals:
	void changeVolume(int volume);
	void mute(bool switcher);
	void buttonBackPushed();

private:
	QSharedPointer<Settings> mAdaptee;
};
#endif // SETTINGSADAPTER_H
