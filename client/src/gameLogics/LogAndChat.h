#ifndef LOGANDCHAT_H
#define LOGANDCHAT_H
#include "InterfaceChatAndStatus.h"

class LogAndChat
{
public:
	LogAndChat(QSharedPointer<InterfaceChatAndStatus> chat);
	void cellAttacked(Players plr, int id, AttackStatus status);
	void playerMessage(Players plr, QString message);
    void gameMasterMessage(const QString& message);
private:
	QSharedPointer<InterfaceChatAndStatus> mChat;
	QString messageFactory(int id, AttackStatus status);
};

#endif // LOGANDCHAT_H
