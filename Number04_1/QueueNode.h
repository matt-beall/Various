#ifndef QUEUENODE_H
#define QUEUENODE_H

template<typename T>
class QueueNode
{
public:
    QueueNode(T* val);
    void setPath(std::vector<T*> pathToHere);
    std::vector<T*> getPath();

    T* value;

    QueueNode<T>* next;
private:
    std::vector<T*> path;
};



template<typename T>
QueueNode<T>::QueueNode(T* val)
{
    value = val;
}


template<typename T>
void QueueNode<T>::setPath(std::vector<T*> pathToHere)
{
    path = pathToHere;
    path.push_back(value);
}

template<typename T>
std::vector<T*> QueueNode<T>::getPath()
{
    return path;
}

#endif