#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {
    public:
        Coordinate();
        Coordinate(int x, int y);
        std::string getFormatedCoordinate();
        int getX();
        int getY();
    private:
        int x;
        int y;
};

#endif