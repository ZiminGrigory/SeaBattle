#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/player.h"
#include "../../src/aiPlayer.h"

// fleet factory class for test purpose
class EmptyFleetCreator : public FleetFactory
{
    QVector<ptrShip> createFleet() const
    {
        return QVector<ptrShip>(0);
    }
};

// test some common for any players methods and slots.
class PlayerTest : public QObject
{
    Q_OBJECT
private slots:
    // test createFleet() method.
    void createFleetTest()
    {
        QScopedPointer<Player> player(new AIPlayer);

        // with empty fleet player will automaticly lose.
        player->createFleet(EmptyFleetCreator());
        QCOMPARE(player->lose(), true);

        player->createFleet(FleetFactory());
        QCOMPARE(player->lose(), false);
    }
};

#endif // PLAYERTEST_H
