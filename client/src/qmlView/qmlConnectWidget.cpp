#include "qmlConnectWidget.h"

const QString QmlConnectWidget::componentUrl = "qml/qml/ConnectWidget.qml";

QmlConnectWidget::QmlConnectWidget(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mConnectWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
	connect(mConnectWidget.data(), SIGNAL(repeat()), this, SIGNAL(buttonTryAgainPushed()));
	connect(mConnectWidget.data(), SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
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

void QmlConnectWidget::show()
{
	mWidgetAppender->show(mConnectWidget);
}

void QmlConnectWidget::hide()
{
	mWidgetAppender->hide(mConnectWidget);
}
