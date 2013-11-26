#ifndef QMLSTARTMENU_H
#define QMLSTARTMENU_H

#include <QQmlEngine>
#include <QSharedPointer>

#include <QQuickItem>

#include "InterfaceStartMenu.h"

class QmlStartMenu : public InterfaceStartMenu
{
	Q_OBJECT
public:
	QmlStartMenu(QObject* widget);
signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();

private:
	// QQuickItem - это сам объект, созданный из qml файла
	QObject* mStartMenu;
};

#endif // QMLSTARTMENU_H
