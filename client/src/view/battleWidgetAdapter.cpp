#include "battleWidgetAdapter.h"
#include "fieldAdapter.h"
#include "tabOfInformationAdapter.h"
#include "chatAndStatusAdapter.h"
BattleWidgetAdapter::BattleWidgetAdapter(const QSharedPointer<BattleWidget>& adaptee) :
	mAdaptee(adaptee),

	mPlayerFieldView(new FieldAdapter(adaptee->getPlayerFieldView())),
	mEnemyFieldView(new FieldAdapter(adaptee->getEnemyFieldView())),
	mInfoTabView(new TabOfInformationAdapter(adaptee->getInfoTabView())),
	mChatAndStatus(new ChatAndStatusAdapter(adaptee->getChatAndStatus()))
{
	connect(adaptee.data(), SIGNAL(gameBreakDialogOkPressed()), this, SIGNAL(gameBreakDialogOkPressed()));
	connect(adaptee.data(), SIGNAL(quitDialogOkPressed()), this, SIGNAL(quitDialogOkPressed()));
	connect(adaptee.data(), SIGNAL(quitDialogCancelPressed()), this, SIGNAL(quitDialogCancelPressed()));
	connect(adaptee.data(), SIGNAL(buttonBackPressed()), this, SIGNAL(buttonBackPressed()));
}

void BattleWidgetAdapter::showPlayerField()
{
	mAdaptee->showPlayerField();
}

void BattleWidgetAdapter::showEnemyField()
{
	mAdaptee->showEnemyField();
}

void BattleWidgetAdapter::showInfoTab()
{
	mAdaptee->showInfoTab();
}

void BattleWidgetAdapter::setTime(int time)
{
	mAdaptee->setTime(time);
}

void BattleWidgetAdapter::hideTimer()
{
	mAdaptee->hideTimer();
}

void BattleWidgetAdapter::showCountersOfFleet()
{
	mAdaptee->showCountersOfFleet();
}

void BattleWidgetAdapter::setCountOfFleet(Players plr, int count)
{
	mAdaptee->setCountOfFleet(plr, count);
}

void BattleWidgetAdapter::clearItself()
{
	mAdaptee->clearItself();
}

void BattleWidgetAdapter::showGameBreakDialog(const QString& message)
{
	mAdaptee->showGameBreakDialog(message);
}

void BattleWidgetAdapter::showQuitDialog()
{
	mAdaptee->showQuitDialog();
}

void BattleWidgetAdapter::switchToPlayerField()
{

}

void BattleWidgetAdapter::switchToEnemyField()
{

}

QSharedPointer<InterfaceField> BattleWidgetAdapter::getPlayerFieldView()
{
	return mPlayerFieldView;
}

QSharedPointer<InterfaceField> BattleWidgetAdapter::getEnemyFieldView()
{
	return mEnemyFieldView;
}

QSharedPointer<InterfaceInfoTab> BattleWidgetAdapter::getInfoTabView()
{
	return mInfoTabView;
}

QSharedPointer<InterfaceChatAndStatus> BattleWidgetAdapter::getChatAndStatus()
{
	return mChatAndStatus;
}

void BattleWidgetAdapter::setMessage(QString text)
{
	mAdaptee->setMessage(text);
}
