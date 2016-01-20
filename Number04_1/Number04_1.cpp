

/*
Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a 
route between two nodes
*/

#include <iostream>
#include <vector>


class Vertex;

//--------------------------------
class Edge
{
public:
    Edge(Vertex* vPrev, Vertex* vNext);

    int getPreviousIndex();

    Vertex* previousVert;
    Vertex* nextVert;
};



//---------------------------------
class Vertex
{
public:
    Vertex(int index, int val);

    void addEdge(Edge e);

    void printChildren();

    int index;
    int val;

private:
    std::vector<Edge> edges;
};

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
        std::cout << edges[i].nextVert->index << " , ";
    }
    std::cout << std::endl;
}

Edge::Edge(Vertex* vPrev, Vertex* vNext)
{
    previousVert = vPrev;
    nextVert = vNext;
}

int Edge::getPreviousIndex()
{
    return previousVert->index;
}

//--------------------------------
class MattGraph
{
public:
    MattGraph();

    void addVertex(Vertex v);

    void addEdge(int index1, int index2);

    void printGraph();

private:
    Vertex* findVertex(int index);

    std::vector<Vertex> vertices;
};

MattGraph::MattGraph()
{
    vertices.clear();
}

void MattGraph::addVertex(Vertex v)
{
    //TODO doesn't check if index already exists
    vertices.push_back(v);
}

Vertex* MattGraph::findVertex(int desiredIndex)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].index == desiredIndex)
        {
            return &vertices[i];
        }
    }
}

void MattGraph::addEdge(int index1, int index2)
{
    // Vertex* v1 = findVertex(index1);
    // Vertex* v2 = findVertex(index2);

    Edge newEdge(findVertex(index1), findVertex(index2));

    for(auto vert : vertices)
    {
        if(vert.index == newEdge.getPreviousIndex())
        {
            //found desired owner of edge
            vert.addEdge(newEdge);
        }
    }
}

void MattGraph::printGraph()
{
    for(auto vert:vertices)
    {
        std::cout << "NEW VERT" << std::endl;
        vert.printChildren();
    }
}

int main(){

    MattGraph theGraph = MattGraph();
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
    
}

