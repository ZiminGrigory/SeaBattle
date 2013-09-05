#include <QtWidgets/QApplication>
#include "view.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	View *view = new View;
	view->paintMainWindowWithStartDialog();
	return a.exec();
}
