#include "qmlSettingsMenu.h"

const QString QmlSettingsMenu::componentUrl = "qml/qml/SettingsMenu.qml";

QmlSettingsMenu::QmlSettingsMenu(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mSettingsWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
}

void QmlSettingsMenu::show()
{
	mWidgetAppender->show(mSettingsWidget);
}

void QmlSettingsMenu::hide()
{
	mWidgetAppender->hide(mSettingsWidget);
}
