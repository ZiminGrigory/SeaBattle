#ifndef QMLWIDGETAPPENDER_H
#define QMLWIDGETAPPENDER_H

#include <QQuickWindow>
#include <QQuickItem>
#include <QSharedPointer>

class QmlWidgetAppender
{
public:
	QmlWidgetAppender(QQuickWindow* window);

	void show(const QSharedPointer<QQuickItem>& rootItem);
	void hide(const QSharedPointer<QQuickItem>& rootItem);

private:
	QQuickWindow* mWindow;
};

#endif // QMLWIDGETAPPENDER_H
