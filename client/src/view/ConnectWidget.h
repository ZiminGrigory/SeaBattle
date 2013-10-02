#ifndef CONNECTWIDGET_H
#define CONNECTWIDGET_H

#include <QWidget>
#include <QMovie>
#include <QSharedPointer>
#include "InterfaceConnectWidget.h"

namespace Ui {
class ConnectWidget;
}

class ConnectWidget :public InterfaceConnectWidget
{
	Q_OBJECT

public:
	explicit ConnectWidget();
	~ConnectWidget();
	void showMessage(QString text);
	void showLoader();
	void hideLoader();
	void setEnabledTryAgain(bool switcher);
	void showItself();
	void hideItself();

signals:
	void buttonExitPushed();
	void buttonTryAgainPushed();

private:
	Ui::ConnectWidget *ui;
	QSharedPointer<QMovie> loader;
};

#endif // CONNECTWIDGET_H
