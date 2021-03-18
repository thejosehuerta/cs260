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
        /* This set contains all (unique) city names.
        The purpose of this set is to refer to it when
        creating new cities in order to not have duplicates*/
        set<string> city_names;
        /*Maps automatically contain pairs and since by definition,
        our cities are pairs, they will be stored in this map.
        This will be useful when trying to get a city's ID which will
        also be their index */
        map<string, int> cities;

        unsigned int V; //number of vertices
        int current_id; //When a new node is created, its ID is auto incremented. This is its initialization
        adj_list *list; //adjacency list containing head nodes
    public:
        Graph(int V);
        bool CityDNE(string name);
        void AddNode(string name);
        void AddEdge(string start, string end, int dist);
        void PrintGraph();
        void PrintCities();


};