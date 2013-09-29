#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() :
	InterfaceMainWindow(),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));
	aiLvlList = QSharedPointer<AiLvlList> (new AiLvlList);
	connectWidget = QSharedPointer<ConnectWidget> (new ConnectWidget);
	startMenu = QSharedPointer<StartMenu> (new StartMenu);
	battleWidget = QSharedPointer<BattleWidget> (new BattleWidget);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::showWidget(Widgets widget)
{
	switch (widget) {
	case BATTLE:
		ui->LayoutForWidget->addWidget(battleWidget.data());
	break;
	case START_MENU:
		ui->LayoutForWidget->addWidget(startMenu.data());
	break;
	case CONNECT:
		ui->LayoutForWidget->addWidget(connectWidget.data());
	break;
	case AI_MENU:
		ui->LayoutForWidget->addWidget(aiLvlList.data());
	break;
	}
}

void MainWindow::hideWidget(Widgets widget)
{
	switch (widget) {
	case BATTLE:
		battleWidget->hide();
	break;
	case START_MENU:
		startMenu->hide();
	break;
	case CONNECT:
		connectWidget->hide();
	break;
	case AI_MENU:
		aiLvlList->hide();
	break;
	}
}

QSharedPointer<InterfaceAiLvlList> MainWindow::getInterfaceAiLvlList()
{
	return aiLvlList;
}

QSharedPointer<InterfaceBattleWidget> MainWindow::getInterfaceBattleWidget()
{
	return battleWidget;
}

QSharedPointer<InterfaceConnectWidget> MainWindow::getInterfaceConnectWidget()
{
	return connectWidget;
}

QSharedPointer<InterfaceStartMenu> MainWindow::getInterfaceStartMenu()
{
	return startMenu;
}
