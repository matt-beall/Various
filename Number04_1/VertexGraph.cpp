#include "VertexGraph.h"

VertexGraph::VertexGraph()
{
    vertices.clear();
}

void VertexGraph::addVertex(Vertex v)
{
    //TODO doesn't check if index already exists
    vertices.push_back(v);
}

Vertex* VertexGraph::findVertex(int desiredIndex)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].getIndex() == desiredIndex)
        {
            return &vertices[i];
        }
    }
}

void VertexGraph::addEdge(int index1, int index2)
{
    // Vertex* v1 = findVertex(index1);
    // Vertex* v2 = findVertex(index2);

    Edge newEdge(findVertex(index1), findVertex(index2));

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].getIndex() == newEdge.getPreviousIndex())
        {   
            //found desired owner of edge
            vertices[i].addEdge(newEdge);
        }
    }
}

void VertexGraph::printGraph()
{
    for(int i = 0; i < vertices.size() ; i++)
    {
        std::cout << "NEW VERT" << std::endl;
        vertices[i].printChildren();
        std::cout << "NumChildren: " << vertices[i].numChildren() << std::endl;
    }

    Vertex* vert2 = findVertex(2);
    std::cout << "NumPtr: " <<  vert2->numChildren() << std::endl;
}

std::vector<Vertex*> VertexGraph::pathBFS(int startIndex, int goalIndex)
{
    // std::vector<int> path;
    Queue<Vertex> myQueue;


    std::cout << "A" << std::endl;

    Vertex* startVertex = findVertex(startIndex);
    std::cout << "B" << std::endl;

    myQueue.enqueue(startVertex);
    // Vertex* testVertex = myQueue.dequeue();
    std::cout << "C" << std::endl;

    std::vector<Vertex*> emptyPath;
    bool found = false;
    while(!found && !myQueue.isEmpty())
    {
    std::cout << "D" << std::endl;
        std::vector<Vertex*> frontPath = myQueue.getFrontPath();
        Vertex* thisVert = myQueue.dequeue();
    std::cout << "E" << std::endl;
        if(thisVert == nullptr)
        {
            std::cout << "Something went wrong" << std::endl;
            found = false;
            return emptyPath;
        }
        std::cout << "E2" << std::endl;
        int tempIndex = thisVert->getIndex();
        std::cout << "E3" << std::endl;
        if(thisVert->getIndex() == goalIndex)
        {
    std::cout << "F" << std::endl;
            found = true;
            return frontPath;
        }
        else
        {
    std::cout << "G" << std::endl;
            int numChild = thisVert->numChildren();
            std::cout << "G2, ind: " << thisVert->getIndex() << " num: " << numChild << std::endl;
            for(int i = 0; i < thisVert->numChildren();i++)
            {
    std::cout << "H" << std::endl;
                myQueue.enqueue(thisVert->getChild(i));
            }
        }
    }
    
    // found = false;

    return emptyPath;

    //start at startIndex
    //check if this is goal
        //if goal, then done...return path

    //if not, add all children to queue
    //pop this one from queue
    //iterate
    //if queue empty, path not found

}

