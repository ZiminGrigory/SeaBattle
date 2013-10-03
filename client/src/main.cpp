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

	return game.exec();
}
