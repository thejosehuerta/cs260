#include <stdio.h>
#include <iostream>
#include <functional>
#include "Graph.h"

using std::string;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

//Constructs a graph with "V" nodes (aka vertices)
Graph::Graph(int V) {
    this->V = V;
    this->current_id = 0;
    this->list = new adj_list[V];
    for(int i = 0; i < V; i++) {
        list[i].head = NULL;   
    }
}

void Graph::PrintTest() {

    cout << "city_names: " << endl;
    set<string>::iterator it;
    for(it = city_names.begin(); it != city_names.end(); it++) {
        cout << *it << endl;
    } 

    cout << "cities:" << endl;
    map <string, int>::iterator it1;
    for(it1 = cities.begin(); it1 != cities.end(); it1++) {
        cout << it1->first << "  " << it1->second << endl;
    }
}

/*If city (name) DNE (does not exist) in the "city_names" set,
then return true*/
bool Graph::CityDNE(string name) {
    return city_names.insert(name).second;
}

//Adds a node to the graph
void Graph::AddNode(string name) {
    if(current_id + 1 > this->V) {
        cout << this->V << " is the maximum of cities you can have! ";
        cout << "'" << name << "' not added!" << endl;
        return;
    }
    if(CityDNE(name)) {
        Node *new_node = new Node;
        new_node->city.first = name;
        new_node->city.second = current_id++;
        new_node->next = NULL;
        this->list[new_node->city.second].head = new_node;

        cities.insert(new_node->city);
        cout << name <<" added!" << endl;
    } 
    else {
        cout << "Not added!" << endl;
    }
}

//Creates undirected connections between "start" and "end"
void Graph::AddEdge(string start, string end, int dist) {

    if(CityDNE(start) || CityDNE(end)) {
        cout << "Either '" << start << "' or '" << end << "' does not exist!" << endl;
    }
    else {
        int start_id = cities.find(start)->second;
        int end_id = cities.find(end)->second;

        
        Node *end_node = new Node();
        end_node->city = make_pair(end, end_id);
        end_node->dist = dist;
        end_node->next = NULL;

        Node *temp = this->list[start_id].head;
        
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = end_node;

        Node *start_node = new Node();
        start_node->city = make_pair(start, start_id);
        start_node->dist = dist;
        start_node->next = NULL;

        temp = this->list[end_id].head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = start_node;
    }
}

//Prints the graph as an adjacency list
void Graph::PrintGraph() {
   for(int i = 0; i < this->V ;i++) {
        Node *root = this->list[i].head;
        cout << "[" << i << "][" << root->city.first << "]: ";

        root = root->next;
        while(root != NULL) {
            cout << "[" << root->city.first << ", " << root->dist << "] -> ";
            root = root->next;
        }
        cout << "[]" << endl;
        if(this->list[i + 1].head == NULL) {
            break;
        }
    }

}
