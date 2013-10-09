#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QtGlobal>
#include <QDataStream>

namespace Protocol
{
    /**
      *
      */
    const QString ServerName = "127.0.0.1";
    /**
      *
      */
	const quint16 ServerPort = 21539;
    /**
      *
      */
	const quint16 ClientPort = 21433;
    /**
      *
      */
	const quint16 ClientPortTest = 21434;
    /**
      *
      */
    const QDataStream::Version QDataStreamVersion = QDataStream::Qt_4_8;
    /**
      * Types of requsts which clients can send to server or to other client
      */
    enum RequestType
    {
        // Request from server to client for getting the information about client state.
        CHECK_STATE = 1,
        // Request which is informing about founded enemy for multiplayer.
        // Request also contains port and hostname of the remote player.
        GAME_FOUND = 2,
        // response on CHECK_STATE request from server.
        // It is used to check whether player still looking for a game.
        SEEKING_GAME = 10,
        // request to server for the game searching
        // also contains port of supported socket
        SEARCH_GAME = 20,
        // this request is sent after the remote player installed his fleet
        // expected that next 30 bytes describe the fleet (each ship is defined by his top left id, size & orientation)
        FLEET_INSTALLED = 30,
        // message about remote player's turn
        // expected that next byte are the id of attacked cell
        TURN_MADE = 31
    };

    /**
      * Some classes of the exceptins.
      */

    /**
      * Thrown when object connect() method was called but client is already connected.
      */
    class AlreadyConnected {};
    /**
      * Thrown when object can't send messages.
      */
    class SendingForbidden {};
    /**
      * Thrown when object can't send requests of specific type in current state.
      */
    class RequestTypeForbidden {};

    /**
      * Special struct for sending and receiving fleet by remote players.
      */
    struct ShipInfo
    {
        quint8 size;
        quint8 id;
        // true - horizontal, false - vertical
        bool orientation;
    };
}

#endif // PROTOCOL_H
