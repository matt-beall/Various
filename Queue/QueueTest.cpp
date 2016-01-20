
#include <iostream>
#include "QueueClass.h"

int main()
{

    Queue myQueue;
    std::cout << "A"<< std::endl;
    myQueue.enqueue(5.5);
    std::cout << "B"<< std::endl;
    myQueue.enqueue(2.3);
    std::cout << "C"<< std::endl;

    std::cout << "Queue: " << myQueue.dequeue() << " " << myQueue.dequeue() << std::endl;


}