#ifndef QMLSETTINGSMENU_H
#define QMLSETTINGSMENU_H

#include <QQuickWindow>
#include <QQuickItem>
#include "InterfaceSettingsMenu.h"
#include "types.h"

class QmlSettingsMenu : public InterfaceSettingsMenu
{
	Q_OBJECT
public:
	QmlSettingsMenu(QObject* widget);

signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();
private slots:
	void volumeHandler(int lvl);
	void ipAndPortHandler(QString ip, QString port);
private:

	QObject* mSettingsWidget;
};

#endif // QMLSETTINGSMENU_H
