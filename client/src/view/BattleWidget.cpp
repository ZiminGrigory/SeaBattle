#include "BattleWidget.h"
#include "ui_BattleWidget.h"

BattleWidget::BattleWidget() :
	QWidget(),
	ui(new Ui::BattleWidget),
    gameBreakDialog(this),
    quitDialog(this),
	timer()
{
	ui->setupUi(this);
	ui->lcdNumber->hide();
    this->setWindowTitle("МОРСКОЙ БОЙ");
    ui->buttonBack->setText("Назад в главное меню");
	mPlayerField = QSharedPointer<Field>(new Field);
	mEnemyField = QSharedPointer<Field>(new Field);;
	mInfoTab = QSharedPointer<TabOfInformation>(new TabOfInformation);
	mChat = QSharedPointer<ChatAndStatus>(new ChatAndStatus);
	timer.setSingleShot(false);
	showChatAndStatus();
    ui->EnemyCnt->setText("<font color = black>Осталось кораблей:<\\font>");
	ui->EnemyCnt->hide();
    ui->YouCnt->setText("<font color = black>Осталось кораблей:<\\font>");
	ui->YouCnt->hide();
	ui->EnemyCntDisplay->hide();
	ui->YouCntDisplay->hide();
    quitDialog.setText("Вы уверены, что хотите покинуть игру?");
    quitDialog.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);

	connect(ui->buttonBack, SIGNAL(clicked()), SIGNAL(buttonBackPressed()));
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
	ui->horizontalLayout_2->removeWidget(mInfoTab.data());
	ui->horizontalLayout_2->addWidget(mEnemyField.data());
	mEnemyField->show();
	mInfoTab->hide();
}

void BattleWidget::showInfoTab()
{
	ui->horizontalLayout_2->addWidget(mInfoTab.data());
	mInfoTab->show();
}

void BattleWidget::clearItself()
{
	ui->horizontalLayout_2->removeWidget(mEnemyField.data());
	ui->horizontalLayout_2->removeWidget(mPlayerField.data());
	ui->lcdNumber->hide();
	mInfoTab->clearItself();
	mPlayerField->clearItself();
	mEnemyField->clearItself();
	mChat->clearChat();
	ui->EnemyCnt->hide();
	ui->YouCnt->hide();
	ui->EnemyCntDisplay->hide();
	ui->YouCntDisplay->hide();
	mPlayerField->hide();
    mEnemyField->hide();
}

void BattleWidget::showGameBreakDialog(const QString& message)
{
    gameBreakDialog.setText(message);
    QMessageBox::StandardButton res = static_cast<QMessageBox::StandardButton>(gameBreakDialog.exec());
    if (res == QMessageBox::Ok)
    {
        emit gameBreakDialogOkPressed();
    }
}

void BattleWidget::showQuitDialog()
{
    QMessageBox::StandardButton res = static_cast<QMessageBox::StandardButton>(quitDialog.exec());
    if (res == QMessageBox::Ok)
    {
        emit quitDialogOkPressed();
    }
    else if (res == QMessageBox::Cancel)
    {
        emit quitDialogCancelPressed();
    }
}

void BattleWidget::showChatAndStatus()
{
	ui->layoutForChat->addWidget(mChat.data());
}

QSharedPointer<Field> BattleWidget::getPlayerFieldView()
{
	return mPlayerField;
}

QSharedPointer<Field> BattleWidget::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<TabOfInformation> BattleWidget::getInfoTabView()
{
	return mInfoTab;
}

QSharedPointer<ChatAndStatus> BattleWidget::getChatAndStatus()
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


