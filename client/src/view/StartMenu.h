#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include "InterfaceStartMenu.h"

namespace Ui {
class StartMenu;
}

class StartMenu :public InterfaceStartMenu, public QWidget
{
	Q_OBJECT

public:
	StartMenu();
	~StartMenu();

signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();

private:
	Ui::StartMenu *ui;
};

#endif // STARTMENU_H
