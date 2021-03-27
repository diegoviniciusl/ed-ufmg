#include <iostream>
#include "Station.h"

Station::Station(int** map)
{
    this->robots = new Robot*[50];
    for (int i = 0; i < 50; ++i) {
        this->robots[i] = new Robot(i);
    }
    this->mapping.setMap(map);
    this->collectedResources = 0;
    this->eliminatedAliens = 0;
}

void Station::command(int robot, Command command, bool isPriority)
{
    std::string order = command.getOrder();
    if (order == "MOVER" || order == "COLETAR" || order == "ELIMINAR") {
        if (isPriority) {
            this->robots[robot]->stackCommand(command);
        } else {
            this->robots[robot]->queueCommand(command);
        }
        return;
    }

    if (order == "ATIVAR") {
        if (this->robots[robot]->isActive()) {
            this->printResponse(robot, "JA ESTA EM MISSAO");
            return;
        }
        this->robots[robot]->activate();
        this->printResponse(robot, "SAIU EM MISSAO");
        return;
    }

    if (order == "EXECUTAR") {
        if (!this->robots[robot]->isActive()) {
            this->printResponse(robot, "NAO ESTA EM MISSAO");
            return;
        }
        this->robots[robot]->executeCommands(this->mapping);
        return;
    }

    if (order == "RELATORIO") {
        this->robots[robot]->printHistory();
        return;
    }

    if (order == "RETORNAR") {
        int resources;
        int aliens;
        if (!this->robots[robot]->isActive()) {
            this->printResponse(robot, "NAO ESTA EM MISSAO");
            return;
        }
        resources = this->robots[robot]->getCollectedResources();
        aliens = this->robots[robot]->getEliminatedAliens();
        this->collectedResources += resources;
        this->eliminatedAliens += aliens;
        this->robots[robot]->returnToBase();
        this->printResponse(robot, "RETORNOU ALIENS " + std::to_string(aliens) + " RECURSOS " + std::to_string(resources));
        return;
    }
}

void Station::printStats()
{
    std::cout << "BASE: TOTAL DE ALIENS " << this->eliminatedAliens << " RECURSOS " << this->collectedResources << std::endl;
}

void Station::printResponse(int robot, std::string message)
{
    std::cout << "BASE: ROBO " << robot << " " << message << std::endl;
}
