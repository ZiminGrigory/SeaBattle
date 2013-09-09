#include "aiPlayerSimple.h"

AIPlayerSimple::AIPlayerSimple(View *view, QObject *parent):
    AIPlayer(view)
{
    myField.setPlr(NONE);
    enemyField.setPlr(YOU);
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
    successShot = false;
    isWounded = false;
    lastAttackedCell = -1;
    lastAttackResult = NOT_ATTACKED;
}

void AIPlayerSimple::installFleet()
{
    for (int i = 0; i < fleet.size(); i++)
    {
        int shipSize = fleet[i]->size();
        bool isHorizontal = true;
        if (qrand() % 2 == 0)
        {
            isHorizontal == false;
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
            while (!isHorizontal && row > FIELD_ROW_NUM - shipSize);
            do
            {
                col = qrand() % FIELD_COL_NUM;
            }
            while(isHorizontal && col > FIELD_COL_NUM - shipSize);

            QPair<int, int> point1(row, col);
            QPair<int, int> point2(row, col);
            if (isHorizontal)
            {
                point2.second + shipSize;
            }
            else
            {
                point2.first + shipSize;
            }
            first = getIdByCoordinates(point1);
            second = getIdByCoordinates(point2);

            status = fleetInstaller->shipPlaced(first, second);
            bool b = (status != FleetInstaller::OK) ||
                    (status != FleetInstaller::HAVE_NOT_SHIP);
            bool d = true;

        } while((status != FleetInstaller::OK) &&
                (status != FleetInstaller::HAVE_NOT_SHIP));
    }
}

int AIPlayerSimple::chooseRandomCell()
{
    int id = 0;
    bool res = false;
    do
    {
        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
        res = enemyField.attack(id);
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

        lastAttackedCell = id;
    }
    emit turnMade(id);
}

