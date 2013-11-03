#ifndef INTERFACENETWORKSETTINGS_H
#define INTERFACENETWORKSETTINGS_H
#include <QWidget>
#include "types.h"

class InterfaceNetworkSettings: public QWidget
{
public:
	InterfaceNetworkSettings(QWidget *parent = 0): QWidget(parent){}
signals:
	void nameOfServerWithPort(QString server, quint16 port);
	void buttonBackPushed();

};
#endif // INTERFACENETWORKSETTINGS_H
