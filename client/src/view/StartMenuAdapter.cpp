#include "StartMenuAdapter.h"

StartMenuAdapter::StartMenuAdapter(QSharedPointer<StartMenu> _mAdaptee): mAdaptee(_mAdaptee)
{
	connect(mAdaptee.data(), SIGNAL(buttonVsPlayerPushed()), SIGNAL(buttonVsPlayerPushed()));
	connect(mAdaptee.data(), SIGNAL(buttonVsPcPushed()), SIGNAL(buttonVsPcPushed()));
	connect(mAdaptee.data(), SIGNAL(buttonExitPushed()), SIGNAL(buttonExitPushed()));
	connect(mAdaptee.data(), SIGNAL(buttonSettingsPushed()), SIGNAL(buttonSettingsPushed()));
}
