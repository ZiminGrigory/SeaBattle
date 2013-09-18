#pragma once

#include <QTcpSocket>
#include <QSharedPointer>
#include <QDebug>

#include "player.h"

/**
  * Class implements the client-listener methods for the receiving messages from the remote player.
  */
class RemotePlayer : public Player
{
    Q_OBJECT
public:
    /**
      *
      */
    class IncorrectRequest {};
    /**
      *
      */
    class IncorrectFleet {};

    /**
      *
      */
    enum RequestType
    {
        // this request is sent after the remote player installed his fleet
        FLEET_INSTALLED = 20,
        // message about remote player's turn
        // expected that next byte are the id of attacked cell
        TURN_MADE = 21
    };
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
    /**
      * Connection with remote player.
      */
    //void connectToPlayer(const QString& hostname);
public slots:
    /**
      *
      */
    void turn();
    /**
      *
      */
    void enemyTurn(int id);
signals:
    /**
      * Emits when client recieves message about the remote player's turn.
      */
    //void turnMade(int id);
private slots:
    /**
      *
      */
    //void connectedToPlayerSlot();
    /**
      *
      */
    //void errorHandler(QAbstractSocket::SocketError socketError);
    /**
      *
      */
    void readyReadSlot();
    /**
      * This slot sent placement of human player's ship to the another game client.
      */
    void sendPlayerFleet(QVector<FleetInstaller::ptrShip> fleet);
private:
    /**
      * Special struct for sending and receiving fleet by remote players.
      */
    struct ShipInfo
    {
        quint8 size;
        quint8 id;
        // true - horizontal, false - vertical
        quint8 orientation;
    };
    /**
      *
      */
    void parseRecievedRequest(QDataStream &message, quint16 size) throw(IncorrectRequest, IncorrectFleet);
    /**
      *
      */
    void fleetInstalledHandler(QVector<ShipInfo> fleet) throw (IncorrectFleet);
    /**
      *
      */
    void turnMadeHandler(int id);

    QSharedPointer<QTcpSocket> socket;
    quint16 blockSize;

    bool myTurn;
    bool expectFleet;

    QSharedPointer<FleetInstaller> fleetInst;
    QVector<ShipInfo> enemyFleetCopy;

    static const qint16 port;
};
