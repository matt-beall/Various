
#include <iostream>
#include "QueueClass.h"


int main()
{

    int testNum = 1;
    QueueNode<int> testNode = QueueNode<int>(&testNum);

    std::cout << testNode.value << std::endl;

    QueueNode<int>* testNodePtr = &testNode;

    std::cout << testNodePtr->value << std::endl;

    Queue<int> myQueue;
    std::cout << "A"<< std::endl;
    int num1 = 1;
    myQueue.enqueue(&num1);
    std::cout << "B"<< std::endl;
    int num2 = 2;
    myQueue.enqueue(&num2);
    std::cout << "C"<< std::endl;
    int num3 = 3;
    myQueue.enqueue(&num3);
    std::cout << "C2"<< std::endl;
    int num4 = 4;
    myQueue.enqueue(&num4);
    std::cout << "C3"<< std::endl;

    int* val1 = myQueue.dequeue();
    int* val2 = myQueue.dequeue();
    int* val3 = myQueue.dequeue();
    int* val4 = myQueue.dequeue();
    int* val5 = myQueue.dequeue();

    // std::cout << "Queue: " << *val1 << std::endl;

    std::cout << "Queue: " << ((val1 == nullptr)?-1:*val1) << " " <<
                              ((val2 == nullptr)?-1:*val2) << " " <<
                              ((val3 == nullptr)?-1:*val3) << " " <<
                              ((val4 == nullptr)?-1:*val4) << " " <<
                              ((val5 == nullptr)?-1:*val5) << " " << std::endl;

    // std::cout << "Queue: " << (int) *val1 << " " << (int) *val2 << " " << (int) *val3 << " " << (int) *val4 << " " << (int) *val5 << std::endl;


}