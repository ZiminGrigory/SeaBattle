#ifndef INTERFACESTARTMENU_H
#define INTERFACESTARTMENU_H
#include <QWidget>

class InterfaceStartMenu: public QWidget
{
public:
	InterfaceStartMenu(QWidget *parent = 0): QWidget(parent){}

signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
};

#endif // INTERFACESTARTMENU_H
