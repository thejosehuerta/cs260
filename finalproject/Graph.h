#include <string>
#include <vector>
#include "Node.h"

using std::string;

class Graph {
    private:
        int V;
        //N is the number of nodes (vertices) in the graph
        //static const int N = 5;
        //Node *adj_list[];
        adj_list *list;
    public:
        Graph(int V);
        Node *NewNode(int data);
        void AddEdge(int src, int dest);
        void PrintGraph();


};