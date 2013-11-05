#ifndef QMLMAINWINDOW_H
#define QMLMAINWINDOW_H

#include <InterfaceMainWindow.h>

class QmlMainWindow : public InterfaceMainWindow
{
public:
	QmlMainWindow();
	void showWidget(Widgets widget);
	void hideWidget(Widgets widget);
	void showMain();
	QSharedPointer<InterfaceAiLvlList> getInterfaceAiLvlList();
	QSharedPointer<InterfaceBattleWidget> getInterfaceBattleWidget();
	QSharedPointer<InterfaceConnectWidget> getInterfaceConnectWidget();
	QSharedPointer<InterfaceStartMenu> getInterfaceStartMenu();
	QSharedPointer<InterfaceSettingsMenu> getInterfaceSettingsMenu();
};

#endif // QMLMAINWINDOW_H
