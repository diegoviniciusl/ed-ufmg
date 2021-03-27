#ifndef STATION_H
#define STATION_H

#include "Robot.h"
#include "Mapping.h"
#include "Command.h"

class Station {
    public:
        Station(int** map);
        void command(int robot, Command command, bool isPriority);
        void printStats();
    private:
        void printResponse(int robot, std::string response);
        Mapping mapping;
        int collectedResources;
        int eliminatedAliens;
        Robot** robots;
};

#endif