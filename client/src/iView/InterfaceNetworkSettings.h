#ifndef INTERFACENETWORKSETTINGS_H
#define INTERFACENETWORKSETTINGS_H

#include <QWidget>
#include "types.h"

class InterfaceNetworkSettings : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceNetworkSettings() {}
signals:
	void nameOfServerWithPort(QString server, quint16 port);
	void buttonBackPushed();

};
#endif // INTERFACENETWORKSETTINGS_H
