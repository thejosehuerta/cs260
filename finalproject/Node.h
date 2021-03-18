#include <string>


using std::string;
using std::pair;

struct Node {
    pair<string, int> city;
    int dist;
    Node *next;
};

struct adj_list {
    Node *head;
};