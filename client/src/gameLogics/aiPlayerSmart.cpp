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
    currentSquare.first = -1;
    currentSquare.second = -1;
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

    int i = currentSquare.first;
    int j = currentSquare.second;

   if (aerocarrier == 1) // trying to find biggest ship
    {
        while(currentSquare.first == -1 || strategy->fourSquareShooted(i, j))
        {
            i = qrand()%3;
            j = qrand()%3;
            currentSquare.first = i;
            currentSquare.second = j;

        }

        return strategy->fourSquare(i, j); // method returns one of diagonals cells
    }
    if (destroyer != 0) // now we finding some 3 ships
    {
        while(currentSquare.first == -1 || strategy->threeSquareShooted(i, j))
        {
            i = qrand()%4;
            j = qrand()%4;
            currentSquare.first = i;
            currentSquare.second = j;
        }

        return strategy->threeSquare(i,j);

    }
    if (cruiser != 0)
     // 2 ships
    {

        while(currentSquare.first == -1 || strategy->twoSquareShooted(i, j))
        {
            i = qrand()%5;
            j = qrand()%5;
            currentSquare.first = i;
            currentSquare.second = j;
        }
        return strategy->twoSquare(i, j);

    }
    return chooseRandomCell();
    // if we came here  there are left only small ships, there's no special rules to find them


}

void AIPlayerSmart::decreaseFleet(int currentShip)
{
    switch (currentShip) {
    case 1:
        smallship--;
        break;
    case 3:
        destroyer--;
        break;
    case 2:
        cruiser--;
        break;
    case 4:
        aerocarrier--;
        break;
    default:
        break;

    }
    currentSquare.first = -1;
    currentSquare.second = -1;
}