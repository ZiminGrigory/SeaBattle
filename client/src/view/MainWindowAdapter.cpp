#include "MainWindowAdapter.h"

MainWindowAdapter::MainWindowAdapter()
{
	mInterfaceAiLvlList = QSharedPointer<InterfaceAiLvlList>(new AiLvlListAdapter(mAdaptee.getInterfaceAiLvlList()));
	mInterfaceBattleWidget = QSharedPointer<InterfaceBattleWidget>(new BattleWidgetAdapter(mAdaptee.getInterfaceBattleWidget()));
	mInterfaceConnectWidget = QSharedPointer<InterfaceConnectWidget>(new ConnectWidgetAdapter(mAdaptee.getInterfaceConnectWidget()));
	mInterfaceStartMenu = QSharedPointer<InterfaceStartMenu>(new StartMenuAdapter(mAdaptee.getInterfaceStartMenu()));
	mInterfaceSettingsMenu = QSharedPointer<InterfaceSettingsMenu>(new SettingsMenuAdapter(mAdaptee.getInterfaceSettingsMenu()));
}

void MainWindowAdapter::showWidget(Widgets widget)
{
	mAdaptee.showWidget(widget);
}

void MainWindowAdapter::hideWidget(Widgets widget)
{
	mAdaptee.hideWidget(widget);
}

void MainWindowAdapter::showMain()
{
	mAdaptee.showMain();
}

QSharedPointer<InterfaceAiLvlList> MainWindowAdapter::getInterfaceAiLvlList()
{
	return mInterfaceAiLvlList;
}

QSharedPointer<InterfaceBattleWidget> MainWindowAdapter::getInterfaceBattleWidget()
{
	return mInterfaceBattleWidget;
}

QSharedPointer<InterfaceConnectWidget> MainWindowAdapter::getInterfaceConnectWidget()
{
	return mInterfaceConnectWidget;
}

QSharedPointer<InterfaceStartMenu> MainWindowAdapter::getInterfaceStartMenu()
{
	return mInterfaceStartMenu;
}

QSharedPointer<InterfaceSettingsMenu> MainWindowAdapter::getInterfaceSettingsMenu()
{
	return mInterfaceSettingsMenu;
}
