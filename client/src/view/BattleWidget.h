#ifndef BATTLEWIDGET_H
#define BATTLEWIDGET_H

#include <QWidget>
#include <QSharedPointer>
#include <QTimer>
#include "cell.h"
#include "field.h"
#include "tabOfInformation.h"
#include "InterfaceBattleWidget.h"

namespace Ui {
class BattleWidget;
}

class BattleWidget : public InterfaceBattleWidget
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
	QSharedPointer<InterfaceField> getPlayerFieldView();
	QSharedPointer<InterfaceField> getEnemyFieldView();
	QSharedPointer<InterfaceInfoTab> getInfoTabView();

public slots:
	void setMessage(QString text);

private:
	QSharedPointer<Ui::BattleWidget> ui;
	QTimer timer;
	QSharedPointer<InterfaceField> mPlayerField;
	QSharedPointer<InterfaceField> mEnemyField;
	QSharedPointer<InterfaceInfoTab> mInfoTab;

private slots:
	void decTime();
};

#endif // BATTLEWIDGET_H
