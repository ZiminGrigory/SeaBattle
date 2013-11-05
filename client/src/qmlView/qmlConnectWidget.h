#ifndef QMLCONNECTWIDGET_H
#define QMLCONNECTWIDGET_H

#include "InterfaceConnectWidget.h"

class QmlConnectWidget : public InterfaceConnectWidget
{
	Q_OBJECT
public:
	QmlConnectWidget();

	void showMessage(QString text);
	void showLoader();
	void hideLoader();
	void setEnabledTryAgain(bool switcher);

signals:
	void buttonExitPushed();
	void buttonTryAgainPushed();
};

#endif // QMLCONNECTWIDGET_H
