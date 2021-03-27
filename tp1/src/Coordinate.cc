#include "Coordinate.h"

Coordinate::Coordinate()
{
}

Coordinate::Coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Coordinate::getX()
{
    return this->x;
}

int Coordinate::getY()
{
    return this->y;
}

std::string Coordinate::getFormatedCoordinate()
{
    return "(" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")";
}