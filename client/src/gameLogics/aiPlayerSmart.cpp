#include "aiPlayerSmart.h"

AIPlayerSmart::AIPlayerSmart(const QSharedPointer<GameField> &plrField,
                                const QSharedPointer<GameField> &enmField,
                                 QObject *parent):
    AIPlayer(plrField, enmField, parent)
{
    qsrand(QTime::currentTime().msec());
    aerocarrier = 1;
    destroyer = 2;
    cruiser = 3;
    smallship = 4;

    strategy = new DiagonalShoot(enmField); // will be random for each square
}

void AIPlayerSmart::installFleet()
{
    this->randomInstallFleet();
    emit fleetInstalled(this);
}

void AIPlayerSmart::turn()
{
  QTimer::singleShot(AIPlayer::delay, this, SLOT(delayTurn()));

}

int AIPlayerSmart::chooseCell()
{

    if (aerocarrier == 1) // trying to find biggest ship
    {
        for (int i = 0; i < 3; i++) // for now I've made square choose just in order. In future it will be random.
        {
            for (int j = 0; j < 3; j++)
            {
                if (!strategy->fourSquareShooted(i, j))
                    return strategy->fourSquare(i, j); // method returns one of diagonals cells
           }
        }
    }
    if (cruiser != 0) // now we finding some 3 ships
    {
        for (int i = 0; i < 4; i ++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (!strategy->threeSquareShooted(i,j))
                    return strategy->threeSquare(i,j);
            }

        }

    }
    if (destroyer != 0) // 2 ships
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if(!strategy->twoSquareShooted(i, j))
                    return strategy->twoSquare(i,j);
            }

        }
    }
    return chooseRandomCell();
    // if we came here  there are left only small ships, there's no special rules to find them


}

void AIPlayerSmart::decreaseFleet(int currentShip)
{
    switch (currentShip) {
    case BOAT_SCOUT:
        smallship--;
        break;
    case DESTROYER:
        destroyer--;
        break;
    case CRUISER:
        cruiser--;
        break;
    case AEROCARRIER:
        aerocarrier--;
        break;
    default:
        break;

    }

}
