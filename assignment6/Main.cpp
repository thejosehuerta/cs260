#include <iostream>
#include <stdio.h>
#include <string>
#include "BST.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using std::isdigit;

bool isNumeric(string);
int returnNumeric(string);
void invalidInput(string);

//Main
int main(int argc, char **argv) {
    BST *tree = new BST();

    bool running = true;
    cout << endl << "------------------------------------------" << endl;
    cout << "Welcome to your binary search tree!" << endl;
    cout << "In order to show the functionalities of this" << endl;
    cout << "program, your tree will already include pre-existing" << endl;
    cout << "integer values.";
    cout << endl << "------------------------------------------" << endl;

    //These will be the initial values present in the tree
    int initial_values[] = {44, 17, 32, 78, 50, 48, 62, 88};
    //get size of array
    const int init_val_size = sizeof(initial_values)/sizeof(initial_values[0]);
    //Insert values into tree
    for(int i = 0; i < init_val_size; ++i){
        tree->Insert(initial_values[i]);
    }

    cout << "This is your current binary search tree and its values:" << endl << endl;
    cout << "     44" << endl;
    cout << "    /  \\" << endl;
    cout << "  17    78" << endl;
    cout << "   \\    / \\" << endl;
    cout << "    32 50  88" << endl;
    cout << "       / \\" << endl;
    cout << "      48  62" << endl;

    cout << endl << "------------------------------------------" << endl;
    cout << "These are the tree's values printed in 4 different traversal orders:" << endl << endl;
    cout << "Pre-order: "; tree->PrintPreOrder();
    cout << "In-order: "; tree->PrintInOrder();
    cout << "Post-order: "; tree->PrintPostOrder();
    cout << "Level-order: "; tree->PrintLevelOrder();
    cout << "------------------------------------------" << endl;

    cout << "Now that you know what your tree looks like and see that the" << endl;
    cout << "common methods of traversal are working, you can choose what to do next." << endl;
    cout << "------------------------------------------" << endl;

    running = true;
    while(running) {
        cout << endl << "----------------------------------" << endl;
        cout << "Select from the following choices:";
        cout << endl << "----------------------------------" << endl;
        cout << endl << "1. Insert an integer in your tree";
        cout << endl << "2. Delete a specific integer from your tree";
        cout << endl << "3. Return the minimum and maximum values of your tree";
        cout << endl << "4. Print your tree in four different traversal orders";
        cout << endl << "5. Exit" << endl;

        string choice_input;
        int choice_num;

        string element_input;
        int element_num;

        cout << "Your choice: ";
        cin >> choice_input;

        choice_num = returnNumeric(choice_input);
        if(choice_num == -1) {
            invalidInput(choice_input);
        } else {
            switch(choice_num){
            case 1:
                cout << endl << "Enter the integer you wish to add: ";
                cin >> element_input;
                element_num = returnNumeric(element_input);
                if(element_num == -1) {
                    invalidInput(element_input);
                } else {
                    tree->Insert(element_num);
                    cout << endl << "----------------------------------" << endl;
                    cout << "'" << element_num << "' successfully added!";
                    cout << endl << "----------------------------------" << endl;
                }
                break;
            case 2:
                cout << endl << "Enter the integer you wish delete: ";
                cin >> element_input;
                element_num = returnNumeric(element_input);
                if(element_num == -1) {
                    invalidInput(element_input);
                } else {
                    tree->Delete(element_num);
                }
                break;
            case 3:
                cout << endl << "----------------------------------" << endl;
                cout << "Minimum value: " << tree->FindMin() << endl;
                cout << "Maximum value: " << tree->FindMax();
                cout << endl << "----------------------------------" << endl;
                break;
            case 4:
                cout << endl << "------------------------------------------" << endl;
                cout << "Your tree's current values in four different traversal orders:" << endl << endl;
                cout << "Pre-order: "; tree->PrintPreOrder();
                cout << "In-order: "; tree->PrintInOrder();
                cout << "Post-order: "; tree->PrintPostOrder();
                cout << "Level-order: "; tree->PrintLevelOrder();
                cout << "------------------------------------------" << endl;
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