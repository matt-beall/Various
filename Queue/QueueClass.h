
class Queue
{
public:
    Queue();
    void enqueue(double val);
    double dequeue();
    bool isEmpty();

private:
    class QueueNode
    {
    public:
        QueueNode(int val) {value = val; };

        int value;

        QueueNode* next;
    };

    QueueNode* front;
    QueueNode* rear;
};


Queue::Queue(){};

void Queue::enqueue(double val)
{
    QueueNode newNode(val);

    if(isEmpty())
    {
        std::cout << "here" << std::endl;
        front = &newNode;
        std::cout << "here2" << std::endl;
        
        rear  = &newNode;
    }
    else
    {
        rear->next = &newNode;
        rear = rear->next;
    }
}

double Queue::dequeue()
{
    double val = -1;

    if(!isEmpty())
    {
        val = front->value;
    
        front = front->next;
    }

    return val;
}

bool Queue::isEmpty()
{
    std::cout << "??" << std::endl;
    return (front->next == nullptr);
}