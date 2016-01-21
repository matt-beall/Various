/*
List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
*/


#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define TREE_SIZE 1000


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

Node* buildTree(std::array<int, TREE_SIZE> & valueArray, int start, int end)
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

class LinkedList
{
public:
    LinkedList():thisNode{nullptr}, next{nullptr}{};
    LinkedList(Node* nd):next{nullptr}{thisNode = nd;};
    Node* thisNode;
    LinkedList* next;
};

void printLL(LinkedList* list)
{
    LinkedList* runner = list;
    while(runner != nullptr)
    {
        std::cout << *runner->thisNode->getValue() << " ";
        runner = runner->next;
    }
}

void getLayers(std::vector<LinkedList*>& lists, Node* thisNode, int layer)
{
    if(thisNode == nullptr)
    {
        return;
    }
    else
    {
        LinkedList* listItem = new LinkedList();
        if(lists.size() == layer)
        {
            listItem->thisNode = thisNode;
            std::cout << "Layer: " << layer << " Item: " << *listItem->thisNode->getValue() << " PUSH" <<std::endl;

            lists.push_back(listItem);
        }
        else
        {
            listItem->thisNode = thisNode;
            std::cout << "Layer: " << layer << " Item: " << *listItem->thisNode->getValue() << std::endl;

            listItem->next = lists[layer];
            lists[layer] = listItem;
        }
        getLayers(lists, thisNode->getRight(), layer + 1);
        getLayers(lists, thisNode->getLeft(), layer + 1);
    }
}

int main(){

    std::array<int, TREE_SIZE> valueArray;
    
    for(int i = 0; i< valueArray.size(); i++)
    {
        valueArray[i] = i;
    }

    Node* rootNode = buildTree(valueArray, 0, TREE_SIZE - 1);


    // printTree(rootNode);
    // std::cout << std::endl << std::endl;
    printPathTo(rootNode, &valueArray[7]);
    std::cout << std::endl;

    std::vector<LinkedList*> lists;

    getLayers(lists, rootNode, 0);

    for(int i = 0; i < lists.size(); i++)
    {
        printLL(lists.at(i));
        std::cout << std::endl;
    }
    
}


