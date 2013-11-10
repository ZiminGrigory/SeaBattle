#ifndef QMLBATTLEWIDGET_H
#define QMLBATTLEWIDGET_H

#include "InterfaceBattleWidget.h"

class QmlBattleWidget : public InterfaceBattleWidget
{
	Q_OBJECT
public:
	QmlBattleWidget();
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
};

#endif // QMLBATTLEWIDGET_H
