#include "ship.h"


QVector<int> Ship::getCoordinate()
{
	return coordinates;
}


void Ship::appedIdOfPart(int id)
{
	coordinates.append(id);
}
