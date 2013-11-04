#include "SettingsAdapter.h"

SettingsAdapter::SettingsAdapter(QSharedPointer<Settings> _mAdaptee): mAdaptee(_mAdaptee)
{
	connect(mAdaptee.data(), SIGNAL(changeVolume(int volume)), SIGNAL(changeVolume(int volume)));
	connect(mAdaptee.data(), SIGNAL(mute(bool switcher)), SIGNAL(mute(bool switcher)));
	connect(mAdaptee.data(), SIGNAL(buttonBackPushed()), SIGNAL(buttonBackPushed()));
}
