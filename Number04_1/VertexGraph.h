#ifndef VERTEXGRAPH_H
#define VERTEXGRAPH_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "QueueClass.h"


class VertexGraph
{
public:
    VertexGraph();

    void addVertex(Vertex v);

    void addEdge(int index1, int index2);

    void printGraph();

    std::vector<Vertex*> pathBFS(int startIndex, int goalIndex);

private:

    Vertex* findVertex(int index);
    
    //TODO should probably refactor to an array
    std::vector<Vertex> vertices;
};

#endif