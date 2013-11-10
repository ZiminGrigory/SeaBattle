#include "qmlConnectWidget.h"

const QString QmlConnectWidget::componentUrl = "qml/qml/ConnectWidget.qml";

QmlConnectWidget::QmlConnectWidget(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mConnectWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
}

void QmlConnectWidget::showMessage(QString text)
{

}

void QmlConnectWidget::showLoader()
{

}

void QmlConnectWidget::hideLoader()
{

}

void QmlConnectWidget::setEnabledTryAgain(bool switcher)
{

}

void QmlConnectWidget::show()
{
	mWidgetAppender->show(mConnectWidget);
}

void QmlConnectWidget::hide()
{
	mWidgetAppender->hide(mConnectWidget);
}
