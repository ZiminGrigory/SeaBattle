#pragma once

#include <QTcpSocket>
#include <QSharedPointer>
#include <QDebug>

#include "player.h"
#include "protocol.h"

/**
  * Class implements the client-listener methods for the receiving messages from the remote player.
  */
class RemotePlayer : public Player
{
    Q_OBJECT
public:
    /**
      * Throws when object recieves incorrect request from remote player.
      */
    class IncorrectRequest {};
    /**
      * Throws when object recieves incorrect fleet from remote player.
      */
    class IncorrectFleet {};

    /**
      * @var _socket Constructor expects recieve QTcpSocket connected with the remote computer.
      */
    RemotePlayer(const QSharedPointer<GameField>& plrField,
                 const QSharedPointer<GameField>& enmField,
                 QSharedPointer<QTcpSocket>& _socket);

    /**
      *
      */
    void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
public slots:
    /**
      *
      */
    void turn();
private slots:
    /**
      *
      */
    void readyReadSlot();
private:
    /**
      *
      */
    void parseRecievedRequest(QDataStream &message, quint16 size) throw(IncorrectRequest, IncorrectFleet);
    /**
      *
      */
    void fleetInstalledHandler(QVector<Protocol::ShipInfo> fleet) throw (IncorrectFleet);
    /**
      *
      */
    void turnMadeHandler(int id);

    QSharedPointer<QTcpSocket> socket;
    quint16 blockSize;

    bool myTurn;
    bool expectFleet;

    QSharedPointer<FleetInstaller> fleetInst;
    QVector<Protocol::ShipInfo> enemyFleetCopy;

    static const qint16 port;
};
