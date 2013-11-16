#ifndef QMLCONNECTWIDGET_H
#define QMLCONNECTWIDGET_H

#include <QQuickWindow>
#include <QQuickItem>

#include "InterfaceConnectWidget.h"
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"

class QmlConnectWidget : public InterfaceConnectWidget, public QmlRootWidget
{
	Q_OBJECT
public:
	QmlConnectWidget(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder);

	void showMessage(QString text);
	void showLoader();
	void hideLoader();
	void setEnabledTryAgain(bool switcher);

	void show();
	void hide();

signals:
	void buttonExitPushed();
	void buttonTryAgainPushed();

private:
	static const QString componentUrl;
	QObject *textBrowser;
	QObject *loader;
	QSharedPointer<QQuickItem> mConnectWidget;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLCONNECTWIDGET_H
