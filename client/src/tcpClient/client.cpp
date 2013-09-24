#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    connect(state.data(), SIGNAL(error(const QString&)), this, SIGNAL(received(const QString&)));
    connect(state.data(), SIGNAL(recieved(const QByteArray&)), this, SIGNAL(received(const QByteArray&)));
}

void Client::connectToServer()
{
}

void Client::abort()
{
    state->abort();
}

bool Client::send(const QByteArray &bytes)
{
    state->send(bytes);
}
