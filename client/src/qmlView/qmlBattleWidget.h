#ifndef QMLBATTLEWIDGET_H
#define QMLBATTLEWIDGET_H

#include "InterfaceBattleWidget.h"
#include <QQuickWindow>
#include <QQuickItem>
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"
#include "types.h"
#include "qmlInfoTab.h"
#include "qmlChatAndStatus.h"
#include "qmlField.h"


class QmlBattleWidget : public InterfaceBattleWidget, public QmlRootWidget
{
	Q_OBJECT
public:
	QmlBattleWidget(QQmlEngine *engine, const QSharedPointer<QmlWidgetAppender> &widgetAppeder);

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

	void show();
	void hide();

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
private slots:
	void handleDeleteShipMode(bool isActive);
private:
	static const QString componentUrl;
	QSharedPointer<QmlInfoTab> mInfoTab;
	QSharedPointer<QmlField> mPlrField;
	QSharedPointer<QmlField> mEnemyField;
	QSharedPointer<QmlChatAndStatus> mChatAndStatus;
	QSharedPointer<QQuickItem> mBattleWidget;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
	QObject *timer;
};

#endif // QMLBATTLEWIDGET_H
