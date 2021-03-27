#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        Node();
        Node(T value);

        void setValue(T value);
        T getValue();

        void setNext(Node<T>* next);
        Node<T>* getNext();

    private:
        Node<T>* next;
        T value;
};

#endif

template <class T>
Node<T>::Node()
{
    this->next = nullptr;
}

template <class T>
Node<T>::Node(T value)
{
    this->value = value;
    this->next = nullptr;
}

template <class T>
void Node<T>::setValue(T value)
{
    this->value = value;
}

template <class T>
T Node<T>::getValue()
{
    return this->value;
}

template <class T>
void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return this->next;
}
