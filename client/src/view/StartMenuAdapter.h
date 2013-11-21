#ifndef STARTMENUADAPTER_H
#define STARTMENUADAPTER_H
#include "InterfaceStartMenu.h"
#include "StartMenu.h"
#include <QSharedPointer>
class StartMenuAdapter : public InterfaceStartMenu
{
public:
	StartMenuAdapter(const QSharedPointer<StartMenu>& _mAdaptee);
	Q_OBJECT
signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();

private:
	QSharedPointer<StartMenu> mAdaptee;
};

#endif // STARTMENUADAPTER_H
