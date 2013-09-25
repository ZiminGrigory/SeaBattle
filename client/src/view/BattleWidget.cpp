#include "BattleWidget.h"
#include "ui_BattleWidget.h"

BattleWidget::BattleWidget() :InterfaceBattleWidget(),
	ui(new Ui::BattleWidget),
	timer()
{
	ui->setupUi(this);
	ui->lcdNumber->hide();
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));
	mPlayerField = QSharedPointer<Field>(new Field);
	mEnemyField = QSharedPointer<Field>(new Field);;
	mInfoTab = QSharedPointer<TabOfInformation>(new TabOfInformation);
	timer.setSingleShot(false);
}

void BattleWidget::setMessage(QString text)
{
	ui->label->setText(QString::fromLocal8Bit(text.toLocal8Bit()));
}

void BattleWidget::setTime(int time)
{
	disconnect(&timer, SIGNAL(timeout()), 0, 0);
	ui->lcdNumber->display(time);
	timer.start(1000);
	connect(&timer, SIGNAL(timeout()), this, SLOT(decTime()));
}

void BattleWidget::hideTimer()
{
	ui->lcdNumber->hide();
}

void BattleWidget::showPlayerField()
{
	ui->horizontalLayout_2->addWidget(mPlayerField.data());
}

void BattleWidget::showEnemyField()
{
	ui->lcdNumber->show();
	ui->horizontalLayout_2->itemAt(1)->widget()->hide();
	ui->horizontalLayout_2->addWidget(mEnemyField.data());
}

void BattleWidget::showInfoTab()
{
	ui->horizontalLayout_2->addWidget(mInfoTab.data());
}

QSharedPointer<InterfaceField> BattleWidget::getPlayerFieldView()
{
	return mPlayerField;
}

QSharedPointer<InterfaceField> BattleWidget::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<InterfaceInfoTab> BattleWidget::getInfoTabView()
{
	return mInfoTab;
}

void BattleWidget::decTime()
{
	ui->lcdNumber->display(ui->lcdNumber->intValue() - 1);
}


