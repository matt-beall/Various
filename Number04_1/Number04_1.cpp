/*
Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a 
route between two nodes
*/

#include <iostream>
#include <vector>
#include "VertexGraph.h"
#include "Queue.h"







int main(){

    // VertexGraph theGraph = VertexGraph();
    // Vertex v = Vertex(0,0);
    // theGraph.addVertex(v);
    // v = Vertex(1,1);
    // theGraph.addVertex(v);
    // v = Vertex(2,2);
    // theGraph.addVertex(v);
    // v = Vertex(3,3);
    // theGraph.addVertex(v);

    
    // theGraph.addEdge(0,1);
    // theGraph.addEdge(1,2);
    // theGraph.addEdge(2,0);
    // theGraph.addEdge(2,3);
    // theGraph.addEdge(3,2);

    // theGraph.printGraph();


    // theGraph.pathBFS(3,0);

    std::cout << "A" <<std::endl;
    Queue<double> myQueue;
    std::cout << "B" <<std::endl;

    double num1 = 5.5;
    double num2 = 2;

    myQueue.enqueue(&num1);
    std::cout << "C" <<std::endl;
    myQueue.enqueue(&num2);
    std::cout << "D" <<std::endl;

    std::cout << myQueue.dequeue() << " " << myQueue.dequeue() << std::endl;



    
}

