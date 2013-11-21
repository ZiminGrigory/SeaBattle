#ifndef SETTINGS_H
#define SETTINGS_H

//отвечает за звук, переименовывать класс с формой - ооочень плохой план
#include "InterfaceVolumeSettings.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
	Q_OBJECT

public:
	Settings();
	~Settings();

signals:
	void changeVolume(int volume);
	void mute(bool switcher);
	void buttonBackPushed();

private slots:
	void applyHandler();
	void okHandler();

private:
	Ui::Settings *ui;
};

#endif // SETTINGS_H
