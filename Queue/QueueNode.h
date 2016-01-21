#ifndef QUEUENODE_H
#define QUEUENODE_H

template<typename T>
class QueueNode
{
public:
    QueueNode(T* val);

    T* value;

    QueueNode<T>* next;
};



template<typename T>
QueueNode<T>::QueueNode(T* val)
{
    value = val;
}


#endif