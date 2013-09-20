#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QtGlobal>

namespace Protocol
{
    /**
      * Types of requsts which clients can send to server or to other client
      */
    enum RequestType
    {
        // this request is sent after the remote player installed his fleet
        // expected that next 30 bytes describe the fleet (each ship is defined by his top left id, size & orientation)
        FLEET_INSTALLED = 20,
        // message about remote player's turn
        // expected that next byte are the id of attacked cell
        TURN_MADE = 21
    };

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
}

#endif // PROTOCOL_H
