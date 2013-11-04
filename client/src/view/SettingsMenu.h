#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "InterfaceSettingsMenu.h"

namespace Ui {
class SettingsMenu;
}

class SettingsMenu : public InterfaceSettingsMenu, public QWidget
{
	Q_OBJECT

public:
	SettingsMenu();
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

private:
	Ui::SettingsMenu *ui;
	QSharedPointer<InterfaceVolumeSettings> volSettings;
	QSharedPointer<InterfaceNetworkSettings> netorkSettings;
};

#endif // SETTINGSMENU_H
