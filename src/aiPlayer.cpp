#include "aiPlayer.h"

AIPlayer::AIPlayer(View *view, QObject *parent):
    Player(view)
{
    myField.setPlr(NONE);
    enemyField.setPlr(YOU);
    for (int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    //success = false;
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
}

int AIPlayer::tryToKill(int id)
{
    // chose one of  neighboor cells

    int x = id / FIELD_ROW_NUM;
    int y = id % FIELD_COL_NUM;
    bool res = 0;
    int orintation;
    int nextAttacked = 0;
    do
    {
        for (int i = 0; i < 3; i++)
        {
            if (attackedCells[i] == 0 ) //
            {
                nextAttacked = i;
                orintation = i;
            }
        }
        switch (nextAttacked)
        {
        case LEFT:
            nextAttacked = id - 1;
            break;
        case DOWN:
            nextAttacked = id + 10;
            break;
        case RIGHT:
            nextAttacked = id  + 1;
            break;
        case HIGH:
            nextAttacked = id - 10;
            break;

        }
        res = enemyField.attack(nextAttacked); // check for cell were'nt visited earlyer
    }
    while (!res);
    attackedCells[orintation] = nextAttacked;
    direction = static_cast<Direction>(orintation); // remember attacking direction
    return nextAttacked;
}



