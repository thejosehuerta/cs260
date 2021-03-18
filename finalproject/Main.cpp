#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include "Graph.h"

using std::cout;
using std::cin;
using std::endl;
using std::rand;


bool isNumeric(string);
int returnNumeric(string);
void invalidInput(string);
string RandState();
void AddNodeStatus(int);

int main(int argv, char **argc) {
    string destroyed_state = RandState();
    bool running = true;

    cout << endl << "----------------------------------" << endl;
    cout << "Hey you, you're finally awake. Due to unforseen circumstances, the state of " << destroyed_state << " was completely destroyed." << endl;
    cout << "It's up to you to start anew and construct a replacement.";
    cout << endl << "----------------------------------" << endl;
    cout << "What will be the name of this new glorious state of yours?" << endl;
    cout << "Enter the name here: ";

    string state_name;
    getline(cin, state_name);
   
    cout << endl << "----------------------------------" << endl;
    cout << "Fantastic! Now you- wait, '" << state_name << "'? that's the best you- nevermind." << endl;
    cout << "Now you must create your cities!";
    cout << endl << "----------------------------------" << endl;

    //"V" stands for Vertices - original, I know
    string V_str_input;
    int V;

    while(running) {
        cout << "Enter the number of cities you plan to construct (at least two): ";
        getline(cin, V_str_input);
        V = returnNumeric(V_str_input);
        if(V <= 1) {
            invalidInput(V_str_input);
        } else {
            running = false;
        }
    }
    //Construct a graph
    Graph *graph = new Graph(V);
    cout << endl << "----------------------------------" << endl;
    cout << V << " cities, eh? Works for me!" << endl;
    cout << "Now, we're wasting our tax payers' money just standing around- we gotta get started." << endl;
    cout << "We'll start right away by creating two new cities and then connecting them via a highway!";
    cout << endl << "----------------------------------" << endl;
    string city_name;
    string city1_name;

    cout << "Enter the name of your first city: ";
    getline(cin, city_name);
    graph->AddNode(city_name);
    
    running = true;
    while(running) {
        cout << "Enter the name of your second city: ";
        getline(cin, city1_name);
        if(city1_name == city_name) { 
            cout << endl << "----------------------------------" << endl;
            cout << "'" << city1_name << "' already exists! Try a different name!";
            cout << endl << "----------------------------------" << endl;

        } else {
            running = false;
        }
    }
    graph->AddNode(city1_name);
    

    cout << endl << "----------------------------------" << endl;
    cout << "Between you and I, I've already forgotten about " << destroyed_state << "." << endl;
    cout << "Next, before these cities are built and connected, we need to figure out how long the highway between them will be.";
    cout << endl << "----------------------------------" << endl;

    string dist_str;
    int dist_num;
    running = true;
    while(running) {
        cout << "Enter the distance (in miles, and as a number) you want between these two cities: ";
        getline(cin, dist_str);
        dist_num = returnNumeric(dist_str);
        if(dist_num <= 0) {
            invalidInput(dist_str);
        } else {
            running = false;
        }
    }
    cout << endl << "----------------------------------" << endl;
    if(dist_num == 1) {
        cout << dist_num << " mile!? Whatever you want, pal.";
    } else {
        cout << dist_num << " miles? Whatever you want, pal,";
    }
    cout << endl;
    cout << "Alright, just give me a couple nanoseconds and-" << endl;
    graph->AddEdge(city_name, city1_name, dist_num);

    cout << endl << "----------------------------------" << endl;
    cout << "Now that you have a couple cities to work with in your state, you choose what to do next.";
    cout << endl << "----------------------------------" << endl;

    running = true;
    while(running) {
        cout << endl << "----------------------------------" << endl;
        cout << "What do you want to do?";
        cout << endl << "----------------------------------" << endl;
        cout << endl << "1. Create a new city";
        cout << endl << "2. Connect two exisiting cities";
        cout << endl << "3. Print list of exisiting cities";
        cout << endl << "4. Print cities as an adjacency list graph";
        cout << endl << "5. Find the shortest path between two cities";
        cout << endl << "6. Minimum spanning tree";
        cout << endl << "7. Exit" << endl;

        string choice_input;
        int choice_num;
        string new_city;

        cout << "Your choice: ";
        cin >> choice_input;
        bool running1 = true;
        choice_num = returnNumeric(choice_input);
        if(choice_num == -1) {
            invalidInput(choice_input);
        } else {
            switch(choice_num) {
            case 1:
                cout << "Enter the name of your new city: ";
                cin.ignore();
                getline(cin, city_name);
                graph->AddNode(city_name);
                break;
            case 2:
                cin.ignore();
                graph->PrintCities();
                cout << "View the table above to check the spelling of your cities!" << endl;
                cout << "Enter the name of the first city (the start): ";
                getline(cin, city_name);

                cout << "Enter the name of the second city (the end): ";
                getline(cin, city1_name);

                
                while(running1) {
                    cout << "Enter the distance (in miles, and as a number) you want between these two cities: ";
                    getline(cin, dist_str);
                    dist_num = returnNumeric(dist_str);
                    if(dist_num <= 0) {
                        invalidInput(dist_str);
                    } else {
                        running1 = false;
                    }
                }
                graph->AddEdge(city_name, city1_name, dist_num);
                break;
            case 3:
                graph->PrintCities();
                break;
            case 4:
                graph->PrintGraph();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Exiting." << endl;
                running = false;
                break;
            default:
                cout << endl << "----------------------------------" << endl;
                cout << "Out of range.";
                cout << endl << "----------------------------------" << endl;
                break;
            }
        }
    }


    return 0;
}

