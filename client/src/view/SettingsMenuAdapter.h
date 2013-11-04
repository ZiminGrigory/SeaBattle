#ifndef SETTINGSMENUADAPTER_H
#define SETTINGSMENUADAPTER_H
#include "InterfaceSettingsMenu.h"
#include "SettingsMenu.h"
#include <QSharedPointer>
class SettingsMenuAdapter : public InterfaceSettingsMenu
{
public:
	SettingsMenuAdapter(QSharedPointer<SettingsMenu> _mAdaptee);

signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();

private:
	QSharedPointer<SettingsMenu> mAdaptee;
};

#endif // SETTINGSMENUADAPTER_H
