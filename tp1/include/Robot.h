#ifndef ROBOT_H
#define ROBOT_H

#include "Queue.h"
#include "Stack.h"
#include "Command.h"
#include "Mapping.h"

class Robot {
    public:
        Robot();
        Robot(int id);
        void queueCommand(Command command);
        void stackCommand(Command command);
        void executeCommands(Mapping mapping);
        void executeCommand(Command command, Mapping mapping);
        void printHistory();
        void returnToBase();
        void activate();
        bool isActive();
        int getCollectedResources();
        int getEliminatedAliens();
    private:
        std::string move(Coordinate coordinate, Mapping mapping);
        std::string collectResource(Mapping mapping);
        std::string eliminateAlien(Mapping mapping);
        Queue<std::string> history;
        Queue<Command> commands;
        Stack<Command> priorityCommands;
        int id;
        int collectedResources;
        int eliminatedAliens;
        Coordinate currentPosition;
        bool active;
};

#endif