#include "networkHumanPlayer.h"

using namespace Protocol;

NetworkHumanPlayer::NetworkHumanPlayer(const QSharedPointer<GameField>& plrField,
                                       const QSharedPointer<GameField>& enmField,
									   const QSharedPointer<InterfaceField> &_plrFieldView,
									   const QSharedPointer<InterfaceField> &_enmFieldView,
									   const QSharedPointer<InterfaceInfoTab> &_infoTab,
                                       const QSharedPointer<Client>& _client,
									   QObject* parent):
    HumanPlayer(plrField,enmField,_plrFieldView,_enmFieldView, _infoTab, parent),
    client(_client)
{
}

void NetworkHumanPlayer::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    fleetInst = fleetInstaller;
    setFleetHealth(fleetInst->getFleet());

    connect(fleetInst.data(), SIGNAL(fleetInstalled(QVector<ptrShip>)),
            this, SLOT(sendPlayerFleet(QVector<ptrShip>)));
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

void NetworkHumanPlayer::sendPlayerFleet(QVector<ptrShip> fleet)
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
        if (shipInfo.size > 1)
        {
            if (ship->getCoordinate().at(1) == (ship->getCoordinate().at(0) + 1))
            {
                shipInfo.orientation = true;
            }
            else
            {
                shipInfo.orientation = false;
            }
            out << shipInfo.size << shipInfo.id << shipInfo.orientation;
        }
        else
        {
            out << shipInfo.size << shipInfo.id << quint8(0);
        }
    }
    client->send(Protocol::FLEET_INSTALLED, byteArray);

    emit fleetInstalled(this);
}
