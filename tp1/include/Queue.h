#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
    public:
        Queue();
        ~Queue();
        void add(T value);
        T remove();
        bool empty();
        void clear();
    private:
        int size;
        Node<T>* first;
        Node<T>* last;
};

#endif

template <typename T>
Queue<T>::Queue()
{
    this->first = new Node<T>();
    this->last = first;
    this->size = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    this->clear();
    delete this->first;
}

template <typename T>
void Queue<T>::clear()
{
    while (!this->empty()) {
        this->remove();
    }
}

template <typename T>
void Queue<T>::add(T value)
{
    Node<T>* node = new Node<T>(value);
    this->last->setNext(node);
    this->last = node;
    this->size += 1;
}

template <typename T>
T Queue<T>::remove()
{
    Node<T>* node;
    T value;
    if (this->size <= 0) {
        throw "Empty queue";
    }

    value = this->first->getNext()->getValue();
    node = this->first;
    this->first = node->getNext();
    delete node;
    this->size -= 1;

    return value;
}

template <typename T>
bool Queue<T>::empty()
{
    return this->size == 0;
}
