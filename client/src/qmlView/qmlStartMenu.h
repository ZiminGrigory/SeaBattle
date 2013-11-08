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
	QmlStartMenu(QQmlEngine* engine);

	QSharedPointer<QQuickItem> getQmlObject() const;
signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();

private:
	static const QString componentUrl;

	QSharedPointer<QQuickItem> mStartMenu;
};

#endif // QMLSTARTMENU_H
