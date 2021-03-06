#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include "Edge.h"

class Edge;

//---------------------------------
class Vertex
{
public:
    Vertex(int index, int val);

    void addEdge(Edge e);

    void printChildren();

    int numChildren();

    Vertex* getChild(int i);

    int getIndex();

    int getValue();


private:
    std::vector<Edge> edges;
    
    int index;
    int val;
};


#endif