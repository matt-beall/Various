#include "Edge.h"



Edge::Edge(Vertex* vPrev, Vertex* vNext)
{
    previousVert = vPrev;
    nextVert = vNext;
}

int Edge::getPreviousIndex()
{
    return previousVert->index;
}

int Edge::getNextIndex()
{
    return nextVert->index;
}

Vertex* Edge::getNextVert()
{
    return nextVert;
}