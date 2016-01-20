#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
private:
struct QueueNode
{
    T* thisVal;
    QueueNode* next;

    QueueNode(T* t)
    {
        thisVal = t;
    }
};


public:
    Queue();

    void enqueue(T*);

    T* dequeue();

    T* peek();

    bool isEmpty();

    QueueNode* front;
    QueueNode* back;

private:    

};


template <typename T>
Queue<T>::Queue()
{
}



template <typename T>
void Queue<T>::enqueue(T* newVert)
{
    std::cout << "1"<<std::endl;
    QueueNode newNode =  QueueNode(newVert);
    std::cout << "2"<<std::endl;
    if(isEmpty())
    {
    std::cout << "3"<<std::endl;
        front = &newNode;
        back = &newNode;
    }
    else
    {
    std::cout << "4"<<std::endl;
    std::cout << back->thisVal << std::endl;
        back->next = &newNode;
    std::cout << "5"<<std::endl;
        back = back->next;
    }
}





template <typename T>
T* Queue<T>::dequeue()
{
    std::cout <<"a"<<std::endl;
    if(!isEmpty())
    {
    std::cout <<"b"<<std::endl;
        T* returnVert = front->thisVal;
    std::cout <<"c"<<std::endl;
        front = front->next;   
    std::cout <<"d"<<std::endl;
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
T* Queue<T>::peek()
{
    return front->thisVal;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    if(front == nullptr)
    {
        return true;
    }
    else return false;
}



#endif