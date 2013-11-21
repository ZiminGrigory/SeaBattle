#ifndef INTERFACEMAINWINDOW_H
#define INTERFACEMAINWINDOW_H
#include "types.h"
#include "InterfaceAiLvlList.h"
#include "InterfaceBattleWidget.h"
#include "InterfaceChatAndStatus.h"
#include "InterfaceConnectWidget.h"
#include "InterfaceStartMenu.h"
#include "InterfaceSettingsMenu.h"
#include <QSharedPointer>
#include <QMainWindow>

class InterfaceMainWindow: public QMainWindow
{
public:
	InterfaceMainWindow(QWidget *parent = 0): QMainWindow(parent){}
	virtual void showWidget(Widgets widget) = 0;
	virtual void hideWidget(Widgets widget) = 0;
	virtual QSharedPointer<InterfaceAiLvlList> getInterfaceAiLvlList() = 0;
	virtual QSharedPointer<InterfaceBattleWidget> getInterfaceBattleWidget() = 0;
	virtual QSharedPointer<InterfaceConnectWidget> getInterfaceConnectWidget() = 0;
	virtual QSharedPointer<InterfaceStartMenu> getInterfaceStartMenu() = 0;
	virtual QSharedPointer<InterfaceSettingsMenu> getInterfaceSettingsMenu() = 0;
};

#endif // INTERFACEMAINWINDOW_H
