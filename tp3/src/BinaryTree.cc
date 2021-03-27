#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    this->root = nullptr;
    this->currentItem = this->root;
}

BinaryTree::~BinaryTree()
{
    this->destroy(this->root);
}

void BinaryTree::insert(char value)
{
    this->insert(value, this->root);
}

void BinaryTree::insert(char value, Node<char>* &item)
{
    if (item == nullptr) {
        item = new Node<char>();
        item->setValue(value);
        return;
    }
    if (value > item->getValue()) {
        this->insert(value, item->right);
    } else {
        this->insert(value, item->left);
    }
}

void BinaryTree::destroy(Node<char>* item)
{
    destroy(item->right);
    destroy(item->left);
    delete item;
}

BinaryTree* BinaryTree::goToRoot()
{
    this->currentItem = this->root;
    return this;
}

BinaryTree* BinaryTree::left()
{
    this->currentItem = this->currentItem->left;
    return this;
}

BinaryTree* BinaryTree::right()
{
    this->currentItem = this->currentItem->right;
    return this;
}

char BinaryTree::getCurrentValue()
{
    return this->currentItem->getValue();
}
