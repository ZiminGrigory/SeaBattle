#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include "InterfaceMainWindow.h"
#include "StartMenu.h"
#include "AiLvlList.h"
#include "ConnectWidget.h"
#include "BattleWidget.h"
#include "Settings.h"
#include "SettingsMenu.h"
#include "SettingsNetwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();
	void showWidget(Widgets widget);
	void hideWidget(Widgets widget);
	void showMain();
	QSharedPointer<InterfaceAiLvlList> getInterfaceAiLvlList();
	QSharedPointer<InterfaceBattleWidget> getInterfaceBattleWidget();
	QSharedPointer<InterfaceConnectWidget> getInterfaceConnectWidget();
	QSharedPointer<InterfaceStartMenu> getInterfaceStartMenu();
	QSharedPointer<InterfaceSettingsMenu> getInterfaceSettingsMenu();
private:
	Ui::MainWindow *ui;
	QSharedPointer<InterfaceAiLvlList> aiLvlList;
	QSharedPointer<InterfaceConnectWidget> connectWidget;
	QSharedPointer<StartMenu> startMenu;
	QSharedPointer<InterfaceBattleWidget> battleWidget;
	QSharedPointer<InterfaceSettingsMenu> settingsMenu;
};

#endif // MAINWINDOW_H
