#include "remotePlayer.h"

RemotePlayer::RemotePlayer(const QSharedPointer<GameField>& plrField,
                           const QSharedPointer<GameField>& enmField,
                           QSharedPointer<Client>& _client):
    Player(plrField, enmField),
    client(_client),
    myTurn(false),
    expectFleet(false)
{
    connect(client.data(), SIGNAL(received(Protocol::RequestType, const QByteArray&)),
            SLOT(parseRecievedRequest(Protocol::RequestType, const QByteArray&)));
}

void RemotePlayer::installFleet()
{
    expectFleet = true;
    setFleetHealth(myField->getFleet());
}

void RemotePlayer::turn()
{
    myTurn = true;
}

void RemotePlayer::parseRecievedRequest(Protocol::RequestType type, const QByteArray& bytes)
    throw(IncorrectRequest, IncorrectFleet)
{
    QDataStream request(bytes);
    request.setVersion(Protocol::QDataStreamVersion);

    switch (type)
    {
    case Protocol::FLEET_INSTALLED:
    {
        // 3 bytes - size & request type,
        // next bytes represents the fleet placement,
        // each ship defined by size, orientation and id of top left cell,
        // each parameter is stored in 1 byte,
        // and, finally, we have 10 ships
        if (bytes.size() < sizeof(Protocol::ShipInfo) * 10)
        {
            throw IncorrectRequest();
        }
        QVector<Protocol::ShipInfo> fleet;
        for (int i = 0; i < 10; i++)
        {
            Protocol::ShipInfo ship;
            request >> ship.size;
            request >> ship.id;
            request >> ship.orientation;
            if ((ship.size < 1) || (ship.size > 4) || (ship.id >= 100))
            {
                throw IncorrectRequest();
            }
            fleet.append(ship);
        }
        fleetInstalledHandler(fleet);
        return;
    }
    case Protocol::TURN_MADE:
    {
        if (bytes.size() < 1)
        {
            throw IncorrectRequest();
        }
        // we have only 100 ids, so any value out of this range is an error
        quint8 id = 255;
        request >> id;
        if (id >= 100)
        {
            throw IncorrectRequest();
        }
        turnMadeHandler(id);
        return;
    }
    case Protocol::CHAT_MESSAGE:
    {
        if (bytes.size() == 0)
        {
            return;
        }
        QString message = QString::fromLocal8Bit(bytes.mid(4));
        chatMessageHandler(message);
    }
    }
}

void RemotePlayer::fleetInstalledHandler(QVector<Protocol::ShipInfo> fleet) throw (IncorrectFleet)
{
    if (expectFleet)
    {
        qDebug() << "Fleet was recieved";

        for (int i = 0; i < fleet.size(); i++)
        {
            Protocol::ShipInfo ship = fleet[i];
            PlacementStatus status =
                    myField->setShip(ship.id, ship.size, ship.orientation);

            qDebug() << i << ": " << "id: " << ship.id << "size: " << ship.size << "orn: " << ship.orientation;
            if (status != OK)
            {
                throw IncorrectFleet();
            }
        }
    }

    emit fleetInstalled(this);
}

void RemotePlayer::turnMadeHandler(int id)
{
    if (myTurn && enemyField->attackable(id))
    {
        myTurn = false;
        attack(id);
    }
}

void RemotePlayer::chatMessageHandler(const QString& message)
{
    emit chat(message);
}
