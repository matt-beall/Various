#include "Vertex.h"


Vertex::Vertex(int ind, int v)
{
    index = ind;
    val = v;
}

void Vertex::addEdge(Edge e)
{
    edges.push_back(e);
}

void Vertex::printChildren()
{
    std::cout << "Vertex: " << index << " Value: " << val << std::endl;
    std::cout << "Children: ";
    for(int i = 0; i < edges.size(); i ++)
    {
        std::cout << edges[i].getNextIndex();
        if(i < edges.size() - 1)
            std::cout << " , ";
    }
    std::cout << std::endl;
}


int Vertex::numChildren()
{
    int num = edges.size();
    return num;
}

Vertex* Vertex::getChild(int i)
{
    return edges[i].getNextVert();
}

int Vertex::getIndex()
{
    return index;
}

int Vertex::getValue()
{
    return val;
}