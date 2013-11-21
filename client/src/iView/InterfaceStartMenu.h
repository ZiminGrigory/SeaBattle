#ifndef INTERFACESTARTMENU_H
#define INTERFACESTARTMENU_H

#include <QWidget>

class InterfaceStartMenu : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceStartMenu() {}
signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();
};

#endif // INTERFACESTARTMENU_H
