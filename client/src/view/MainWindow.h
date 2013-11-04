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
	QSharedPointer<AiLvlList> getInterfaceAiLvlList();
	QSharedPointer<BattleWidget> getInterfaceBattleWidget();
	QSharedPointer<ConnectWidget> getInterfaceConnectWidget();
	QSharedPointer<StartMenu> getInterfaceStartMenu();
	QSharedPointer<SettingsMenu> getInterfaceSettingsMenu();
private:
	Ui::MainWindow *ui;
	QSharedPointer<AiLvlList> aiLvlList;
	QSharedPointer<ConnectWidget> connectWidget;
	QSharedPointer<StartMenu> startMenu;
	QSharedPointer<BattleWidget> battleWidget;
	QSharedPointer<SettingsMenu> settingsMenu;
};

#endif // MAINWINDOW_H
