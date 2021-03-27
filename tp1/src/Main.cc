#include <iostream>
#include <fstream>
#include "Station.h"

/*
    Mapped attributes:

    0 => . (Empty)
    1 => R (Resource)
    2 => O (Obstacle)
    3 => H (Alien)
    4 => B (Station)
*/

char mappedAttributes[] = {
    '.',
    'R',
    'O',
    'H',
    'B'
};

std::fstream getFile(std::string name)
{
    std::fstream file("../inputs/" + name);
    return file;
}

int getMappedAttribute(char value)
{
    for (int i = 0; i < 5; i++) {
        if (value == mappedAttributes[i]) {
            return i;
        }
    }
    return -1;
}

Mapping createMapping(std::fstream &file)
{
    std::string buffer;
    getline(file, buffer);
    int rows = stoi(buffer.substr(0, buffer.find(" ")));
    int columns = stoi(buffer.substr(buffer.find(" ") + 1, buffer.size()));
    int** map;

    map = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        map[i] = new int[columns];
    }

    for (int i = 0; i < rows; ++i) {
        getline(file, buffer);
        for (int j = 0; j < columns; ++j) {
            map[i][j] = getMappedAttribute(buffer[j * 2]);
        }
    }

    return Mapping(map, rows, columns);
}

int getX(std::string value)
{
    value = value.substr(value.find("(") + 1, value.find(","));
    if (value.size() > 0) {
        return stoi(value);
    }
    return 0;
}

int getY(std::string value)
{
    value = value.substr(value.find(",") + 1, value.find(")"));
    if (value.size() > 0) {
        return stoi(value);
    }
    return 0;
}

bool isPriority(std::string &order)
{
    if (order[0] == '*') {
        order = order.substr(1, order.size());
        return true;
    }
    return false;
}

void sendCommands(Station &station, std::fstream &file)
{
    int robot;
    Command command;
    std::string order;
    std::string aux;
    int x;
    int y;
    bool priority;
    std::string buffer;
    while (getline(file, buffer)) {
        order = buffer.substr(0, buffer.find(" "));

        aux = buffer.substr(buffer.find(" ") + 1, buffer.size());
        robot = stoi(aux.substr(0, aux.find(" ")));

        x = getX(aux);
        y = getY(aux);

        priority = isPriority(order);
        command = Command(order, x, y);

        station.command(robot, command, priority);
    }
}

int main(int argc, char* const argv[])
{
    std::fstream mappingFile = getFile(std::string(argv[1]));
    Mapping mapping = createMapping(mappingFile);
    Station station(mapping.getMap());

    std::fstream commandsFile = getFile(std::string(argv[2]));
    sendCommands(station, commandsFile);
    station.printStats();
    return 0;
}
