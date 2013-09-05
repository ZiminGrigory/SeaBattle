#include "view.h"
#include "gameMaster.h"
#include "humanPlayer.h"
#include "aiPlayer.h"
#ifdef QT4
    #include <QtGui>
#elif QT5
    #include <QtWidgets/QApplication>
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	View *view = new View;
	HumanPlayer humanPlayer(view);
	AIPlayer aiPlayer(view);
	GameMaster gameMaster(&humanPlayer, &aiPlayer, view);
	gameMaster.startGame();
	return a.exec();
}
