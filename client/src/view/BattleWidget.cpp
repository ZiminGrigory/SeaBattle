#include "BattleWidget.h"
#include "ui_BattleWidget.h"

BattleWidget::BattleWidget() :InterfaceBattleWidget(),
	ui(new Ui::BattleWidget),
	timer()
{
	ui->setupUi(this);
	ui->lcdNumber->hide();
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));
	mPlayerField = QSharedPointer<InterfaceField>(new Field);
	mEnemyField = QSharedPointer<InterfaceField>(new Field);;
	mInfoTab = QSharedPointer<InterfaceInfoTab>(new TabOfInformation);
	mChat = QSharedPointer<InterfaceChatAndStatus>(new ChatAndStatus);
	timer.setSingleShot(false);
	showChatAndStatus();
	ui->EnemyCnt->setText(QString::fromLocal8Bit("<font color = black>Осталось кораблей:<\\font>"));
	ui->EnemyCnt->hide();
	ui->YouCnt->setText(QString::fromLocal8Bit("<font color = black>Осталось кораблей:<\\font>"));
	ui->YouCnt->hide();
	ui->EnemyCntDisplay->hide();
	ui->YouCntDisplay->hide();
}

void BattleWidget::setMessage(QString text)
{
	ui->label->setText(QString::fromLocal8Bit("<font color = black>"+text.toLocal8Bit() + "<\\font>"));
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
	mPlayerField->show();
}

void BattleWidget::showEnemyField()
{
	ui->lcdNumber->show();
	ui->horizontalLayout_2->itemAt(1)->widget()->hide();
	ui->horizontalLayout_2->addWidget(mEnemyField.data());
	mEnemyField->show();
}

void BattleWidget::showInfoTab()
{
	ui->horizontalLayout_2->addWidget(mInfoTab.data());
	mInfoTab->show();
}

void BattleWidget::showChatAndStatus()
{
	ui->layoutForChat->addWidget(mChat.data());
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

QSharedPointer<InterfaceChatAndStatus> BattleWidget::getChatAndStatus()
{
	return mChat;
}

void BattleWidget::showCountersOfFleet()
{
	ui->EnemyCnt->show();
	ui->YouCnt->show();
	ui->EnemyCntDisplay->show();
	ui->YouCntDisplay->show();
}

void BattleWidget::setCountOfFleet(Players plr, int count)
{
	if (plr == YOU){
		ui->YouCntDisplay->display(count);
	} else if (plr == ENEMY){
		ui->EnemyCntDisplay->display(count);
	}
}

void BattleWidget::decTime()
{
	ui->lcdNumber->display(ui->lcdNumber->intValue() - 1);
}


