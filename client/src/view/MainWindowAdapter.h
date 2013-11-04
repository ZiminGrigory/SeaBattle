#ifndef MAINWINDOWADAPTER_H
#define MAINWINDOWADAPTER_H
#include "InterfaceMainWindow.h"
#include "MainWindow.h"
#include "aiLvlListAdapter.h"
#include "battleWidgetAdapter.h"
#include "connectWidgetAdapter.h"
#include "SettingsMenuAdapter.h"
#include "StartMenuAdapter.h"
class MainWindowAdapter: public InterfaceMainWindow
{
public:
	MainWindowAdapter();
	void showWidget(Widgets widget);
	void hideWidget(Widgets widget);
	void showMain();
	 QSharedPointer<InterfaceAiLvlList> getInterfaceAiLvlList();
	 QSharedPointer<InterfaceBattleWidget> getInterfaceBattleWidget();
	 QSharedPointer<InterfaceConnectWidget> getInterfaceConnectWidget();
	 QSharedPointer<InterfaceStartMenu> getInterfaceStartMenu();
	 QSharedPointer<InterfaceSettingsMenu> getInterfaceSettingsMenu();

private:
	MainWindow mAdaptee;
	QSharedPointer<InterfaceAiLvlList> mInterfaceAiLvlList;
	QSharedPointer<InterfaceBattleWidget> mInterfaceBattleWidget;
	QSharedPointer<InterfaceConnectWidget> mInterfaceConnectWidget;
	QSharedPointer<InterfaceStartMenu> mInterfaceStartMenu;
	QSharedPointer<InterfaceSettingsMenu> mInterfaceSettingsMenu;
};

#endif // MAINWINDOWADAPTER_H
