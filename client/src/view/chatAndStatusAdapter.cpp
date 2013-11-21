#include "chatAndStatusAdapter.h"

ChatAndStatusAdapter::ChatAndStatusAdapter(const QSharedPointer<ChatAndStatus> adaptee) :
	mAdaptee(adaptee)
{
	connect(mAdaptee.data(), SIGNAL(getNewMessage(QString)), this, SIGNAL(getNewMessage(QString)));
}

void ChatAndStatusAdapter::clearChat()
{
	mAdaptee->clearChat();
}

void ChatAndStatusAdapter::appendMessage(Players plr, QString text)
{
	mAdaptee->appendMessage(plr, text);
}

void ChatAndStatusAdapter::showPicture(Players plr, PictureStatus::Picture status)
{
	mAdaptee->showPicture(plr, status);
}
