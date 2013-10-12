#include "LogAndChat.h"

LogAndChat::LogAndChat(QSharedPointer<InterfaceChatAndStatus> chat): mChat(chat)
{
}

void LogAndChat::cellAttacked(Players plr, int id, AttackStatus status)
{
	PictureStatus::Picture tmpStatus = PictureStatus::MISSED;
	switch (int(status)) {
	case int(WOUNDED):
		tmpStatus = PictureStatus::DAMAGE_SHIP;
		break;
	case int(KILLED):
		tmpStatus = PictureStatus::KILL_SHIP;
		break;
	}

	mChat->showPicture(plr, tmpStatus);
	if (plr == YOU){
		mChat->showPicture(ENEMY, PictureStatus::ATTACKED);
		mChat->appendMessage(ENEMY, messageFactory(id, status));
	} else if (plr == ENEMY){
		mChat->showPicture(YOU, PictureStatus::ATTACKED);
		mChat->appendMessage(YOU, messageFactory(id, status));
	}
}

void LogAndChat::playerMessage(Players plr, QString message)
{
	mChat->appendMessage(plr, message);
}

QString LogAndChat::messageFactory(int id, AttackStatus status)
{
	int tmp = id % FIELD_COL_NUM;
	QString character = "";
	QString attackStatus = "";
	switch (tmp){
	case 0:
		character = "A";
		break;
	case 1:
		character = "B";
		break;
	case 2:
		character = "C";
		break;
	case 3:
		character = "D";
		break;
	case 4:
		character = "E";
		break;
	case 5:
		character = "F";
		break;
	case 6:
		character = "G";
		break;
	case 7:
		character = "H";
		break;
	case 8:
		character = "I";
		break;
	case 9:
		character = "J";
		break;
	}

	switch (int(status)) {
	case MISS:
		attackStatus = QString::fromLocal8Bit(" - ПРОМАХ");
		break;
	case WOUNDED:
		attackStatus = QString::fromLocal8Bit(" - ПОПАДАНИЕ в корабль");
		break;
	case KILLED:
		attackStatus = QString::fromLocal8Bit(" - корабль УБИТ");
		break;
	}
	return QString(QString::fromLocal8Bit("атака на ") + QString::number(id / FIELD_ROW_NUM + 1)
				   + character + attackStatus);
}
