#include <stdio.h>
#include <iostream>
#include "Graph.h"

using std::string;
using std::cout;
using std::endl;

Graph::Graph(int V) {
    this->V = V;
    this->list = new adj_list[V];
    for(int i = 0; i < V; i++) {
        list[i].head = NULL;  
    }

}

Node *Graph::NewNode(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void Graph::AddEdge(int src, int dest) {
    Node *new_node = NewNode(dest);
    //new_node->cost = cost;
    new_node->next = this->list[src].head;
    this->list[src].head = new_node;

    new_node = NewNode(src);
    new_node->next = this->list[dest].head;
    this->list[dest].head = new_node;
}

void Graph::PrintGraph() {
    for(int i=0; i < this->V ;i++)
    {
        Node *root = this->list[i].head;
        cout << "vertex " << i << ":  ";

        while(root!=NULL)
        {
            cout<<root->data<<" -> ";
            root=root->next;
        }
        cout<< "NULL" << endl;
    }
}
