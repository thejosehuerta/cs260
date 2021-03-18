#include <string>


using std::string;
using std::pair;

//Every node will be composed of a city, a distance, and a pointer node
struct Node {
    /*cities will be a pair (the city's name, and its unique ID that will
    also correspond to its index in the adjecancy table) */
    pair<string, int> city;
    int dist;
    Node *next;
};

//This adjecancy list will be an array of pointer nodes
struct adj_list {
    Node *head;
};