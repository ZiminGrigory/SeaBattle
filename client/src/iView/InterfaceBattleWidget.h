#ifndef INTERFACEBATTLEWIDGET_H
#define INTERFACEBATTLEWIDGET_H

#include <QSharedPointer>
#include "InterfaceField.h"
#include "InterfaceInfoTab.h"
#include "InterfaceChatAndStatus.h"

class InterfaceBattleWidget : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceBattleWidget() {}

	virtual void showPlayerField() = 0;
	virtual void showEnemyField() = 0;
	virtual void showInfoTab() = 0;
	virtual void setTime(int time) = 0;
	virtual void hideTimer() = 0;
	virtual void showCountersOfFleet() = 0;
	virtual void setCountOfFleet(Players plr, int count) = 0;
	virtual void clearItself() = 0;
    virtual void showGameBreakDialog(const QString& message) = 0;
    virtual void showQuitDialog() = 0;

    virtual QSharedPointer<InterfaceField> getPlayerFieldView() = 0;
    virtual QSharedPointer<InterfaceField> getEnemyFieldView() = 0;
	virtual QSharedPointer<InterfaceInfoTab> getInfoTabView() = 0;
	virtual QSharedPointer<InterfaceChatAndStatus> getChatAndStatus() = 0;
signals:
	void buttonBackPressed();
    void gameBreakDialogOkPressed();
    void quitDialogOkPressed();
    void quitDialogCancelPressed();
public slots:
	virtual void setMessage(QString text) = 0;
};

#endif // INTERFACEBATTLEWIDGET_H
