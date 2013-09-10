#include "view.h"
#include "gameMaster.h"
#include "humanPlayer.h"
#include "aiPlayerSimple.h"
#ifdef QT4
    #include <QtGui>
#elif QT5
    #include <QtWidgets/QApplication>
#endif

int main(int argc, char *argv[])
{
<<<<<<< HEAD:client/src/main.cpp
	QApplication a(argc, argv);
    GameMaster gameMaster(QSharedPointer<View>(new View));
=======
    QApplication a(argc, argv);
	View *view = new View;
	HumanPlayer humanPlayer(view);
    AIPlayerSimple aiPlayer(view);
	GameMaster gameMaster(&humanPlayer, &aiPlayer, view);
>>>>>>> 51113694a8344743112a0373549dd2ce0ff60285:src/main.cpp
	gameMaster.startGame();
	return a.exec();
}
