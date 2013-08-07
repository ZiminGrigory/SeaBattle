#include "aiPlayer.h"

AIPlayer::AIPlayer(QObject *parent)
{
    //connect(this, SIGNAL(turnMade(int)), );
}

void AIPlayer::turn()
{
    qsrand(QTime::currentTime().msec());
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


