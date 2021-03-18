#include <string>
#include <set>
#include <map>
#include "Node.h"

using std::string;
using std::set;
using std::pair;
using std::map;

class Graph {
    private:
        set<string> city_names;
        map<string, int> cities;

        unsigned int V; //number of vertices
        int current_id;
        adj_list *list; //adjacency list containing head nodes
    public:
        Graph(int V);
        bool CityDNE(string name);
        void AddNode(string name);
        void AddEdge(string start, string end, int dist);
        void PrintGraph();
        void PrintTest();


};