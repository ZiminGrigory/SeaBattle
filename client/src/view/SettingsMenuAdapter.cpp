#include "SettingsMenuAdapter.h"

SettingsMenuAdapter::SettingsMenuAdapter(QSharedPointer<SettingsMenu> _mAdaptee): mAdaptee(_mAdaptee)
{
	connect(mAdaptee.data(), SIGNAL(mute(bool switcher)), SIGNAL(mute(bool switcher)));
	connect(mAdaptee.data(), SIGNAL(volumeChanched(int i)), SIGNAL(volumeChanched(int i)));
	connect(mAdaptee.data(), SIGNAL(buttonBackPushed()), SIGNAL(buttonBackPushed()));
}
