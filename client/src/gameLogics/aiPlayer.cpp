#include "aiPlayer.h"

AIPlayer::AIPlayer(const QSharedPointer<GameField> &plrField,
                   const QSharedPointer<GameField> &enmField,
                   QObject *parent):
    Player(plrField, enmField, parent)
{
    for(int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
}



int AIPlayer::tryToKill(int id)
 {

    // chose one of  neighboor cells

    int x = id / FIELD_ROW_NUM;
    int y = id % FIELD_COL_NUM;
    bool res = 0;
    int orintation = 0;
    int nextAttacked = 0;
    do
    {
        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
        res = enemyField->attackable(id);
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

        res = enemyField->attackable(nextAttacked); // check for cell were'nt visited earlyer
    }
    while (!res);
    attackedCells[orintation] = nextAttacked; // remember attacked cell
    direction = static_cast<Direction>(orintation); // remember attacking direction
    return nextAttacked;
 }

//void AIPlayer::turn()
//{
//    int id = 0;
//    bool res = false;
//    do
//    {
//        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
//     //   res =  enmField. //attack(id);
//    }
//    while (!res);
//    attack(id);
//}


