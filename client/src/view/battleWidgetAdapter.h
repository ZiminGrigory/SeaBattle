#ifndef BATTLEWIDGETADAPTER_H
#define BATTLEWIDGETADAPTER_H

#include <QSharedPointer>

#include "InterfaceBattleWidget.h"
#include "BattleWidget.h"
#include "fieldAdapter.h"
#include "chatAndStatusAdapter.h"
#include "tabOfInformationAdapter.h"

class BattleWidgetAdapter : public InterfaceBattleWidget
{
	Q_OBJECT
public:
	BattleWidgetAdapter(const QSharedPointer<BattleWidget>& adaptee);

	void showPlayerField();
	void showEnemyField();
	void showInfoTab();
	void setTime(int time);
	void hideTimer();
	void showCountersOfFleet();
	void setCountOfFleet(Players plr, int count);
	void clearItself();
	void showGameBreakDialog(const QString& message);
	void showQuitDialog();
	void switchToPlayerField();
	void switchToEnemyField();

	QSharedPointer<InterfaceField> getPlayerFieldView();
	QSharedPointer<InterfaceField> getEnemyFieldView();
	QSharedPointer<InterfaceInfoTab> getInfoTabView();
	QSharedPointer<InterfaceChatAndStatus> getChatAndStatus();
signals:
	void buttonBackPressed();
	void gameBreakDialogOkPressed();
	void quitDialogOkPressed();
	void quitDialogCancelPressed();
public slots:
	void setMessage(QString text);
private:
	QSharedPointer<BattleWidget> mAdaptee;

	QSharedPointer<InterfaceField> mPlayerFieldView;
	QSharedPointer<InterfaceField> mEnemyFieldView;
	QSharedPointer<InterfaceInfoTab> mInfoTabView;
	QSharedPointer<InterfaceChatAndStatus> mChatAndStatus;
};

#endif // BATTLEWIDGETADAPTER_H
