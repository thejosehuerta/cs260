#include <string>
using std::string;

struct Node {
    int data;
    int cost;
    Node *next;
};

struct adj_list {
    Node *head;
};