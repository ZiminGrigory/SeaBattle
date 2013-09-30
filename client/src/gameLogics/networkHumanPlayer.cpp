#include "networkHumanPlayer.h"

using namespace Protocol;

NetworkHumanPlayer::NetworkHumanPlayer(const QSharedPointer<GameField>& plrField,
                                       const QSharedPointer<GameField>& enmField,
                                       const QSharedPointer<FieldView>& _plrFieldView,
                                       const QSharedPointer<FieldView>& _enmFieldView,
                                       const QSharedPointer<InfoTabView>& _infoTab,
                                       const QSharedPointer<Client>& _client,
                                       QObject* parent):
    HumanPlayer(plrField,enmField,_plrFieldView,_enmFieldView, _infoTab),
    client(_client)
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
    out.setVersion(Protocol::QDataStreamVersion);
    out << quint8(id);

    client->send(Protocol::TURN_MADE, byteArray);
}

void NetworkHumanPlayer::sendPlayerFleet(QVector<FleetInstaller::ptrShip> fleet)
{
    QByteArray byteArray;
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.setVersion(Protocol::QDataStreamVersion);

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
    client->send(Protocol::FLEET_INSTALLED, byteArray);
}
