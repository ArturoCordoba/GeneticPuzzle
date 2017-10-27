//
// Created by fabian on 23/10/17.
//

#ifndef GENETICPUZZLE_MATRIXNODE_H
#define GENETICPUZZLE_MATRIXNODE_H

#include <iostream>

using namespace std;

template <class T>
class MatrixNode
{
public:
    MatrixNode();
    MatrixNode(T);
    ~MatrixNode();

    T getData();
    void setData(T);
    int getH();
    void setH(int);
    MatrixNode<T>* getRight();
    void setRight(MatrixNode<T>*);
    MatrixNode<T>* getLeft();
    void setLeft(MatrixNode<T>*);
    MatrixNode<T>* getUp();
    void setUp(MatrixNode<T>*);
    MatrixNode<T>* getDown();
    void setDown(MatrixNode<T>*);

    void print();

private:
    T data;
    int H;
    MatrixNode<T>* right = nullptr;
    MatrixNode<T>* left = nullptr;
    MatrixNode<T>* up = nullptr;
    MatrixNode<T>* down = nullptr;
};

///Default constructor
template <typename T>
MatrixNode<T>::MatrixNode() {}

///Constructor per parameter
template <typename T>
MatrixNode<T>::MatrixNode(T data_)
{
    data = data_;
}

///Gets the data of the node
template <typename T>
T MatrixNode<T>::getData()
{
    return MatrixNode::data;
}

///Sets the data of the node
template <typename T>
void MatrixNode<T>::setData(T data_)
{
    MatrixNode::data = data_;
}

///Gets the H of the node
template <typename T>
int MatrixNode<T>::getH()
{
    return MatrixNode::H;
}

///Sets the H of the node
template <typename T>
void MatrixNode<T>::setH(int h)
{
    MatrixNode::H = h;
}

///Gets the right node in matrix
template <typename T>
MatrixNode<T>* MatrixNode<T>::getRight()
{
    return MatrixNode::right;
}

///Sets the right node in matrix
template <typename T>
void MatrixNode<T>::setRight(MatrixNode<T>* node)
{
    MatrixNode::right = node;
}

///Gets the left node in matrix
template <typename T>
MatrixNode<T>* MatrixNode<T>::getLeft()
{
    return MatrixNode::left;
}

///Sets the left node in matrix
template <typename T>
void MatrixNode<T>::setLeft(MatrixNode<T>* node)
{
    MatrixNode::left = node;
}

///Gets the node above in matrix
template <typename T>
MatrixNode<T>* MatrixNode<T>::getUp()
{
    return MatrixNode::up;
}

///Sets the node above in matrix
template <typename T>
void MatrixNode<T>::setUp(MatrixNode<T>* node)
{
    MatrixNode::up = node;
}

///Gets the node below in matrix
template <typename T>
MatrixNode<T>* MatrixNode<T>::getDown()
{
    return MatrixNode::down;
}

///Sets the node below in matrix
template <typename T>
void MatrixNode<T>::setDown(MatrixNode<T>* node)
{
    MatrixNode::down = node;
}

///Prints the data of the node
template <typename T>
void MatrixNode<T>::print()
{
    cout << data << " ";
}

///Deconstructor
template <typename T>
MatrixNode<T>::~MatrixNode() {}

#endif //GENETICPUZZLE_MATRIXNODE_H
