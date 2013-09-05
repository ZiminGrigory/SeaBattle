#include "view.h"
#ifdef QT4
    #include <QtGui>
#elif QT5
    #include <QtWidgets/QApplication>
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	View *view = new View;
	view->paintMainWindowWithStartDialog();
	return a.exec();
}
