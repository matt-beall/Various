/*
Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a 
route between two nodes
*/

#include <iostream>
#include <vector>
#include "VertexGraph.h"
#include "QueueClass.h"







int main(){

    VertexGraph theGraph = VertexGraph();
    Vertex v = Vertex(0,0);
    theGraph.addVertex(v);
    v = Vertex(1,1);
    theGraph.addVertex(v);
    v = Vertex(2,2);
    theGraph.addVertex(v);
    v = Vertex(3,3);
    theGraph.addVertex(v);

    
    theGraph.addEdge(0,1);
    theGraph.addEdge(1,2);
    theGraph.addEdge(2,0);
    theGraph.addEdge(2,3);
    theGraph.addEdge(3,2);


    theGraph.printGraph();


    std::vector<Vertex*> path =  theGraph.pathBFS(3,0);

    if(path.size() == 0)
    {
        std::cout << "No Path" << std::endl;
    }
    else
    {
        std::cout << "Path Exists: ";
        for(int i = 0; i < path.size(); i++)
        {
            std::cout << path[i]->getIndex() << " -> ";
        }
        std::cout << std::endl;
    }
}

