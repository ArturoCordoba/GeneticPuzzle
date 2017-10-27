//
// Created by fabian on 21/10/17.
//

#ifndef GENETICPUZZLE_LIST_H
#define GENETICPUZZLE_LIST_H

#include <iostream>
#include <curses.h>

#include "Node.h"
#include "MatrixNode.h"

using namespace std;

template <class T>
class List
{
public:
    List();
    ~List();


    void addData(T);
    void delAll();
    void delData(T);
    void print();

    int getSize();
    T getDataPos(int);
    Node<T>* getHead();

private:
    Node<T> *head;
    int numNodes;
};

///Default constructor
template <typename T>
List<T>::List()
{
    numNodes = 0;
    head = NULL;
}

///Add a node data at the end of the list
template <typename T>
void List<T>::addData(T data_)
{
    Node<T> *newNode = new Node<T>(data_);
    Node<T> *temp = head;

    if (!head) {
        head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    numNodes++;
}

///Deletes all the nodes
template <typename T>
void List<T>::delAll()
{
    head->delAll();
    head = 0;
}

///Delete a node of the list by data
template <typename T>
void List<T>::delData(T data_)
{
    Node<T> *temp = head;
    Node<T> *temp1 = head->next;

    if(head->data == data_)
    {
        head = temp->next;
    } else {
        while(temp1)
        {
            if(temp1->data == data_)
            {
                Node<T> *aux = temp1;
                temp->next = temp1->next;
                delete aux;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
    numNodes--;
}

///Gets the size of the list
template <typename T>
int List<T>::getSize()
{
    return numNodes;
}

///Get the data of the node by position
template <typename T>
T List<T>::getDataPos(int index)
{
    Node<T> *temp = head;
    int count = 0;

    while(temp != NULL)
    {
        if(count == index)
            return temp->data;
        count++;
        temp = temp->next;
    }
}

///Gets the head of the list
template <typename T>
Node<T>* List<T>::getHead() {
    return List::head;
}

///Prints the list node by node
template <typename T>
void List<T>::print()
{
    Node<T> *temp = head;
    if(!head){
        cout << "La lista esta vacia" << endl;
    } else {
        while(temp != NULL){
            temp->print();
            temp = temp->next;
        }
    }
}



///Deconstructor
template <typename T>
List<T>::~List() {}

#endif //GENETICPUZZLE_LIST_H
