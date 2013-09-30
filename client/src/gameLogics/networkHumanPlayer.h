#ifndef NETWORKHUMANPLAYER_H
#define NETWORKHUMANPLAYER_H

#include <QSharedPointer>
#include <QTcpSocket>

#include "humanPlayer.h"
#include "client.h"

/**
  * Subclass of human player that implements human player gamed with the remote player by network.
  * This class does the same as a HumanPlayer but also sends notices about its actions to the remote player by network.
  */
class NetworkHumanPlayer : public HumanPlayer
{
    Q_OBJECT
public:
    /**
      * @var _socket Constructor expects recieve QTcpSocket connected with the remote instance of game client.
      */
    NetworkHumanPlayer(const QSharedPointer<GameField> &plrField,
                       const QSharedPointer<GameField>& enmField,
                       const QSharedPointer<FieldView>& _plrFieldView,
                       const QSharedPointer<FieldView>& _enmFieldView,
                       const QSharedPointer<InfoTabView>& _infoTab,
                       const QSharedPointer<Client>& _client,
                       QObject *parent = 0);

public slots:
    void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
protected slots:
    void cellWasAttacked(int id);
private slots:
   /**
     * Sends player's fleet to the remote instance of the game client.
     */
    void sendPlayerFleet(QVector<FleetInstaller::ptrShip> fleet);
private:
    QSharedPointer<Client> client;
};


#endif // NETWORKHUMANPLAYER_H
