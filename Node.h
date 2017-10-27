//
// Created by fabian on 21/10/17.
//

#ifndef GENETICPUZZLE_NODE_H
#define GENETICPUZZLE_NODE_H

#include <iostream>

using namespace std;


template <class T>
class Node
{
public:
    Node();
    Node(T);
    ~Node();

    Node *next;

    T data;

    void delAll();
    void print();
};

///Default constructor
template <typename T>
Node<T>::Node()
{
    data = NULL;
    next = NULL;
}

///Constructor per parameter
template <typename T>
Node<T>::Node(T data_)
{
    data = data_;
    next = NULL;
}

///Deletes all the nodes
template <typename T>
void Node<T>::delAll()
{
    if (next)
        next->delAll();
    delete this;
}

///Prints the data of the node
template <typename T>
void Node<T>::print()
{
    cout << data << endl;
}

///Deconstructor
template <typename T>
Node<T>::~Node() {}

#endif //GENETICPUZZLE_NODE_H
