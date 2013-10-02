#include <QObject>
#include "game.h"

#ifdef QT4
    #include <QtGui>
#elif QT5
    #include <QtWidgets/QApplication>
#endif

#include "MainWindow.h"
#include "InterfaceConnectWidget.h"

int main(int argc, char *argv[])
{
	Game game(argc, argv);
//	QSharedPointer<InterfaceMainWindow> mainWindow = QSharedPointer<MainWindow>(new MainWindow);
//	mainWindow->show();
//	mainWindow->showWidget(BATTLE);
//	GameMaster gameMaster(QSharedPointer<InterfaceBattleWidget>(mainWindow->getInterfaceBattleWidget()));
//	gameMaster.startGame();
	return game.exec();

}
