/*
Validate BST: Implement a function to check if a binary tree is a binary search tree.
*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <utility>
#include <climits>

#define TREE_SIZE 10000


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


int treeHeight(Node* thisNode)
{
    if(thisNode == nullptr)
    {
        return 0;
    }
    else
    {
        return std::max(treeHeight(thisNode->getLeft()), treeHeight(thisNode->getRight() )) + 1;
    }
}

std::pair<bool, int> isBalanced(Node* thisNode)
{
    std::pair<bool, int> result;
    if(thisNode == nullptr)
    {
        result.first = true;
        result.second = 0;
        return result;
    }

    //Since we want true height, we check all connections...if we only want
    // balanced or not, we can short circuit upon seeing a false
    std::pair<bool, int> leftResult = isBalanced(thisNode->getLeft());
    std::pair<bool, int> rightResult = isBalanced(thisNode->getRight());


    int leftHeight = leftResult.second;
    int rightHeight = rightResult.second;

    result.second = std::max(leftHeight, rightHeight) + 1;
    result.first = leftResult.first && rightResult.first && (std::abs(leftHeight - rightHeight) <= 1);

    return result;
}

std::pair<bool, std::array<int, 2>> validateBST(Node* thisNode)
{
    std::pair<bool, std::array<int, 2>> result;
    if(thisNode == nullptr)
    {
        result.first = true;
        result.second = {INT_MAX, INT_MIN};
        return result;
    }


    std::pair<bool, std::array<int,2>> resultLeft = validateBST(thisNode->getLeft());
    std::pair<bool, std::array<int,2>> resultRight = validateBST(thisNode->getRight());
    
    result.first = resultLeft.first && resultRight.first &&
                   resultLeft.second[1] <= *thisNode->getValue() &&
                   resultRight.second[0] > *thisNode->getValue();

    result.second[0] = std::min(std::min(resultLeft.second[0], resultRight.second[0]), *thisNode->getValue());
    result.second[1] = std::max(std::max(resultLeft.second[1], resultRight.second[1]), *thisNode->getValue());

    return result;
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

    bool unbalance = 0;

    int extra1 = 3;
    int extra2 = 11;

    if(unbalance)
    {
        Node* extraN1 = new Node();
        extraN1->setValue(&extra1);
        Node* extraN2 = new Node();
        extraN2->setValue(&extra2);
        extraN1->setRight(extraN2);
        rootNode->getRight()->getRight()->getRight()->setRight(extraN1);

    }

    getLayers(lists, rootNode, 0);

    for(int i = 0; i < lists.size(); i++)
    {
        printLL(lists.at(i));
        std::cout << std::endl;
    }

    std::pair<bool, int> balanceResultPair = isBalanced(rootNode);
    bool balanceResult = balanceResultPair.first;

    std::cout << std::endl << "Balanced? " << balanceResult << " Height: " << balanceResultPair.second << std::endl;

    std::pair<bool, std::array<int,2>> bstResult = validateBST(rootNode);

    std::cout << std::endl << "BST? " << bstResult.first << " Min: " << bstResult.second[0] << " Max: " << bstResult.second[1] << std::endl;
}



