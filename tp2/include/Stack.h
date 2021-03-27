#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack {
    public:
        Stack();
        ~Stack();
        void add(T value);
        T remove();
        bool empty();
        void clear();
    private:
        int size;
        Node<T>* top;
};

#endif

template <typename T>
Stack<T>::Stack()
{
    this->top = nullptr;
    this->size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    this->clear();
}

template <typename T>
void Stack<T>::clear()
{
    while (!this->empty()) {
        this->remove();
    }
}

template <typename T>
void Stack<T>::add(T value)
{
    Node<T>* node = new Node<T>(value);
    node->setNext(this->top);
    this->top = node;
    this->size += 1;
}

template <typename T>
T Stack<T>::remove()
{
    Node<T>* node;
    T value;
    if (this->size <= 0) {
        throw "Empty stack";
    }

    value = this->top->getValue();
    node = this->top;
    this->top = node->getNext();
    delete node;
    this->size -= 1;

    return value;
}

template <typename T>
bool Stack<T>::empty()
{
    return this->size == 0;
}
