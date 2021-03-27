#include "Robot.h"

Robot::Robot()
{
    this->id = -1;
    this->collectedResources = 0;
    this->eliminatedAliens = 0;
    this->active = false;
}

Robot::Robot(int id)
{
    this->id = id;
    this->collectedResources = 0;
    this->eliminatedAliens = 0;
    this->active = false;
}

void Robot::queueCommand(Command command)
{
    this->commands.add(command);
}

void Robot::stackCommand(Command command)
{
    this->priorityCommands.add(command);
}

int Robot::getCollectedResources()
{
    return this->collectedResources;
}

int Robot::getEliminatedAliens()
{
    return this->eliminatedAliens;
}

std::string Robot::move(Coordinate coordinate, Mapping mapping)
{
    std::string response;
    if (mapping.canMove(coordinate)) {
        response = "MOVEU PARA ";
        this->currentPosition = coordinate;
    } else {
        response = "IMPOSSIVEL MOVER PARA ";
    }
    return response + coordinate.getFormatedCoordinate();
}

std::string Robot::collectResource(Mapping mapping)
{
    std::string response;
    if (mapping.canCollectResource(this->currentPosition)) {
        response = "RECURSOS COLETADOS EM ";
        mapping.clearUnity(this->currentPosition);
        this->collectedResources++;
    } else {
        response = "IMPOSSIVEL COLETAR RECURSOS EM ";
    }
    return response + this->currentPosition.getFormatedCoordinate();
}

std::string Robot::eliminateAlien(Mapping mapping)
{
    std::string response;
    if (mapping.canEliminateAlien(this->currentPosition)) {
        response = "ALIEN ELIMINADO EM ";
        mapping.clearUnity(this->currentPosition);
        this->eliminatedAliens++;
    } else {
        response = "IMPOSSIVEL ELIMINAR ALIEN EM ";
    }
    return response + this->currentPosition.getFormatedCoordinate();
}

void Robot::activate()
{
    this->currentPosition = Coordinate(0, 0);
    this->active = true;
}

bool Robot::isActive()
{
    return this->active;
}

void Robot::executeCommands(Mapping mapping)
{
    Command command;
    std::string response;
    while (!this->priorityCommands.empty()) {
        command = this->priorityCommands.remove();
        this->executeCommand(command, mapping);
    }
    while (!this->commands.empty()) {
        command = this->commands.remove();
        this->executeCommand(command, mapping);
    }
}

void Robot::executeCommand(Command command, Mapping mapping)
{
    std::string response;
    if (command.getOrder() == "MOVER") response = this->move(command.getCoordinate(), mapping);
    else if (command.getOrder() == "COLETAR") response = this->collectResource(mapping);
    else if (command.getOrder() == "ELIMINAR") response = this->eliminateAlien(mapping);
    this->history.add("ROBO " + std::to_string(this->id) + ": " + response);
}

void Robot::printHistory()
{
    while (!this->history.empty()) {
        std::cout << this->history.remove() << std::endl;
    }
}

void Robot::returnToBase()
{
    this->currentPosition = Coordinate(0, 0);
    this->active = false;
    this->history.clear();
    this->collectedResources = 0;
    this->eliminatedAliens = 0;
}
