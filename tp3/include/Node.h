#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        Node();
        Node(T value);

        void setValue(T value);
        T getValue();
        Node<T>* right;
        Node<T>* left;

    private:
        T value;
};

#endif

template <class T>
Node<T>::Node()
{
    this->right = nullptr;
    this->left = nullptr;
}

template <class T>
Node<T>::Node(T value)
{
    this->value = value;
    this->right = nullptr;
    this->left = nullptr;
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
