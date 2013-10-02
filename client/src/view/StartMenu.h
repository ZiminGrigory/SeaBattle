#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include "InterfaceStartMenu.h"

namespace Ui {
class StartMenu;
}

class StartMenu :public InterfaceStartMenu
{
	Q_OBJECT

public:
	explicit StartMenu();
	~StartMenu();

signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();

private:
	Ui::StartMenu *ui;
};

#endif // STARTMENU_H
