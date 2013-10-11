#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "InterfaceSettingsMenu.h"

namespace Ui {
class SettingsMenu;
}

class SettingsMenu : public InterfaceSettingsMenu
{
	Q_OBJECT

public:
	explicit SettingsMenu();
	~SettingsMenu();

signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();

private slots:
	void showNetworkSettings();
	void showVolumeSettings();
	void hideBoth();
	void handleNameOfServerWithPort(QString name, quint16 i);
	void handleVolumeChanged(int i);
	void handleMute(bool isMute);

private:
	Ui::SettingsMenu *ui;
	QSharedPointer<InterfaceVolumeSettings> volSettings;
	QSharedPointer<InterfaceNetworkSettings> netorkSettings;
};

#endif // SETTINGSMENU_H
