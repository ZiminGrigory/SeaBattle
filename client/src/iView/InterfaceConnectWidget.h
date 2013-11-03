#ifndef INTERFACECONNECTWIDGET_H
#define INTERFACECONNECTWIDGET_H
#include <QString>
#include <QWidget>

class InterfaceConnectWidget: public QWidget
{
public:
	InterfaceConnectWidget(QWidget *parent = 0): QWidget(parent){}
	virtual void showMessage(QString text) = 0;
	virtual void showLoader() = 0;
	virtual void hideLoader() = 0;
	virtual void setEnabledTryAgain(bool switcher) = 0;

signals:
	void buttonExitPushed();
	void buttonTryAgainPushed();
};

#endif // INTERFACECONNECTWIDGET_H
