#include "gameField.h"

void GameField::setShip(int id, bool orientation, QSharedPointer<Ship> ship)
{
    QPair<int, int> coord = coordinates(id);
    int row = coord.first;
    int col = coord.second;
    int shipSize = ship->size();
    // if orientation == true, then ship has horizontal orientation
    if (orientation)
    {
        for (int i = 0; i < shipSize; i++)
        {
            field[row][col + i].setShip(ship);
            view->paintCell(plr, getIdByCoordinates(row, col + i), textureOfCell(i + 1, shipSize, orientation));
        }
    }
    // otherwise - vertical orientation
    else
    {
        for (int i = 0; i < shipSize; i++)
        {
            field[row + i][col].setShip(ship);
            view->paintCell(plr, getIdByCoordinates(row + i, col), textureOfCell(i + 1, shipSize, orientation));
        }
    }
}

QSharedPointer<Ship> GameField::getShip(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;
    if (!checkCoord(x, y))
    {
        return QSharedPointer<Ship>();
    }
    return field[x][y].getShip();
}

void GameField::removeShip(int id)
{
    QPair<int, int> coordinateOfShip = coordinates(id);
    int row = coordinateOfShip.first;
    int column = coordinateOfShip.second;
    QSharedPointer<Ship> ship = field[row][column].getShip();
    int size = ship.data()->size();
    view->changeCounter(NameOfShips(size - 1), 1);
    view->paintCell(plr, id, EMPTY);
    bool isAll = true;
    if (size != 1){
        do{
            row++;
            if (row <= 9){
                QSharedPointer<Ship> shipTmp = field[row][column].getShip();
                if (shipTmp != NULL){
                    view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
                    field[row][column].deleteShip();
                } else {
                    isAll = false;
                }
            }
        } while (row <= 9 && isAll);
        row = coordinateOfShip.first;
        isAll = true;
        do{
            row--;
            if (row >= 0){
                QSharedPointer<Ship> shipTmp = field[row][column].getShip();
                if (shipTmp != NULL){
                    view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
                    field[row][column].deleteShip();
                } else {
                    isAll = false;
                }
            }
        } while (row >= 0 && isAll);
        row = coordinateOfShip.first;
        isAll = true;
        do{
            column++;
            if (column <= 9){
                QSharedPointer<Ship> shipTmp = field[row][column].getShip();
                if (shipTmp != NULL){
                    view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
                    field[row][column].deleteShip();
                } else {
                    isAll = false;
                }
            }
        }while (column <= 9 && isAll);
        column = coordinateOfShip.second;
        isAll = true;
        do{
            column--;
            if (column <= 9){
                QSharedPointer<Ship> shipTmp = field[row][column].getShip();
                if (shipTmp != NULL){
                    view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
                    field[row][column].deleteShip();
                } else {
                    isAll = false;
                }
            }
        } while (column >= 0 && isAll);
    }
    field[coordinateOfShip.first][coordinateOfShip.second].deleteShip();
}

AttackStatus GameField::attack(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;

    if (res == MISS)
    {
        view->paintCell(ENEMY, getIdByCoordinates(x, y), MISS_CELL);
        field[x][y].mark(res);
    }
    else if (res == WOUNDED)
    {
        view->paintCell(ENEMY, getIdByCoordinates(x, y), SHIP_DAMAGED);
        field[x][y].mark(res);
    }
    else if (res == KILLED)
    {
        view->paintCell(ENEMY, getIdByCoordinates(x, y), SHIP_KILLED);
        field[x][y].mark(res);
        QStack<Coord> markedCells;
        markedCells.push(Coord(x, y));
        while (!markedCells.isEmpty())
        {
            Coord coord = markedCells.pop();
            int _x = coord.first;
            int _y = coord.second;
            markKilled(_x + 1, _y, &markedCells);
            markKilled(_x + 1, _y + 1, &markedCells);
            markKilled(_x, _y + 1, &markedCells);
            markKilled(_x - 1, _y + 1, &markedCells);
            markKilled(_x - 1, _y, &markedCells);
            markKilled(_x - 1, _y - 1, &markedCells);
            markKilled(_x, _y - 1, &markedCells);
            markKilled(_x + 1, _y - 1, &markedCells);
        }
    }
}


void GameField::markKilled(int i, int j, QStack<Coord>* markedCells)
{
    if (checkCoord(i, j))
    {
        if (field[i][j].getAttackStatus() == KILLED)
        {
            view->paintCell(plr, getIdByCoordinates(i, j), SHIP_KILLED);
            return;
        }
        else if (field[i][j].getAttackStatus() == WOUNDED)
        {
            field[i][j].mark(KILLED);
            view->paintCell(plr, getIdByCoordinates(i, j), SHIP_KILLED);
            markedCells->push(Coord(i, j));
        }
        else
        {
            field[i][j].mark(MISS);
            view->paintCell(plr, getIdByCoordinates(i, j), MISS_CELL);
        }
    }
}

bool GameField::attackable()
{
    int i = id / FIELD_ROW_NUM;
    int j = id % FIELD_COL_NUM;
    if (!checkCoord(i, j) || !field[i][j].attackable())
    {
        return false;
    }
    else
    {
        return true;
    }
}

Textures PlayerField::textureOfCell(int i, int shipSize, bool orientation)
{
    switch (shipSize) {
    case 1:
        return SHIP_SINGLE;
        break;
    case 2:{
        if (orientation) { //horizontally
            if (i == 1) {
                return SHIP_BOW_HORIZONTAL;
            }else {
                return SHIP_POOP_HORIZONTAL;
            }
        } else {
            if (i == 1) {
                return SHIP_BOW_VERTICAL;
            }else {
                return SHIP_POOP_VERTICAL;
            }
        }
    }
    break;
    case 3:{
        if (orientation) { //horizontally
            switch (i) {
            case 1:
                return SHIP_BOW_HORIZONTAL;
                break;
            case 2:
                return SHIP_DECK_HORIZONTAL;
                break;
            case 3:
                return SHIP_POOP_HORIZONTAL;
                break;
            }
        } else {
            switch (i) {
            case 1:
                return SHIP_BOW_VERTICAL;
                break;
            case 2:
                return SHIP_DECK_VERTICAL;
                break;
            case 3:
                return SHIP_POOP_VERTICAL;
                break;
            }
        }
    }
    break;
    case 4:{
        if (orientation) { //horizontally
            switch (i) {
            case 1:
                return SHIP_BOW_HORIZONTAL;
                break;
            case 2:
                return SHIP_DECK_HORIZONTAL;
                break;
            case 3:
                return SHIP_DECK_HORIZONTAL;
                break;
            case 4:
                return SHIP_POOP_HORIZONTAL;
                break;
            }
        } else {
            switch (i) {
            case 1:
                return SHIP_BOW_VERTICAL;
                break;
            case 2:
                return SHIP_DECK_VERTICAL;
                break;
            case 3:
                return SHIP_DECK_VERTICAL;
                break;
            case 4:
                return SHIP_POOP_VERTICAL;
                break;
            }
        }
    }
    break;
    }
}
