#include "qmlConnectWidget.h"

QmlConnectWidget::QmlConnectWidget(QObject* widget) :
	mConnectWidget(widget)
{
	connect(mConnectWidget, SIGNAL(repeat()), this, SIGNAL(buttonTryAgainPushed()));
	connect(mConnectWidget, SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
	textBrowser = mConnectWidget->findChild<QObject*>("messageBox");
	loader = mConnectWidget->findChild<QObject*>("loader");
}

void QmlConnectWidget::showMessage(QString text)
{
	textBrowser->setProperty("text", text);
}

void QmlConnectWidget::showLoader()
{
	loader->setProperty("visible", true);
}

void QmlConnectWidget::hideLoader()
{
	loader->setProperty("visible", false);
}

void QmlConnectWidget::setEnabledTryAgain(bool switcher)
{
	//because...Menu{} can not provide access to enabled/disabled button
	Q_UNUSED(switcher)
}
