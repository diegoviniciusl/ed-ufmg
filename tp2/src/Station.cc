#include "Station.h"

Station::Station(std::string name, int distance)
{
    this->name = name;
    this->distance = distance;
}

int Station::getDistance()
{
    return this->distance;
}

std::string Station::getName()
{
    return this->name;
}