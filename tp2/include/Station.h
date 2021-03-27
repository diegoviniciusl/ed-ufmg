#ifndef STATION_H
#define STATION_H

#include <iostream>

class Station {
    public:
        Station(std::string name, int distance);
        int getDistance();
        std::string getName();
    private:
        std::string name;
        int distance;
};

#endif