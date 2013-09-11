#include "aiPlayerSimple.h"

AIPlayerSimple::AIPlayerSimple(const QSharedPointer<GameField> &plrField,
								const QSharedPointer<GameField> &enmField,
								 QObject *parent):
    AIPlayer(plrField, enmField, parent)
{
    isWounded = false;
    lastAttackResult = NOT_ATTACKED;
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
}

void AIPlayerSimple::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    QVector<FleetInstaller::ptrShip> fleet = fleetInstaller->getFleet();
    setFleetHealth(fleet);
    for (int i = 0; i < fleet.size(); i++)
    {
        int shipSize = fleet[i]->size();
        bool isHorizontal = true;
      //  qsrand(QTime::currentTime().msec());
        int smth = qrand()% 20 - qrand() % 20;
        if (smth > 0)
        {
            isHorizontal = false;
        }

        int row = 0;
        int col = 0;
        int first = 0;

        int second = 0;
        FleetInstaller::PlacementStatus status = FleetInstaller::OK;
        do
        {
            do
            {
                row = qrand() % FIELD_ROW_NUM;
            }
            while (!isHorizontal && (row > FIELD_ROW_NUM - shipSize));
            do
            {
                col = qrand() % FIELD_COL_NUM;
            }
            while(isHorizontal && col > (FIELD_COL_NUM - shipSize));

            QPair<int, int> point1(row, col);
            QPair<int, int> point2(row, col);

            if (isHorizontal)
			{
                point2.second += shipSize - 1;
            }
            else
            {
                point2.first += shipSize - 1;
            }
            first = getIdByCoordinates(point1);
            second = getIdByCoordinates(point2);

            status = fleetInstaller->shipPlaced(first, second);

        } while((status != FleetInstaller::OK) &&
                (status != FleetInstaller::HAVE_NOT_SHIP));
    }
    emit fleetInstalled(this);
}

int AIPlayerSimple::chooseRandomCell()
{
    int id = 0;
    bool res = false;
    do
    {
        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
        res = enemyField->attackable(id);
    }
    while (!res);
    return id;
}

void AIPlayerSimple::turn()
{
    int id = 0;
    if((isWounded) && (lastAttackResult == WOUNDED)) // here we've found right direction for attack (3 or 4 ships)
    {
        switch(direction)
        {
        case LEFT:
            id = lastAttackedCell - 1;
            break;
        case DOWN:
            id = lastAttackedCell + 10;
            break;
        case RIGHT:
            id = lastAttackedCell  + 1;
            break;
        case HIGH:
            id = lastAttackedCell - 10;
            break;
        }
    }
    else if ((isWounded) && (lastAttackResult == MISS))
    {
        id = tryToKill(lastAttackedCell);
    }
    else
    {
        switch(lastAttackResult)
        {
        case (NOT_ATTACKED):
            id = chooseRandomCell();
            break;
        case(MISS):
            id = chooseRandomCell();
            isWounded = false;
            break;
        case(WOUNDED):
            id = tryToKill(lastAttackedCell);
            isWounded = true;
            break;
        case (KILLED):
            id = chooseRandomCell();
            isWounded = false;
            break;
        }
//        for(int i = 0; i < 3; i++)
//            attackedCells[i] = 0;
        lastAttackedCell = id;
    }
    lastAttackResult = enemyField->attack(id);
    emit turnMade(id, lastAttackResult);
}

