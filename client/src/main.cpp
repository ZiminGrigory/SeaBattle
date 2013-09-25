#include <QObject>

#include "gameMaster.h"
#include "humanPlayer.h"
#include "aiPlayerSimple.h"
#ifdef QT4
    #include <QtGui>
#elif QT5
    #include <QtWidgets/QApplication>
#endif


#include "MainWindow.h"
#include "InterfaceConnectWidget.h"

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
//    GameMaster gameMaster(QSharedPointer<View>(new View));
//	gameMaster.startGame();

	return a.exec();

}
