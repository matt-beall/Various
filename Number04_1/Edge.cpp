#include "Edge.h"



Edge::Edge(Vertex* vPrev, Vertex* vNext)
{
    previousVert = vPrev;
    nextVert = vNext;
}

int Edge::getPreviousIndex()
{
    return previousVert->getIndex();
}

int Edge::getNextIndex()
{
    return nextVert->getIndex();
}

Vertex* Edge::getNextVert()
{
    return nextVert;
}