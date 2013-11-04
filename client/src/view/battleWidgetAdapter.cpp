#include "battleWidgetAdapter.h"

BattleWidgetAdapter::BattleWidgetAdapter(const QSharedPointer<BattleWidget>& adaptee) :
	mAdaptee(adaptee),
	mPlayerFieldView(adaptee->getPlayerFieldView()),
	mEnemyFieldView(adaptee->getEnemyFieldView()),
	mInfoTabView(adaptee->getInfoTabView()),
	mChatAndStatus(adaptee->getChatAndStatus())
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

void BattleWidgetAdapter::setMessage(QString text)
{
	mAdaptee->setMessage(text);
}
