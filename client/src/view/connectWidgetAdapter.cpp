#include "connectWidgetAdapter.h"

ConnectWidgetAdapter::ConnectWidgetAdapter(const QSharedPointer<ConnectWidget>& adaptee) :
	mAdaptee(adaptee)
{
	connect(mAdaptee.data(), SIGNAL(buttonExitPushed()), this, SIGNAL(buttonExitPushed()));
	connect(mAdaptee.data(), SIGNAL(buttonTryAgainPushed()), this, SIGNAL(buttonTryAgainPushed()));
}

void ConnectWidgetAdapter::showMessage(QString text)
{
	mAdaptee->showMessage(text);
}

void ConnectWidgetAdapter::showLoader()
{
	mAdaptee->showLoader();
}

void ConnectWidgetAdapter::hideLoader()
{
	mAdaptee->hideLoader();
}

void ConnectWidgetAdapter::setEnabledTryAgain(bool switcher)
{
	mAdaptee->setEnabledTryAgain(switcher);
}
