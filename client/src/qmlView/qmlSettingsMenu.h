#ifndef QMLSETTINGSMENU_H
#define QMLSETTINGSMENU_H

#include <QQuickWindow>
#include <QQuickItem>
#include "InterfaceSettingsMenu.h"
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"
#include "types.h"

using namespace std;

class QmlSettingsMenu : public InterfaceSettingsMenu, public QmlRootWidget
{
	Q_OBJECT
public:
	QmlSettingsMenu(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder);

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
	static const QString componentUrl;

	QSharedPointer<QQuickItem> mSettingsWidget;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLSETTINGSMENU_H
