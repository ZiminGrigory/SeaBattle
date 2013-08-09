#ifndef GAMEMASTERTEST_H
#define GAMEMASTERTEST_H

#include <QObject>
#include <QScopedPointer>
#include <QtTest/QtTest>

#include "playerTest.h"
#include "../../src/gameMaster.h"

class GameMasterTest : public QObject
{
    Q_OBJECT
public:
    explicit GameMasterTest(QObject *parent = 0):
        QObject(parent)
    {}

signals:

private slots:
    // test the sequance of calling signals and slots after GameMaster start new turn.
    void turnTest()
    {
        Player* plr1 = new AIPlayer;
        Player* plr2 = new AIPlayer;
        EmptyFleetCreator fleetCreator;
        GameMaster master(plr1, plr2, fleetCreator);

        QSignalSpy turnMadeSpy(plr1, SIGNAL(turnMade(int)));
        QSignalSpy attackResultSpy(plr2, SIGNAL(attackResult(AttackStatus)));

        master.offerTurn();

        // check that player1 made turn and player2 report about result of attack on him.
        QCOMPARE(turnMadeSpy.first().count(), 1);
        QCOMPARE(attackResultSpy.first().count(), 1);
    }
};

#endif // GAMEMASTERTEST_H
