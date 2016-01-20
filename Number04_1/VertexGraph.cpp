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
        if(vertices[i].index == desiredIndex)
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
        if(vertices[i].index == newEdge.getPreviousIndex())
        {   
            //found desired owner of edge
            vertices[i].addEdge(newEdge);
        }
    }
}

void VertexGraph::printGraph()
{
    for(auto vert:vertices)
    {
        std::cout << "NEW VERT" << std::endl;
        vert.printChildren();
    }
}

bool VertexGraph::pathBFS(int startIndex, int goalIndex)
{
    // std::vector<int> path;
    // Queue<Vertex> myQueue;


    // std::cout << "A" << std::endl;

    // Vertex* startVertex = findVertex(startIndex);
    // std::cout << "B" << std::endl;

    // myQueue.enqueue(startVertex);
    // Vertex* testVertex = myQueue.dequeue();
    // std::cout << "C" << std::endl;

    // bool found = false;
    // while(!found & !myQueue.isEmpty())
    // {
    // std::cout << "D" << std::endl;
    //     Vertex* thisVert = myQueue.dequeue();
    // std::cout << "E" << std::endl;

    //     if(thisVert->index == startIndex)
    //     {
    // std::cout << "F" << std::endl;
    //         found = true;
    //         break;
    //     }
    //     else
    //     {
    // std::cout << "G" << std::endl;
    //         for(int i = 0; i < thisVert->numChildren();i++)
    //         {
    // std::cout << "H" << std::endl;
    //             myQueue.enqueue(thisVert->getChild(i));
    //         }
    //     }
    // }

    bool found = false;

    return found;

    //start at startIndex
    //check if this is goal
        //if goal, then done...return path

    //if not, add all children to queue
    //pop this one from queue
    //iterate
    //if queue empty, path not found

}

