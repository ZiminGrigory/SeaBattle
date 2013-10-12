#include "client.h"
#include "clientstate.h"
#include "stateCollection.h"
#include "types.h"

Client::Client(QObject *parent) :
    QObject(parent),
    state(NULL),
    socket(new QTcpSocket()),
    stateCollection(new StateCollection(this))
{
    state = stateCollection->getNoConnectionState();
}

void Client::connectToServer()
{
    // abort all connections and return to NoConnectionState
    abort();
	QString serverName = settings.value(SettingsKey::IP_KEY).toString();
	if (serverName.isEmpty()){
		serverName = Protocol::ServerName;
	}

	quint16 port = Protocol::ServerPort;

	if (settings.contains(SettingsKey::PORT_KEY)){
		port = quint16(settings.value(SettingsKey::PORT_KEY).toInt());
	}
	state->connect(serverName, port);
}

void Client::abort()
{
    state->abort();
}

void Client::send(Protocol::RequestType type, const QByteArray &bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    state->send(type, bytes);
}

void Client::setState(const QSharedPointer<ClientState> &newState)
{
    state = newState;
}
