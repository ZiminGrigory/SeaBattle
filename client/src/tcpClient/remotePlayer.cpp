#include "remotePlayer.h"

const qint16 RemotePlayer::port = 10244;

RemotePlayer::RemotePlayer(const QSharedPointer<GameField>& plrField,
                           const QSharedPointer<GameField>& enmField,
                           QSharedPointer<QTcpSocket>& _socket):
    Player(plrField, enmField),
    socket(_socket),
    blockSize(0),
    myTurn(false),
    expectFleet(false),
    fleetInst(NULL)
{
    connect(socket.data(), SIGNAL(connected()), this, SLOT(connectedToPlayerSlot()));
    connect(socket.data(), SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorHandler(QAbstractSocket::SocketError)));
    connect(socket.data(), SIGNAL(readyRead()), this, SLOT(readyReadSlot()));
}

void RemotePlayer::installFleet(const QSharedPointer<FleetInstaller>& fleetInstaller)
{
    expectFleet = true;
    connect(fleetInstaller.data(), SIGNAL(fleetInstalled(QVector<FleetInstaller::ptrShip)),
            this, SLOT(sendPlayerFleet(QVector<FleetInstaller::ptrShip>)));
    fleetInst = fleetInstaller;
}

void RemotePlayer::turn()
{
    myTurn = true;
}

void RemotePlayer::enemyTurn(int id)
{
    Player::enemyTurn(id);
    QByteArray byteArray;
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    out << quint16(4) << quint8(TURN_MADE) << quint8(id);
    socket->write(byteArray);
}

void RemotePlayer::readyReadSlot()
{
    QDataStream in(socket.data());
    in.setVersion(QDataStream::Qt_4_8);

    if (blockSize == 0) {
        // first two bytes are the size of the rest message
        // so wait until we recive the size of message
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (socket->bytesAvailable() < blockSize)
        return;

    parseRecievedRequest(in, blockSize);
}

void RemotePlayer::sendPlayerFleet(QVector<FleetInstaller::ptrShip> fleet)
{
    QByteArray byteArray;
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    // 3 bytes - size & request type,
    // next bytes represents the fleet placement
    out << quint16(3 + 10 * sizeof(ShipInfo)) << quint8(FLEET_INSTALLED);

    for (QVector<FleetInstaller::ptrShip>::const_iterator itr = fleet.begin(); itr != fleet.end(); itr++)
    {
        FleetInstaller::ptrShip ship = *itr;
        ShipInfo shipInfo;
        shipInfo.size = ship->size();
        shipInfo.id = ship->getCoordinate().at(0);
        if (ship->getCoordinate().at(1) == (ship->getCoordinate().at(0) + 1))
        {
            shipInfo.orientation = '1';
        }
        else
        {
            shipInfo.orientation = '0';
        }
        out << shipInfo.size << shipInfo.id << shipInfo.orientation;
    }
    socket->write(byteArray);
}

void RemotePlayer::parseRecievedRequest(QDataStream& request, quint16 size) throw(IncorrectRequest, IncorrectFleet)
{
    if (size < 3)
    {
        throw IncorrectRequest();
    }
    // third byte are the request type
    quint8 _type = 0;
    request >> _type;
    RequestType type = static_cast<RequestType>(_type);

    switch (type)
    {
    case FLEET_INSTALLED:
    {
        // 3 bytes - size & request type,
        // next bytes represents the fleet placement,
        // each ship defined by size, orientation and id of top left cell,
        // each parameter is stored in 1 byte,
        // and, finally, we have 10 ships
        if (size < 3 + sizeof(ShipInfo) * 10)
        {
            throw IncorrectRequest();
        }
        QVector<ShipInfo> fleet;
        for (int i = 0; i < 10; i++)
        {
            ShipInfo ship;
            request >> ship.size;
            request >> ship.id;
            request >> ship.orientation;
            if ((ship.size < 1) || (ship.size > 4) || (ship.id >= 100) ||
                    (ship.orientation != 0) || (ship.orientation != 1))
            {
                throw IncorrectRequest();
            }
            fleet.append(ship);
        }
        fleetInstalledHandler(fleet);
        return;
    }
    case TURN_MADE:
    {
        if (size < 4)
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
    }
}

void RemotePlayer::fleetInstalledHandler(QVector<RemotePlayer::ShipInfo> fleet) throw (IncorrectFleet)
{
    if (expectFleet)
    {
        for (int i = 0; i < fleet.size(); i++)
        {
            ShipInfo ship = fleet[i];
            FleetInstaller::PlacementStatus status =
                    fleetInst->shipPlaced(ship.id, ship.size, static_cast<bool>(ship.orientation));
            if (status != FleetInstaller::OK)
            {
                throw IncorrectFleet();
            }
        }
    }
}

void RemotePlayer::turnMadeHandler(int id)
{
    if (myTurn && enemyField->attackable(id))
    {
        myTurn = false;
        attack(id);
    }
}


/*
void RemotePlayer::connectedToPlayerSlot()
{
    qDebug() << "Connection success";
}
*/

/*
void RemotePlayer::errorHandler(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug << "The remote host closed the connection.";
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug() << "The host was not found. Please check the host name and port settings.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug() << "The connection was refused by the peer.";
        break;
    default:
        qDebug << "The following error occurred: " << socketError;
    }
}
*/

/*
void RemotePlayer::connectedToPlayerSlot()
{
    qDebug() << "Connection success";
}
*/

/*
void RemotePlayer::errorHandler(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug << "The remote host closed the connection.";
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug() << "The host was not found. Please check the host name and port settings.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug() << "The connection was refused by the peer.";
        break;
    default:
        qDebug << "The following error occurred: " << socketError;
    }
}
*/
