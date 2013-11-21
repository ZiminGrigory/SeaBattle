#ifndef QMLNETWORKSETTINGS_H
#define QMLNETWORKSETTINGS_H

#include "InterfaceNetworkSettings.h"

class QmlNetworkSettings : public InterfaceNetworkSettings
{
	Q_OBJECT
public:
	QmlNetworkSettings();

signals:
	void nameOfServerWithPort(QString server, quint16 port);
	void buttonBackPushed();
};

#endif // QMLNETWORKSETTINGS_H
