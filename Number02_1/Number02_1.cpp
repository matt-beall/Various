/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <array>
#include <iostream>
#include <unordered_map>

class Node
{
public:
    Node(int val);

    int value;

    Node* next;
};

Node::Node(int val)
{
    value = val;
}

void insertAtEnd(Node* first, int value)
{
    Node* thisNode = first;
    while(thisNode->next != nullptr)
    {
        thisNode = thisNode->next;
    }
    thisNode->next = new Node(value);
}

void printValues(Node* first)
{
    Node* thisNode = first;
    while(thisNode->next != nullptr)
    {
        std::cout << thisNode->value << " ";
        thisNode = thisNode->next;
    }
    std::cout << thisNode->value << std::endl;
}


void removeDups(Node* first)
{
    std::unordered_map<int, bool> found;
    found[first->value] = true;

    Node* thisNode = first->next;
    Node* prevNode = first;

    bool done = false;

    while(!done)
    {
        int thisVal = thisNode->value;
        if(thisNode->next == nullptr)
        {
            done = true;
        }

        if(found[thisVal])
        {
            //Remove thisNode and 
            thisNode = thisNode->next;
            prevNode->next = thisNode;
        }
        else
        {
            found[thisVal] = true;
            prevNode = thisNode;
            thisNode = thisNode->next;
        }
    }
}

int main(){
    std::array<int, 8> values{1,2, 4, 5, 2, 1, 6, 3};

    Node* firstNode = new Node(values[0]);

    for(int i = 1; i < values.size(); i++)
    {
        insertAtEnd(firstNode, values[i]);
    }

    printValues(firstNode);

    removeDups(firstNode);

    printValues(firstNode);

    delete firstNode;
    
}
