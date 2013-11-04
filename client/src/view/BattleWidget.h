#ifndef BATTLEWIDGET_H
#define BATTLEWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QSharedPointer>
#include <QTimer>

#include "cell.h"
#include "field.h"
#include "tabOfInformation.h"
#include "InterfaceBattleWidget.h"
#include "ChatAndStatus.h"

namespace Ui {
class BattleWidget;
}

class BattleWidget : public InterfaceBattleWidget, public QWidget
{
	Q_OBJECT

public:
	explicit BattleWidget();
	~BattleWidget(){}
	void setTime(int time);
	void hideTimer();
	void showPlayerField();
	void showEnemyField();
	void showInfoTab();
	void clearItself();
    void showGameBreakDialog(const QString &message);
    void showQuitDialog();

	QSharedPointer<InterfaceField> getPlayerFieldView();
	QSharedPointer<InterfaceField> getEnemyFieldView();
	QSharedPointer<InterfaceInfoTab> getInfoTabView();
	QSharedPointer<InterfaceChatAndStatus> getChatAndStatus();
	void showCountersOfFleet();
	void setCountOfFleet(Players plr, int count);
signals:
	void buttonBackPressed();
    void gameBreakDialogOkPressed();
    void quitDialogOkPressed();
    void quitDialogCancelPressed();

public slots:
	void setMessage(QString text);
private:
	QSharedPointer<Ui::BattleWidget> ui;
    QMessageBox gameBreakDialog;
    QMessageBox quitDialog;
	QTimer timer;
	QSharedPointer<InterfaceField> mPlayerField;
	QSharedPointer<InterfaceField> mEnemyField;
	QSharedPointer<InterfaceInfoTab> mInfoTab;
	QSharedPointer<InterfaceChatAndStatus> mChat;
	void showChatAndStatus();

private slots:
	void decTime();
};

#endif // BATTLEWIDGET_H
