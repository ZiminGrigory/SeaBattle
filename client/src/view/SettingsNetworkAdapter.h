#ifndef SETTINGSNETWORKADAPTER_H
#define SETTINGSNETWORKADAPTER_H
#include "InterfaceNetworkSettings.h"
#include "SettingsNetwork.h"
#include <QSharedPointer>
class SettingsNetworkAdapter :public InterfaceNetworkSettings
{
public:
	SettingsNetworkAdapter(const QSharedPointer<SettingsNetwork>& _mAdaptee);
signals:
	void nameOfServerWithPort(QString server, quint16 port);
	void buttonBackPushed();
private:
	QSharedPointer<SettingsNetwork> mAdaptee;
};

#endif // SETTINGSNETWORKADAPTER_H
