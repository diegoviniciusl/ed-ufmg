#include <fstream>
#include <string>
#include <ctime>
#include "Encoder.h"

std::ifstream getFile(std::string name)
{
    std::ifstream file(name);
    return file;
}

BinaryTree* createBinaryTree(std::string encodedBinaryTree)
{
    BinaryTree* binaryTree = new BinaryTree();
    for (unsigned int i = 0; i < encodedBinaryTree.size(); i++) {
        binaryTree->insert(encodedBinaryTree[i]);
    }
    return binaryTree;
}

void runCommand(char command, std::string message, Encoder &encoder)
{
    switch (command) {
        case 'A':
            encoder.setBinaryTree(createBinaryTree(message));
            break;
        case 'D':
            std::cout << encoder.decode(message) << std::endl;
            break;
        case 'C':
            std::cout << encoder.encode(message) << std::endl;
            break;
    }
}

int main(int argc, char *argv[])
{
    std::ifstream file = getFile(std::string(argv[1]));
    if (file.good()) {
        srand(time(NULL));
        std::string buffer;
        char command;
        std::string message;
        Encoder encoder;
        while (getline(file, buffer))
        {
            command = buffer.substr(0, 1)[0];
            message = buffer.substr(3, buffer.size());
            runCommand(command, message, encoder);
        }
    }
    file.close();

    return 0;
}