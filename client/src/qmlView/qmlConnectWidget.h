#ifndef QMLCONNECTWIDGET_H
#define QMLCONNECTWIDGET_H

#include <QQuickWindow>
#include <QQuickItem>

#include "InterfaceConnectWidget.h"

class QmlConnectWidget : public InterfaceConnectWidget
{
	Q_OBJECT
public:
	QmlConnectWidget(QObject* widget);

	void showMessage(QString text);
	void showLoader();
	void hideLoader();
	void setEnabledTryAgain(bool switcher);

signals:
	void buttonExitPushed();
	void buttonTryAgainPushed();

private:
	QObject *textBrowser;
	QObject *loader;
	QObject* mConnectWidget;
};

#endif // QMLCONNECTWIDGET_H