/*bool function that checks a string input for any string characters.
Returns false if any non-numeric elements are found. */
bool isNumeric(string input) {
    for(int i = 0; i <input.length(); i++) {
        if(isdigit(input[i]) == false) {
            return false;
        } 
    } 
    return true;
}

/*Function to utilize isNumeric function to first check if value is 
numeric, convert that value to an int,
then return that value, else return -1. */
int returnNumeric(string str) {
    if(isNumeric(str)) {
        int value = stoi(str);
        return value;
    } else {
        return -1;
    }
}

/*Function to simply return a message stating that the user's input
is invalid. It saves time typing it out all the time. */
void invalidInput(string str){
    string message;
    message = "'" + str + "'" + " is not a valid input.";
    cout << endl << "----------------------------------" << endl;
    cout << message;
    cout << endl << "----------------------------------" << endl;
}


//Returns a random state as a string 
string RandState() {
    std::srand(time(0));
    string states[] = {"Alaska",
                  "Alabama",
                  "Arkansas",
                  "Arizona",
                  "California",
                  "Colorado",
                  "Connecticut",
                  "The District of Columbia",
                  "Delaware",
                  "Florida",
                  "Georgia",
                  "Hawaii",
                  "Iowa",
                  "Idaho",
                  "Illinois",
                  "Indiana",
                  "Kansas",
                  "Kentucky",
                  "Louisiana",
                  "Massachusetts",
                  "Maryland",
                  "Maine",
                  "Michigan",
                  "Minnesota",
                  "Missouri",
                  "Mississippi",
                  "Montana",
                  "North Carolina",
                  "North Dakota",
                  "Nebraska",
                  "New Hampshire",
                  "New Jersey",
                  "New Mexico",
                  "Nevada",
                  "New York",
                  "Ohio",
                  "Oklahoma",
                  "Oregon",
                  "Pennsylvania",
                  "Puerto Rico",
                  "Rhode Island",
                  "South Carolina",
                  "South Dakota",
                  "Tennessee",
                  "Texas",
                  "Utah",
                  "Virginia",
                  "Vermont",
                  "Washington",
                  "Wisconsin",
                  "West Virginia",
                  "Wyoming"};
    int states_size = (sizeof(states)/sizeof(states[0]));
    int des_state_index = std::rand() % states_size;
    string destroyed_state = states[des_state_index];
    return destroyed_state;
}