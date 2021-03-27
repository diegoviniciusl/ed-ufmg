#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "Node.h"

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(char value);
        void insert(char value, Node<char>* &item);
        void destroy(Node<char>* item);
        BinaryTree* goToRoot();
        BinaryTree* left();
        BinaryTree* right();
        char getCurrentValue();
    private:
        Node<char>* currentItem;
        Node<char>* root;
};

#endif