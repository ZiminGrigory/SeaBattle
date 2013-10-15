#include "aiPlayerSmart.h"

AIPlayerSmart::AIPlayerSmart(const QSharedPointer<GameField> &plrField,
                                const QSharedPointer<GameField> &enmField,
                                 QObject *parent):
    AIPlayer(plrField, enmField, parent)
{
    qsrand(QTime::currentTime().msec());
}

void AIPlayerSmart::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    this->randomInstallFleet(fleetInstaller);
    emit fleetInstalled(this);
}

void AIPlayerSmart::turn()
{
    QTimer::singleShot(AIPlayer::delay, this, SLOT(delayTurn()));

}
void AIPlayerSmart::delayTurn()
{
    int id = this->chooseRandomCell();
    lastAttackResult = enemyField->attack(id);
    emit turnMade(id, lastAttackResult);
}
