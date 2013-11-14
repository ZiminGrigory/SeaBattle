#include "qmlBattleWidget.h"


const QString QmlBattleWidget::componentUrl = "qml/qml/Battle.qml";

QmlBattleWidget::QmlBattleWidget(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mBattleWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));

}

void QmlBattleWidget::showPlayerField()
{

}

void QmlBattleWidget::showEnemyField()
{

}

void QmlBattleWidget::showInfoTab()
{

}

void QmlBattleWidget::setTime(int time)
{

}

void QmlBattleWidget::hideTimer()
{

}

void QmlBattleWidget::showCountersOfFleet()
{

}

void QmlBattleWidget::setCountOfFleet(Players plr, int count)
{

}

void QmlBattleWidget::clearItself()
{

}

void QmlBattleWidget::showGameBreakDialog(const QString& message)
{

}

void QmlBattleWidget::showQuitDialog()
{

}

void QmlBattleWidget::show()
{
	mWidgetAppender->show(mBattleWidget);
}

void QmlBattleWidget::hide()
{
	mWidgetAppender->hide(mBattleWidget);
}

QSharedPointer<InterfaceField> QmlBattleWidget::getPlayerFieldView()
{

}

QSharedPointer<InterfaceField> QmlBattleWidget::getEnemyFieldView()
{

}

QSharedPointer<InterfaceInfoTab> QmlBattleWidget::getInfoTabView()
{

}

QSharedPointer<InterfaceChatAndStatus> QmlBattleWidget::getChatAndStatus()
{

}

void QmlBattleWidget::setMessage(QString text)
{

}
