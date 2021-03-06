#include <stdio.h>
#include <iostream>
#include <string>
#include "Hash.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using std::isdigit;

bool isNumeric(string);
int returnNumeric(string);
void invalidInput(string);

int main(int argc, char **argv) {
    //New hash table is created!
    Hash *Hashbrown = new Hash();
 
    bool running = true;
    cout << endl << "----------------------------------" << endl;
    cout << "Welcome to your hash table!";
    cout << endl << "----------------------------------" << endl;
    cout << "Your table will be a fixed size of 10 rows (this can be changed in the source code)." << endl;
    cout << "It can hold strings (names, places, etc.) and will be pre-filled with values." << endl;
    
    //Initial values present in the table
    string names[] = {"cats", "cast", "guitar", "dare", 
        "read", "rabbit", "tar", "rat", "arc", "car"};
    int names_size = sizeof(names)/sizeof(names[0]);
    //adding the values to the table
    for(int i = 0; i < names_size; i++) {
        Hashbrown->Insert(names[i]);
    }
    //printing the table in a readable way
    Hashbrown->PrintTable();

    cout << endl << "----------------------------------" << endl;
    cout << "Now that you've seen your table, choose what to do next!";
    cout << endl << "----------------------------------" << endl;

     while(running) {
        cout << endl << "----------------------------------" << endl;
        cout << "What do you want to do?";
        cout << endl << "----------------------------------" << endl;
        cout << endl << "1. Insert a value into the table";
        cout << endl << "2. Delete a value in the table";
        cout << endl << "3. Search for a value in the table";;
        cout << endl << "4. Print the table and all its elements";
        cout << endl << "5. Exit" << endl;

        string choice_input;
        int choice_num;

        cout << "Your choice: ";
        cin >> choice_input;

        string value_input;

        choice_num = returnNumeric(choice_input);
        if(choice_num == -1) {
            invalidInput(choice_input);
        } else {
            switch(choice_num){
            case 1:
                cout << endl << "Enter the value you wish to insert into the table:" << endl;
                cin >> value_input;
                Hashbrown->Insert(value_input);
                cout << endl << "----------------------------------" << endl;
                cout << "'" << value_input << "' successfully added!";
                cout << endl << "----------------------------------" << endl;
                break;
            case 2:
                cout << endl << "Enter the value you wish to delete from the table:" << endl;
                cin >> value_input;
                Hashbrown->Delete(value_input);
                break;
            case 3:
                cout << endl << "Enter the value you wish to look for in the table:" << endl;
                cin >> value_input;
                Hashbrown->Contains(value_input);
                break;
            case 4:
                Hashbrown->PrintTable();
                break;
            case 5:
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