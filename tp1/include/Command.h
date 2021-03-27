#ifndef COMMAND_H
#define COMMAND_H

#include "Coordinate.h"
#include <string>

class Command {
    public:
        Command();
        Command(std::string order, int x, int y);
        void setOrder(std::string order);
        void setCoordinate(int x, int y);
        std::string getOrder();
        Coordinate getCoordinate();
    private:
        std::string order;
        Coordinate coordinate;
};

#endif