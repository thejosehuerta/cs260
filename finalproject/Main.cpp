#include <iostream>
#include <stdio.h>
#include "Graph.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argv, char **argc) {

    int V = 5;
    Graph *graph = new Graph(V);
    
    graph->AddEdge(0,2);
    graph->AddEdge(0,3);
    graph->AddEdge(0,4);
    graph->AddEdge(1,0);
    graph->AddEdge(1,4);
    graph->AddEdge(2,0);
    graph->AddEdge(2,3);
    graph->AddEdge(3,2);
    graph->AddEdge(3,0);
    graph->AddEdge(3,4);
    graph->AddEdge(4,3);
    graph->AddEdge(4,2);

    
  

    graph->PrintGraph();
    


    return 0;
}