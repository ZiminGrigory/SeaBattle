#ifndef QMLSTARTMENU_H
#define QMLSTARTMENU_H

#include "InterfaceStartMenu.h"

class QmlStartMenu : public InterfaceStartMenu
{
	Q_OBJECT
public:
	QmlStartMenu();

signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();
};

#endif // QMLSTARTMENU_H
