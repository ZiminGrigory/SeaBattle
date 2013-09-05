#ifndef TYPES_H
#define TYPES_H

#include <QPair>
#include <QSharedPointer>


enum AttackStatus
{
    NOT_ATTACKED,
    MISS,
    WOUNDED,
    KILLED
};

enum NameOfShips{
	AEROCARRIER,
	CRUISER,
	DESTROYER,
	BOAT_SCOUT
};

enum Players{
	YOU,
	ENEMY
};

const int FIELD_ROW_NUM = 10;
const int FIELD_COL_NUM = 10;

const int sizeOfCube = 300;
inline QPair<int, int> coordinates(int id)
{
    return QPair<int, int>(id / FIELD_ROW_NUM, id % FIELD_COL_NUM);
}

inline int getIdByCoordinates(const QPair<int, int>& point)
{
    return point.first * FIELD_ROW_NUM + point.second;
}

inline bool checkCoord(int x, int y)
{
    return !((x < 0) || (x >= FIELD_ROW_NUM) || (y < 0) || (y >= FIELD_COL_NUM));
}
#endif // TYPES_H


