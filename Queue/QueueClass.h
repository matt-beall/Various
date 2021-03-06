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

private:

    QueueNode<T>* front;
    QueueNode<T>* rear;
};


template <typename T>
Queue<T>::Queue(): front{nullptr}, 
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
    }
    else if(containsOne())
    {
        front->next = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = rear->next;
    }
}

template <typename T>
T* Queue<T>::dequeue()
{
    if(!isEmpty())
    {
        T* val = front->value;   
        front = front->next;
        return val;
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (front == nullptr);
}

template <typename T>
bool Queue<T>::containsOne()
{
    return (!isEmpty() && rear == nullptr);
}

#endif