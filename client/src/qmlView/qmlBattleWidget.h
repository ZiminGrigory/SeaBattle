#ifndef QMLBATTLEWIDGET_H
#define QMLBATTLEWIDGET_H

#include "InterfaceBattleWidget.h"
#include <QQuickWindow>
#include <QQuickItem>
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"
#include "types.h"

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

private:
	static const QString componentUrl;

	QSharedPointer<QQuickItem> mBattleWidget;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLBATTLEWIDGET_H
