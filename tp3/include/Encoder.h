#ifndef ENCODER_H
#define ENCODER_H

#include "BinaryTree.h"

class Encoder {
    public:
        Encoder();
        void setBinaryTree(BinaryTree* tree);
        std::string decode(std::string message);
        std::string encode(std::string message);
    private:
        BinaryTree* tree;
};

#endif