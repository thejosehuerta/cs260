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
    //Creates a graph with "V" nodes aka vertices
    this->V = V;
    //initializes the ID counter to 0
    this->current_id = 0;
    //the adjacency list is created. It will be an array of pointer nodes
    this->list = new adj_list[V];
    for(int i = 0; i < V; i++) {
        list[i].head = NULL;   
    }
}

//This function prints all cities stored in the "city_names" set
void Graph::PrintCities() {
    cout << endl << "++++++++++++++++++++++++++++++++++" << endl;
    cout << "Current Cities: ";
    cout << endl << "++++++++++++++++++++++++++++++++++" << endl;
    set<string>::iterator it;
    for(it = city_names.begin(); it != city_names.end(); it++) {
        cout << *it << endl;
    } 
    cout << "----------------------------------" << endl;

    /* Prints map values
    cout << "cities:" << endl;
    map <string, int>::iterator it1;
    for(it1 = cities.begin(); it1 != cities.end(); it1++) {
        cout << it1->first << "  " << it1->second << endl;
    }
    */
}

/*If city (name) DNE (does not exist) in the "city_names" set,
then return true*/
bool Graph::CityDNE(string name) {
    return city_names.insert(name).second;
}

//Adds a node to the graph
void Graph::AddNode(string name) {
    //First it checks if we have reached the maximum number of nodes we can have in the graph
    if(current_id + 1 > this->V) {
        cout << endl << "----------------------------------" << endl;
        cout << this->V << " is the maximum of cities you can have! ";
        cout << "'" << name << "' not created!";
        cout << endl << "----------------------------------" << endl;
        return;
    }
    //if the city name does not exist, then create a new node
    if(CityDNE(name)) {
        Node *new_node = new Node;
        //"city" is a pair and "first" gets its string value (name), while "second" gets its int value (ID)
        new_node->city.first = name;
        new_node->city.second = current_id++;
        new_node->next = NULL;
        //Add this node to the graph
        //Remeber that its unique ID is also its position in the adgecancy list
        this->list[new_node->city.second].head = new_node;

        //this "city" pair is inserted into the "cities" map
        cities.insert(new_node->city);
        cout << endl << "----------------------------------" << endl;
        cout << "'" << name << "' created!";
        cout << endl << "----------------------------------" << endl;
       
    } 
    else {
        cout << endl << "----------------------------------" << endl;
        cout << "City not created! No two cities can have the same name!";
        cout << endl << "----------------------------------" << endl;
    }
}

//Creates undirected connections between "start" and "end" with a distance of "dist"
void Graph::AddEdge(string start, string end, int dist) {
    //First it checks if "start" exists in the city_names set
    if(CityDNE(start)) {
        cout << "'" << start << "' does not exist!" << endl;
        /*It erases it because this function unintentionally adds "start" to 
        the set whether it exists or not, so we want to delete it if it does not exist*/
        city_names.erase(start);
        return;
    }
    //The same thing as above but for "end"
    else if(CityDNE(end)) {
        cout << "'" << end << "' does not exist!" << endl;
        city_names.erase(end);
        return;
    }
    //In this case, we know that both "start" and "end" exist, and we can begin to create an edge between them
    else {
        //Using the "cities" map's find function we can return a city's name ID value
        int start_id = cities.find(start)->second;
        int end_id = cities.find(end)->second;

        //A new node is added to the adjecancy list at "start's" head node
        //every new node added is chained a la linked list
        Node *end_node = new Node();
        end_node->city = make_pair(end, end_id);
        end_node->dist = dist;
        end_node->next = NULL;

        Node *temp = this->list[start_id].head;
        //We will always be adding at the end of the linked list
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = end_node;

        //Since this is an undirected graph, we will also be adding the connection from end to start
        Node *start_node = new Node();
        start_node->city = make_pair(start, start_id);
        start_node->dist = dist;
        start_node->next = NULL;

        temp = this->list[end_id].head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = start_node;
        cout << endl << "----------------------------------" << endl;
        cout << "'" << start << "' and " << "'" << end << "' have been connected via a highway that is " << dist << " miles long!";
        cout << endl << "----------------------------------" << endl;
        
    }
}

//Prints the graph as an adjacency list
void Graph::PrintGraph() {
    cout << endl << "++++++++++++++++++++++++++++++++++" << endl;
    cout << "Cities Adjacency List: ";
    cout << endl << "++++++++++++++++++++++++++++++++++" << endl;
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
    cout << "----------------------------------" << endl;


}
