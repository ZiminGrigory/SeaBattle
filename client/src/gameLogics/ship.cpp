#include "ship.h"


QVector<int> Ship::getCoordinate()
{
	return coordinates;
}

void Ship::clearCoordinate()
{
	coordinates.clear();
}


void Ship::appedIdOfPart(int id)
{
    coordinates.append(id);
    if (size() == 1)
    {
        return;
    }
    // insertion sort
    // ids will saved in ascending order
    bool swap = false;
    int j = coordinates.size() - 1;
    do
    {
        swap = false;
        if (j - 1 < 0)
        {
            continue;
        }
        if (coordinates[j] < coordinates[j - 1])
        {
            int tmp = coordinates[j];
            coordinates[j - 1] = coordinates[j];
            coordinates[j] = tmp;
            swap = true;
            j--;
        }
    } while (swap && (j > 0));
}
