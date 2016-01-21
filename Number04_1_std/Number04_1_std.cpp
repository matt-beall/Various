/*
Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a 
route between two nodes
*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>


int main(){

    std::array<std::vector<int>,4> indexChildren;

    indexChildren[0].push_back(1);
    indexChildren[1].push_back(2);
    indexChildren[2].push_back(3);
    indexChildren[2].push_back(0);
    indexChildren[3].push_back(2);

    std::queue<int> myQueue;
    int goal = 0;
    int start = 3;
    myQueue.push(start);

    bool found = false;

    while(!found && !myQueue.empty())
    {
        int thisInd = myQueue.front();
        myQueue.pop();
        if(thisInd == goal)
        {
            found = true;
            break;
        }
        else
        {
            for(int i = 0; i < indexChildren[thisInd].size() ; i++)
            {
                myQueue.push(indexChildren[thisInd][i]);
            }
        }
    }

    std::cout << "Found: " << found << std::endl;




    std::array<std::array<bool,4>,4> adjacencyMatrix{};

    adjacencyMatrix[0][1] = true;
    adjacencyMatrix[1][2] = true;
    adjacencyMatrix[2][0] = true;
    adjacencyMatrix[2][3] = true;
    adjacencyMatrix[3][2] = true;

    std::queue<int> myQueue2;

    myQueue2.push(start);
    found = false;
    while(!found && !myQueue2.empty())
    {
        int thisIndex = myQueue2.front();
        myQueue2.pop();

        if(thisIndex == goal)
        {
            found = true;
            break;
        }
        else
        {
            for(int i = 0; i < adjacencyMatrix.size() ; i++)
            {
                if(adjacencyMatrix[thisIndex][i])
                {
                    myQueue2.push(i);
                }
            }
        }
    }

    std::cout << "Approach 2: " << std::endl;
    std::cout << "Found: " << found << std::endl;






}

