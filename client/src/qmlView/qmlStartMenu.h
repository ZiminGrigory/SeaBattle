#ifndef QMLSTARTMENU_H
#define QMLSTARTMENU_H

#include <QQmlEngine>
#include <QSharedPointer>

#include <QQuickItem>

#include "InterfaceStartMenu.h"
#include "qmlWidgetAppender.h"
#include "qmlRootWidget.h"

class QmlStartMenu : public InterfaceStartMenu, public QmlRootWidget
{
	Q_OBJECT
public:
	QmlStartMenu(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder);

	void show();
	void hide();
signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();

private:
	// путь к qml файлу (путь не от исходников, а от исполняемого файла)
	static const QString componentUrl;

	// QQuickItem - это сам объект, созданный из qml файла
	QSharedPointer<QQuickItem> mStartMenu;
	// эта штука для добавления элементов на окно
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLSTARTMENU_H
