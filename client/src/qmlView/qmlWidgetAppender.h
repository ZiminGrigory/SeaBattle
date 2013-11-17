#ifndef QMLWIDGETAPPENDER_H
#define QMLWIDGETAPPENDER_H

#include <QQuickWindow>
#include <QQuickItem>
#include <QSharedPointer>

class QmlWidgetAppender
{
public:
	QmlWidgetAppender(QQuickWindow* window, QScreen* screen);

	void show(const QSharedPointer<QQuickItem>& rootItem);
	void hide(const QSharedPointer<QQuickItem>& rootItem);

private:
	QQuickWindow* mWindow;
	QScreen* mScreen;
};

#endif // QMLWIDGETAPPENDER_H
