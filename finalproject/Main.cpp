#include <iostream>
#include <stdio.h>
#include "Graph.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argv, char **argc) {

    int V = 5;
    Graph *graph = new Graph(V);
    

    graph->AddNode("LA");
    graph->AddNode("SD");
    graph->AddNode("NH");
    graph->AddNode("NJ");
    graph->AddNode("CA");
    graph->AddNode("FL");

    graph->AddNode("RI");

    graph->PrintTest();
    cout << endl;
    graph->PrintGraph();
    cout << endl;
    graph->AddEdge("LA", "SD", 80);
    graph->AddEdge("LA", "NJ", 45);
    
   


    


    
  

    graph->PrintGraph();
    


    return 0;
}