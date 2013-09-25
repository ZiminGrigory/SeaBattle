#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include "InterfaceMainWindow.h"
#include "StartMenu.h"
#include "AiLvlList.h"
#include "ChatAndStatus.h"
#include "ConnectWidget.h"
#include "BattleWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public InterfaceMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow();
	~MainWindow();
	void showWidget(Widgets widget);
	void hideWidget(Widgets widget);
	QSharedPointer<InterfaceAiLvlList> getInterfaceAiLvlList();
	QSharedPointer<InterfaceBattleWidget> getInterfaceBattleWidget();
	QSharedPointer<InterfaceChatAndStatus> getInterfaceChatAndStatus();
	QSharedPointer<InterfaceConnectWidget> getInterfaceConnectWidget();
	QSharedPointer<InterfaceStartMenu> getInterfaceStartMenu();
private:
	Ui::MainWindow *ui;
	QSharedPointer<InterfaceAiLvlList> aiLvlList;
	QSharedPointer<InterfaceChatAndStatus> chatAndStatus;
	QSharedPointer<InterfaceConnectWidget> connectWidget;
	QSharedPointer<InterfaceStartMenu> startMenu;
	QSharedPointer<InterfaceBattleWidget> battleWidget;
};

#endif // MAINWINDOW_H
