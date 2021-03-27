#include "Mapping.h"

Mapping::Mapping()
{
    this->rows = 0;
    this->columns = 0;
}

Mapping::Mapping(int** map, int rows, int columns)
{
    this->map = map;
    this->rows = rows;
    this->columns = columns;
}

void Mapping::setMap(int** map)
{
    this->map = map;
}

int** Mapping::getMap()
{
    return this->map;
}

Mapping::~Mapping()
{
    if (this->rows <= 0) {
        return;
    }
    for (int i = 0; i < this->rows; ++i) {
        delete this->map[i];
    }
    delete this->map;
}

bool Mapping::canMove(Coordinate coordinate)
{
    return this->map[coordinate.getX()][coordinate.getY()] != 2;
}

bool Mapping::canCollectResource(Coordinate coordinate)
{
    return this->map[coordinate.getX()][coordinate.getY()] == 1;
}

bool Mapping::canEliminateAlien(Coordinate coordinate)
{
    return this->map[coordinate.getX()][coordinate.getY()] == 3;
}

void Mapping::clearUnity(Coordinate coordinate)
{
    this->map[coordinate.getX()][coordinate.getY()] = 0;
}
