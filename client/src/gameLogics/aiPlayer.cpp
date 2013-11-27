#include "aiPlayer.h"

// delay for turns of ai players in ms
const int AIPlayer::delay = 3 * 1000;

AIPlayer::AIPlayer(const QSharedPointer<GameField> &plrField,
				   const QSharedPointer<GameField> &enmField,
				   QObject *parent):
	Player(plrField, enmField, parent)
{
    isWounded = false;
    lastAttackResult = NOT_ATTACKED;
    for(int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    cnt = 2;
    directionChanged = false;
    currentShip = 0;
    //connect(this, SIGNAL(turnMade(int)), );
	qsrand(QTime::currentTime().msec());
}

void AIPlayer::changeDirection()
{
    switch (direction)
    {
    case (LEFT):
        direction = RIGHT;
        break;
    case(DOWN):
        direction = HIGH;
        break;
    case (RIGHT):
        direction = RIGHT;
        break;
    case (HIGH):
        direction = DOWN;
        break;

    }
    cnt = 1;
    directionChanged = true;
}

void AIPlayer::delayTurn()
{
    int id = 0;


    if((isWounded) &&
            ((lastAttackResult == WOUNDED) || directionChanged) ) // here we've found right direction for attack (3 or 4 ships)
    {

//        if(!directionChanged)
            currentShip++;
        directionChanged = false;
        switch(direction)
        {
        case LEFT:
           if(enemyField->attackable(lastAttackedCell - cnt) && ((lastAttackedCell - cnt)/10 == lastAttackedCell/10))
                id = lastAttackedCell - cnt;
           else
           {
               changeDirection();
               id = lastAttackedCell + cnt;
           }
           break;
        case DOWN:
            if(enemyField->attackable(lastAttackedCell + 10 * cnt))
                id = lastAttackedCell + 10 * cnt;
            else
            {
                changeDirection();
                id = lastAttackedCell - 10 * cnt;
            }
            break;
        case RIGHT:
            if(enemyField->attackable(lastAttackedCell  + cnt) && ((lastAttackedCell + cnt)/10 == lastAttackedCell/10))
                id = lastAttackedCell  + cnt;
            else
            {
                changeDirection();
                id = lastAttackedCell - cnt;
            }
           break;
        case HIGH:
            if (enemyField->attackable(lastAttackedCell - 10 * cnt))
                id = lastAttackedCell - 10 * cnt;
            else
            {
                changeDirection();
                id = lastAttackedCell + 10 * cnt;
            }
            break;
        }
        cnt++;
        lastAttackResult = enemyField->attack(id);
        if(lastAttackResult == MISS)
            changeDirection();

    }
    else if ((isWounded) && (lastAttackResult == MISS))
    {
        id = tryToKill(lastAttackedCell);
        lastAttackResult = enemyField->attack(id);
    }
    else
    {
        switch(lastAttackResult)
        {
        case (NOT_ATTACKED):
            id = this->chooseCell();
            lastAttackedCell = id;
            break;
        case(MISS):
            id = chooseCell();
            isWounded = false;
            clear();

            lastAttackedCell = id;
           break;
        case(WOUNDED):
            isWounded = true;
            id = tryToKill(lastAttackedCell);
            currentShip++;
            break;
        case (KILLED):
            currentShip++;
            decreaseFleet(currentShip);
            id = this->chooseCell();
            isWounded = false;
           lastAttackedCell = id;
            clear();

            break;
        }

    lastAttackResult = enemyField->attack(id);
    }

    emit turnMade(id, lastAttackResult);
}

void AIPlayer::clear()
{

    for(int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    cnt = 2;
	directionChanged = false;
    currentShip = 0;
}

int AIPlayer::tryToKill(int id)
 {

	// chose one of  neighboor cells
	int x = id % FIELD_ROW_NUM;
	int y = id / FIELD_COL_NUM;
	bool res = 0;
	int orintation = 0;
	int nextAttacked = 0;
	do
	{
		for (int i = 0; i < 3; i++)
		{
			if (attackedCells[i] == 0 ) //
			{
				nextAttacked = i;
				orintation = i;
                break;
			}
		}

		switch (nextAttacked)
		{
		case LEFT:
			if((x - 1 >= 0) && (enemyField->attackable(id - 1)))
			{
				nextAttacked = id - 1;
				direction = LEFT;
				break;
			}
		case DOWN:
			if ((y + 1 <= 10) && (enemyField->attackable(id + 10))
)            {
				nextAttacked = id + 10;
				direction = DOWN;
				break;
			}
		case RIGHT:
			if ((x + 1 <= 10) && (res = enemyField->attackable(id + 1)))
			{
				nextAttacked = id  + 1;
				direction = RIGHT;
				break;
			}
		case HIGH:
			if ((y - 1 >= 0) && (res = enemyField->attackable(id - 10)))
			{
				nextAttacked = id - 10;
				direction = HIGH;
				break;
			}
		}

		res = enemyField->attackable(nextAttacked); // check for cell were'nt visited earlyer
	}
	while (!res);
	attackedCells[orintation] = nextAttacked; // remember attacked cell
  //  direction = static_cast<Direction>(orintation); // remember attacking direction
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


