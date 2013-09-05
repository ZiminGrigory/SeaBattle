#include "aiPlayer.h"

AIPlayer::AIPlayer(QObject *parent)
{
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
}

void AIPlayer::installFleet()
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
        QPair<int, int> ids(0, 0);
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
            ids.first = getIdByCoordinates(point1);
            ids.second = getIdByCoordinates(point2);
        } while(fleetInstaller->shipPlaced(ids) != FleetInstaller::OK);
    }
}

void AIPlayer::turn()
{
    int id = 0;
    bool res = false;
    do
    {
        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
        res = enemyField.attack(id);
    }
    while (!res);
    emit turnMade(id);
}


