#include "Encoder.h"

Encoder::Encoder()
{
}

void Encoder::setBinaryTree(BinaryTree* tree)
{
    this->tree = tree;
}

std::string Encoder::decode(std::string message)
{
    std::string decodedMessage = "";
    for (unsigned int i = 0; i < message.size(); i++) {
        if (message[i] == 'x') {
            this->tree->goToRoot();
        } else if (message[i] % 2 == 0) {
            this->tree->right();
        } else {
            this->tree->left();
        }
        if (i == (message.size() - 1) || (i < (message.size() - 1) && message[i + 1] == 'x')) {
            decodedMessage += this->tree->getCurrentValue();
        }
    }
    return decodedMessage;
}

std::string Encoder::encode(std::string message)
{
    std::string encodedMessage = "";
    std::string randomNumber = "";
    for (unsigned int i = 0; i < message.size(); i++) {
        this->tree->goToRoot();
        randomNumber = "";
        while (message[i] != this->tree->getCurrentValue()) {
            if (message[i] < this->tree->getCurrentValue()) {
                this->tree->left();
                randomNumber += '0' + (rand() % 5) * 2 + 1;
            } else {
                this->tree->right();
                randomNumber += '0' + (rand() % 5) * 2;
            }
        }
        if (i != (message.size() - 1)) {
            encodedMessage += 'x';
        }
        encodedMessage += randomNumber;
    }
    return encodedMessage;
}
