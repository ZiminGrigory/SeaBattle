#include "qmlWidgetAppender.h"

#include <QScreen>
#include "qmlViewTypes.h"

QmlWidgetAppender::QmlWidgetAppender(QQuickWindow* window, QScreen* screen):
	mWindow(window),
	mScreen(screen)
{}

void QmlWidgetAppender::show(const QSharedPointer<QQuickItem>& rootItem)
{
#ifdef Q_OS_ANDROID
	rootItem->setWidth(mScreen->availableSize().width());
	rootItem->setHeight(mScreen->availableSize().height());
#else
	rootItem->setWidth(QML_WINDOW_SIZE.width());
	rootItem->setHeight(QML_WINDOW_SIZE.height());
#endif
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
