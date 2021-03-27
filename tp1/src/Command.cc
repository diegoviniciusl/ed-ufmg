#include "Command.h"

Command::Command()
{
}

Command::Command(std::string order, int x, int y)
{
    this->order = order;
    this->coordinate = Coordinate(x, y);
}

void Command::setOrder(std::string order)
{
    this->order = order;
}

void Command::setCoordinate(int x, int y)
{
    this->coordinate = Coordinate(x, y);
}

std::string Command::getOrder()
{
    return this->order;
}

Coordinate Command::getCoordinate()
{
    return this->coordinate;
}
