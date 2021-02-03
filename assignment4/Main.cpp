#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::isdigit;

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
string invalidInput(string str){
    string message;
    message = "'" + str + "'" + " is not a valid input.";
    cout << endl << "----------------------------------" << endl;
    cout << message;
    cout << endl << "----------------------------------" << endl;
    return "pop";
}

//Main
int main(int argc, char **argv) {
    //new linked list is created!
    LinkedList *my_linkedlist = new LinkedList();

    bool running = true;
    cout << endl << "----------------------------------" << endl;
    cout << "Welcome to your linked-list!";
    cout << endl << "----------------------------------" << endl;

    /*In this section, the user is aksed to input an interger
    value for how long their list will be. This initial length of
    the list is not concrete, but it makes sure that the user has a 
    linked list with initial values before performing the other functions
    such as inserting/removing/viewing elements. A while and for loop
    is used to make sure the input is numeric before continuing. */
    string size_input;
    int size_num;
    while(running) {
        cout << "Enter the number of integers you initially want in your list: ";
        cin >> size_input;
        //checks for numeric input.
        size_num = returnNumeric(size_input);
        if(size_num == -1) {
            invalidInput(size_input);
        } else {;
            running = false;
        }
    }

    cout << endl << "----------------------------------" << endl;
    cout << "Great! Now you will add to your list.";
    cout << endl << "----------------------------------" << endl;

    /*In this section, the user has set an initial size for their
    linked list and is now asked to fill that list. Every value is
    checked to make sure it is numeric and a linked list is created.
    Every element added here will be added in numerical order i.e. 
    the first number entered is added at the first position of the linked
    list, the second number entered is added to the second position 
    and so on.*/
    string list_input;
    int list_num;
    for(int i = 1; i <= size_num; i++) {
        cout << "Enter a number to add it to your list: ";
        cin >> list_input;
        list_num = returnNumeric(list_input);
        if(list_num == -1) {
            invalidInput(list_input);
            cout << endl << "Your current list: " << endl;
            my_linkedlist->Print();
            i--;
        } else {
            my_linkedlist->Insert(list_num, i);
            cout << endl << "Your current list: " << endl;
            my_linkedlist->Print();
        }    
    }
    cout << "----------------------------------" << endl;
    cout << "Awesome! You have successfully created a Linked-List!";
    cout << endl << "----------------------------------" << endl;
    cout << "You currently have a list with " << size_num << " integers:" << endl;
    my_linkedlist->Print();

    running = true;
    cout << "----------------------------------" << endl;
    cout << "Now, enter a choice and go crazy with the functions!";
    cout << endl << "----------------------------------" << endl;

    while(running) {
        cout << endl << "----------------------------------" << endl;
        cout << "What do you want to do?";
        cout << endl << "----------------------------------" << endl;
        cout << endl << "1. Insert an integer at any position in the list";
        cout << endl << "2. Remove an integer at any position in the list";
        cout << endl << "3. Retrieve an integer at any position in the list";
        cout << endl << "4. Print linked-list";
        cout << endl << "5. Exit" << endl;

        string choice_input;
        int choice_num;

        string pos_input;
        int pos_num;

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
                    cout << endl << "Enter the position you wish to insert this integer in: ";
                    cin >> pos_input;
                    pos_num = returnNumeric(pos_input);
                    if(pos_num == -1) {
                        invalidInput(pos_input);
                    } else {
                        if(pos_num < 1 || pos_num > my_linkedlist->Count()) {
                            cout << endl << "----------------------------------" << endl;
                            cout << "Invalid position!";
                            cout << endl << "----------------------------------" << endl;
                        } else {
                            my_linkedlist->Insert(element_num, pos_num);
                            cout << endl << "'" << element_num << "' successfully added to position " << "'" << pos_num << "'!" << endl;
                        }   
                    }
                }
                break;    
            case 2:
                cout << endl << "You currently have " << my_linkedlist->Count() << " elements in your linked-list:" << endl;
                my_linkedlist->Print();
                cout << "----------------------------------" << endl;
                cout << "To remove an element from the first position, enter a '1', to remove an element from the second position enter a '2'." << endl;
                cout << "Use this logic to remove an element from a position of your choice.";
                cout << endl << "----------------------------------" << endl;
                cout << "Enter a number: ";
                cin >> pos_input;
                pos_num = returnNumeric(pos_input);
                if(pos_num == -1) {
                    invalidInput(pos_input);
                } else {
                    if(pos_num < 1 || pos_num > my_linkedlist->Count()) {
                        cout << endl << "----------------------------------" << endl;
                        cout << "Invalid position!";
                        cout << endl << "----------------------------------" << endl;
                    } else {
                        my_linkedlist->Remove(pos_num);
                        cout << endl << "Element at position '" << pos_num << "' successfully removed!" << endl;
                    }
                }
                break;  
                    case 3:
                    cout << endl << "----------------------------------" << endl;
                    cout << "Enter a position to retrieve the element currently living there.";
                    cout << endl << "----------------------------------" << endl;
                    cout << "Enter a number: ";
                    cin >> pos_input;
                    pos_num = returnNumeric(pos_input);
                    if(pos_num == -1) {
                        invalidInput(pos_input);
                    } else {
                        if(pos_num < 1 || pos_num > my_linkedlist->Count()) {
                            cout << endl << "----------------------------------" << endl;
                            cout << "Invalid position!";
                            cout << endl << "----------------------------------" << endl;
                        } else {
                            element_num = my_linkedlist->Retrieve(pos_num);
                            cout << endl << "Element at position '" << pos_num << "' is currently: '" << element_num << "'!" << endl;
                        }
                    }  
                break;  
            case 4:
                cout << endl << "You currently have " << my_linkedlist->Count() << " elements in your linked-list:" << endl;
                my_linkedlist->Print();
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