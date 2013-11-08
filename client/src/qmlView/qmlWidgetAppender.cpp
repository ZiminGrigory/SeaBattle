#include "qmlWidgetAppender.h"


QmlWidgetAppender::QmlWidgetAppender(QQuickWindow* window):
	mWindow(window)
{}

void QmlWidgetAppender::show(const QSharedPointer<QQuickItem>& rootItem)
{
	// чтобы отобразить какой-нибудь qml объект, надо его подцепить к корневому элементу qml окна или
	// к какому-нибудь уже отображаемому qml объекту.
	// подцепляем методом setParentItem().
	// у qml окна есть невидимый корневой элемент (contentItem), к нему можно цыплять объекты верхнего уровня
	rootItem->setParentItem(mWindow->contentItem());
}

void QmlWidgetAppender::hide(const QSharedPointer<QQuickItem>& rootItem)
{
	// чтобы скрыть qml объект, отцепляем его от другого отображаемого qml объекта
	rootItem->setParentItem(NULL);
}
