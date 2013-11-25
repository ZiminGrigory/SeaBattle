#ifndef QMLSETTINGSMENU_H
#define QMLSETTINGSMENU_H

#include <QQuickWindow>
#include <QQuickItem>
#include "InterfaceSettingsMenu.h"
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"
#include "types.h"

class QmlSettingsMenu : public InterfaceSettingsMenu, public QmlRootWidget
{
	Q_OBJECT
public:
	QmlSettingsMenu(QObject* widget);

	void show();
	void hide();

signals:
	void mute(bool switcher);
	void volumeChanched(int i);
	void buttonBackPushed();
private slots:
	void volumeHandler(int lvl);
	void ipAndPortHandler(QString ip, QString port);
private:

	QObject* mSettingsWidget;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLSETTINGSMENU_H
