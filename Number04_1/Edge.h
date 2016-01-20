#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <vector>
#include "Vertex.h"
class Vertex;

//--------------------------------
class Edge
{
public:
    Edge(Vertex* vPrev, Vertex* vNext);

    int getPreviousIndex();

    int getNextIndex();

    Vertex* getNextVert();

private:
    Vertex* previousVert;
    Vertex* nextVert;
};


#endif