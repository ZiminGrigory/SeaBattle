#include "qmlWidgetAppender.h"


QmlWidgetAppender::QmlWidgetAppender(QQuickWindow* window):
	mWindow(window)
{}

void QmlWidgetAppender::show(const QSharedPointer<QQuickItem>& rootItem)
{
	rootItem->setParentItem(mWindow->contentItem());
}

void QmlWidgetAppender::hide(const QSharedPointer<QQuickItem>& rootItem)
{
	rootItem->setParentItem(NULL);
}
