#ifndef QMLSETTINGSMENU_H
#define QMLSETTINGSMENU_H

#include "InterfaceSettingsMenu.h"

class QmlSettingsMenu : public InterfaceSettingsMenu
{
	Q_OBJECT
public:
	QmlSettingsMenu();
signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();
};

#endif // QMLSETTINGSMENU_H
