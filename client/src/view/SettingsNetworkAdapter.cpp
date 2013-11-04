#include "SettingsNetworkAdapter.h"

SettingsNetworkAdapter::SettingsNetworkAdapter(const QSharedPointer<SettingsNetwork>& _mAdaptee): mAdaptee(_mAdaptee)
{
	connect(mAdaptee.data(), SIGNAL(nameOfServerWithPort(QString server, quint16 port)),
			SIGNAL(nameOfServerWithPort(QString server, quint16 port)));
	connect(mAdaptee.data(), SIGNAL(buttonBackPushed()), SIGNAL(buttonBackPushed()));
}
