#ifndef CONNECTWIDGETADAPTER_H
#define CONNECTWIDGETADAPTER_H

#include <QSharedPointer>

#include "ConnectWidget.h"
#include "InterfaceConnectWidget.h"

class ConnectWidgetAdapter : public InterfaceConnectWidget
{
	Q_OBJECT
public:
	ConnectWidgetAdapter(const QSharedPointer<ConnectWidget>& adaptee);

	void showMessage(QString text);
	void showLoader();
	void hideLoader();
	void setEnabledTryAgain(bool switcher);

signals:
	void buttonExitPushed();
	void buttonTryAgainPushed();
private:
	QSharedPointer<ConnectWidget> mAdaptee;

};

#endif // CONNECTWIDGETADAPTER_H
