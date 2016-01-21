/*
Minimal Tree: Given a sorted (increasing order ) array with unique integer elements, 
write an algorithm to create a binary search tree with minimal height.
*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>

class Node
{
public:
    Node(){};
    int* getValue(){return value;};
    void setValue(int* newVal){value = newVal;};
    Node* getLeft(){return leftChild;};
    Node* getRight(){return rightChild;};
    void setLeft(Node* newNode) { leftChild = newNode;};
    void setRight(Node* newNode) { rightChild = newNode;};
private:
    int* value;
    Node* leftChild;
    Node* rightChild;
};




int getCenter(int start, int end)
{
    int span = end - start;
    int mid = span / 2;

    return start + mid;
}

Node* buildTree(std::array<int, 1000> & valueArray, int start, int end)
{
    int centerIndex = getCenter(start, end);

    Node* thisNode = new Node();
    thisNode->setValue(&valueArray[centerIndex]);

    if(end == start)
    {
        return thisNode;
    }
    else if(end <= start)
    {
        return nullptr;
    }
    else{
        thisNode->setLeft(buildTree(valueArray, start, centerIndex - 1));
        thisNode->setRight(buildTree(valueArray, centerIndex + 1, end));
        return thisNode;
    }
    
}

void printTree(Node* node)
{
    if(node == nullptr)
    {
        return;
    }
    printTree(node->getLeft());
    std::cout << *node->getValue() << " ";
    printTree(node->getRight());
}

void printPathTo(Node* node, int* val)
{
    std::cout << *node->getValue() << " ";
    if(val == node->getValue())
    {
        return;
    }
    else if(*val < *node->getValue())
    {
        printPathTo(node->getLeft(), val);
    }
    else if(*val > *node->getValue())
    {
        printPathTo(node->getRight(), val);
    }
}

int main(){

    std::array<int, 1000> valueArray;
    
    for(int i = 0; i< valueArray.size(); i++)
    {
        valueArray[i] = i;
    }

    Node* rootNode = buildTree(valueArray, 0, 999);


    // printTree(rootNode);
    // std::cout << std::endl << std::endl;
    printPathTo(rootNode, &valueArray[3]);
    std::cout << std::endl;



}

