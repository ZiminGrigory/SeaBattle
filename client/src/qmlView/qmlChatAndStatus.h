#ifndef QMLCHATANDSTATUS_H
#define QMLCHATANDSTATUS_H

#include "InterfaceChatAndStatus.h"

class QmlChatAndStatus : public InterfaceChatAndStatus
{
	Q_OBJECT
public:
	QmlChatAndStatus();

	void clearChat();
public slots:
	void appendMessage(Players plr, QString text);
	void showPicture(Players plr, PictureStatus::Picture status);

signals:
	void getNewMessage(QString text);
};

#endif // QMLCHATANDSTATUS_H
