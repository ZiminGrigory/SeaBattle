#include "qmlBattleWidget.h"

//i know, that this code very horrible, but...deadline and other problem make me to do this

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
	//to do, there we give command to start
}

void QmlBattleWidget::showInfoTab()
{
	//unused....
}

void QmlBattleWidget::setTime(int time)
{
	//unused....
}

void QmlBattleWidget::hideTimer()
{
	//unused....
}

void QmlBattleWidget::showCountersOfFleet()
{
	//unused....
}

void QmlBattleWidget::setCountOfFleet(Players plr, int count)
{

}

void QmlBattleWidget::clearItself()
{

}

void QmlBattleWidget::showGameBreakDialog(const QString& message)
{
	//unused....
}

void QmlBattleWidget::showQuitDialog()
{
	//unused....
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
	//unused....
}

void QmlBattleWidget::setMessage(QString text)
{
	//unused....
	Q_UNUSED(text)
}
