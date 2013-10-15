#pragma once

#include <QTcpSocket>
#include <QSharedPointer>
#include <QDebug>

#include "player.h"
#include "client.h"

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
                 QSharedPointer<Client>& _client);

    /**
      *
      */
    void installFleet();
public slots:
    /**
      *
      */
    void turn();
private slots:
    /**
      *
      */
    void parseRecievedRequest(Protocol::RequestType, const QByteArray& bytes) throw(IncorrectRequest, IncorrectFleet);
private:
    /**
      *
      */
    void fleetInstalledHandler(QVector<Protocol::ShipInfo> fleet) throw (IncorrectFleet);
    /**
      *
      */
    void turnMadeHandler(int id);
    /**
     *
     */
    void chatMessageHandler(const QString& message);

    QSharedPointer<Client> client;

    bool myTurn;
    bool expectFleet;

    QVector<Protocol::ShipInfo> enemyFleetCopy;
};
