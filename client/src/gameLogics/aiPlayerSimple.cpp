#include "aiPlayerSimple.h"

AIPlayerSimple::AIPlayerSimple(const QSharedPointer<GameField> &plrField,
								const QSharedPointer<GameField> &enmField,
								 QObject *parent):
    AIPlayer(plrField, enmField, parent)
{

    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());



}

void AIPlayerSimple::installFleet()
{
    this->randomInstallFleet();
	emit fleetInstalled(this);
}

int AIPlayerSimple::chooseCell()
{
    return chooseRandomCell();
}


void AIPlayerSimple::decreaseFleet(int currentShip)
{
    //do nothing
}

void AIPlayerSimple::turn()
{
    QTimer::singleShot(AIPlayer::delay, this, SLOT(delayTurn()));
}



