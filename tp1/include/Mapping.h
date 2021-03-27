#ifndef MAPPING_H
#define MAPPING_H

#include "Coordinate.h"

class Mapping {
    public:
        Mapping();
        Mapping(int** map, int rows, int columns);
        ~Mapping();
        void setMap(int** map);
        int** getMap();
        bool canMove(Coordinate coordinate);
        bool canCollectResource(Coordinate coordinate);
        bool canEliminateAlien(Coordinate coordinate);
        void clearUnity(Coordinate coordinate);
    private:
        int** map;
        int rows;
        int columns;
};

#endif