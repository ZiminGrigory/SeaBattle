#include "SettingsMenuAdapter.h"

SettingsMenuAdapter::SettingsMenuAdapter(const QSharedPointer<SettingsMenu>& _mAdaptee): mAdaptee(_mAdaptee)
{
	connect(mAdaptee.data(), SIGNAL(mute(bool)), SIGNAL(mute(bool)));
	connect(mAdaptee.data(), SIGNAL(volumeChanched(int)), SIGNAL(volumeChanched(int)));
	connect(mAdaptee.data(), SIGNAL(buttonBackPushed()), SIGNAL(buttonBackPushed()));
}
