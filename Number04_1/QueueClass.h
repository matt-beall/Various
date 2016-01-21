#ifndef QUEUECLASS_H
#define QUEUECLASS_H

#include <iostream>
#include "QueueNode.h"

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    void enqueue(T* val);
    T* dequeue();
    bool isEmpty();
    bool containsOne();
    std::vector<T*> getFrontPath();

private:

    int numNodes;

    QueueNode<T>* front;
    QueueNode<T>* rear;
};


template <typename T>
Queue<T>::Queue(): numNodes(0),
                   front{nullptr}, 
                   rear{nullptr}
{

}

template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
void Queue<T>::enqueue(T* val)
{
    QueueNode<T>* newNode = new QueueNode<T>(val);


    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
        std::vector<T*> emptyPath;
        rear->setPath(emptyPath);
    }
    else if(containsOne())
    {
        front->next = newNode;
        rear = newNode;
        rear->setPath(front->getPath());
    }
    else
    {
        rear->next = newNode;
        rear->next->setPath(rear->getPath());
        rear = rear->next;
    }
    numNodes++;
}

template <typename T>
T* Queue<T>::dequeue()
{
    if(!isEmpty())
    {
        T* val = front->value;   
        front = front->next;
        numNodes--;
        return val;
    }
    else
    {
        return nullptr;
    }
    return nullptr;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (numNodes == 0);
}

template <typename T>
bool Queue<T>::containsOne()
{
    return (numNodes == 1);
}

template <typename T>
std::vector<T*> Queue<T>::getFrontPath()
{
    return front->getPath();
}

#endif