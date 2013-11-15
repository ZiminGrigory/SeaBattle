#include "qmlBattleWidget.h"
#include "QDebug"
//i know, that this code very horrible, but...deadline and other problem make me to do this

const QString QmlBattleWidget::componentUrl = "qml/qml/Battle.qml";

QmlBattleWidget::QmlBattleWidget(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mBattleWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
	mBattleWidget->dumpObjectTree();
	connect(mBattleWidget.data(), SIGNAL(backPressed()), this, SIGNAL(quitDialogOkPressed()));

	mInfoTab = QSharedPointer<QmlInfoTab>(new QmlInfoTab(QSharedPointer<QObject>(mBattleWidget->findChild<QObject*>("mAutoButton"))
													 ,QSharedPointer<QObject>(mBattleWidget->findChild<QObject*>("mButtonReady"))
													 ,QSharedPointer<QObject>(mBattleWidget->findChild<QObject*>("mCountOfShipn"))));
	mPlrField = QSharedPointer<QmlField>(new QmlField(QSharedPointer<QObject>(mBattleWidget->findChild<QObject*>("mPlrField"))));
	mEnemyField = QSharedPointer<QmlField>(new QmlField(QSharedPointer<QObject>(mBattleWidget->findChild<QObject*>("mEnemyField"))));
}

void QmlBattleWidget::showPlayerField()
{
	// crashed here ...
	QObject* mField = mBattleWidget->findChild<QObject*>("mPlrField");
	qDebug() << mField;
	mField->setProperty("visible", true);
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
	Q_UNUSED(time)
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
	if (plr == YOU){
		mBattleWidget->setProperty("countOfPlr", count);
	}else{
		mBattleWidget->setProperty("countOfEnemy", count);
	}
}

void QmlBattleWidget::clearItself()
{
	//to do call in children
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
	return mPlrField;
}

QSharedPointer<InterfaceField> QmlBattleWidget::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<InterfaceInfoTab> QmlBattleWidget::getInfoTabView()
{
	return mInfoTab;
}

QSharedPointer<InterfaceChatAndStatus> QmlBattleWidget::getChatAndStatus()
{
	return QSharedPointer<InterfaceChatAndStatus>();
}

void QmlBattleWidget::setMessage(QString text)
{
	//unused....
	Q_UNUSED(text)
}
