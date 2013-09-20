#include "networkHumanPlayer.h"

using namespace Protocol;

NetworkHumanPlayer::NetworkHumanPlayer(const QSharedPointer<GameField>& plrField,
                                       const QSharedPointer<GameField>& enmField,
                                       const QSharedPointer<FieldView>& _plrFieldView,
                                       const QSharedPointer<FieldView>& _enmFieldView,
                                       const QSharedPointer<InfoTabView>& _infoTab,
                                       const QSharedPointer<QTcpSocket>& _socket,
                                       QObject* parent):
    HumanPlayer(plrField,enmField,_plrFieldView,_enmFieldView, _infoTab),
    socket(_socket)
{
}

void NetworkHumanPlayer::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    HumanPlayer::installFleet(fleetInstaller);

    connect(fleetInst.data(), SIGNAL(fleetInstalled(QVector<FleetInstaller::ptrShip)),
            this, SLOT(sendPlayerFleet(QVector<FleetInstaller::ptrShip>)));
}

void NetworkHumanPlayer::cellWasAttacked(int id)
{
    HumanPlayer::cellWasAttacked(id);

    QByteArray byteArray;
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    out << quint16(4) << quint8(Protocol::TURN_MADE) << quint8(id);
    socket->write(byteArray);
}

void NetworkHumanPlayer::sendPlayerFleet(QVector<FleetInstaller::ptrShip> fleet)
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
