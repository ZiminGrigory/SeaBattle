#include <QQmlComponent>

#include "qmlStartMenu.h"

const QString QmlStartMenu::componentUrl = "qml/qml/StartMenu.qml";

QmlStartMenu::QmlStartMenu(QQmlEngine* engine)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mStartMenu = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
}

QSharedPointer<QQuickItem> QmlStartMenu::getQmlObject() const
{
	return mStartMenu;
}
