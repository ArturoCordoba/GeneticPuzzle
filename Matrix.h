//
// Created by fabian on 21/10/17.
//

#ifndef GENETICPUZZLE_MATRIX_H_H
#define GENETICPUZZLE_MATRIX_H_H

#include <iostream>
#include <curses.h>

#include "MatrixNode.h"

using namespace std;

template <class T>
class Matrix
{
public:
    Matrix(int, int);
    ~Matrix();

    MatrixNode<T>* getFirst();
    int getRows();
    int getCols();

    void setRows(int);
    void setCols(int);

    MatrixNode<T>* getNodePos(int, int);
    MatrixNode<T>* getNodeData(Matrix<T>*,T);
    void setNode(int, int, T);

    void printMatrix();

private:
    MatrixNode<T> *first;

    int cols;
    int rows;
};

///Constructor per paramater
template <typename T>
Matrix<T>::Matrix(int rows_, int cols_)
{
    Matrix::rows = rows_;
    Matrix::cols = cols_;

    MatrixNode<T> *previousRow = nullptr;

    for(int i = 0; i < rows; ++i)
    {
        MatrixNode<T>* columnNode = new MatrixNode<T>();
        MatrixNode<T>* current = columnNode;

        if(previousRow != nullptr)
        {
            columnNode->setUp(previousRow);
            previousRow->setDown(columnNode);
            previousRow = previousRow->getRight();
        }

        if(i == 0)
            Matrix::first = columnNode;

        for(int j = 1; j < cols_; ++j)
        {
            MatrixNode<T> * rowNode = new MatrixNode<T>();
            rowNode->setLeft(current);
            current->setRight(rowNode);

            if(previousRow != nullptr){
                rowNode->setUp(previousRow);
                previousRow->setDown(rowNode);
                previousRow = previousRow->getRight();
            }
            current = rowNode;
        }
        previousRow = columnNode;
    }
}

///Gets the first node of the matrix
template <typename T>
MatrixNode<T>* Matrix<T>::getFirst()
{
    return Matrix::first;
}

///Gets the number of rows of the matrix
template <typename T>
int Matrix<T>::getRows()
{
    return Matrix::rows;
}

///Gets the number of columns of the matrix
template <typename T>
int Matrix<T>::getCols()
{
    return Matrix::cols;
}

///Sets the number of rows of a matrix
template <typename T>
void Matrix<T>::setRows(int rows_)
{
    Matrix::rows = rows_;
}

///Sets the number of rows of a matrix
template <typename T>
void Matrix<T>::setCols(int cols_)
{
    Matrix::cols = cols_;
}

///Gets a node of the matrix by position
template <typename T>
MatrixNode<T>* Matrix<T>::getNodePos(int row, int column)
{
    if(row < rows && column < cols){
        MatrixNode<T>* node = first;

        for (int i = 0; i < row; ++i) {
            node = node->getDown();
        }
        for (int j = 0; j < column; ++j) {
            node = node->getRight();
        }

        return node;
    } else {
        return nullptr;
    }
}


///Gets a node of the matrix by data
template <typename T>
MatrixNode<T>* Matrix<T>::getNodeData(Matrix<T>* matrix, T data_)
{
    for(int i = 0; i < matrix->getRows(); i++)
    {
        for(int j = 0; j < matrix->getCols(); j++)
        {
            MatrixNode<int>* node = matrix->getNodePos(i,j);
            if(node->getData() == data_)
                return node;
        }
    }
}

///Sets a node in the matrix
template <typename T>
void Matrix<T>::setNode(int row, int column, T data_)
{
    if(column < cols && row < rows){
        MatrixNode<T> *node = first;

        for (int i = 0; i < row; ++i) {
            node = node->getDown();
        }

        for (int j = 0; j < column; ++j) {
            node = node->getRight();
        }

        node->setData(data_);
    }
}

///Print the matrix
template <typename T>
void Matrix<T>::printMatrix()
{
    MatrixNode<T>* currentColumn = first;

    for(int i = 0; i < rows; i++) {
        currentColumn->print();
        MatrixNode<T>* currentRow = currentColumn->getRight();

        for(int j = 0; j < cols - 1; ++j) {
            currentRow->print();
            currentRow = currentRow->getRight();
        }
        cout << endl;
        currentColumn = currentColumn->getDown();
    }
}

///Deconstructor
template<typename T>
Matrix<T>::~Matrix() {}

#endif //GENETICPUZZLE_MATRIX_H_H
