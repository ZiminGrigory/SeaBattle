#ifndef SETTINGSNETWORK_H
#define SETTINGSNETWORK_H

#include "InterfaceNetworkSettings.h"

namespace Ui {
class SettingsNetwork;
}

class SettingsNetwork : public InterfaceNetworkSettings, public QWidget
{
	Q_OBJECT

public:
	SettingsNetwork();
	~SettingsNetwork();

signals:
	void nameOfServerWithPort(QString server, quint16 port);
	void buttonBackPushed();

private slots:
	void applyHandler();
	void okHandler();

private:
	Ui::SettingsNetwork *ui;
};

#endif // SETTINGSNETWORK_H
