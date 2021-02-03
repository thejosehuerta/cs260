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

//Main
int main(int argc, char **argv) {
    //new linked list is created!
    LinkedList *my_linkedlist = new LinkedList();

    bool running1 = true;
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
    while(running1) {
        cout << "Enter the number of integers you initially want in your list: ";
        cin >> size_input;
        //checks for numeric input.
        size_num = returnNumeric(size_input);
        if(size_num == -1) {
            cout << endl << "----------------------------------" << endl;
            cout << "'" << size_input << "'" << " is not a valid input.";
            cout << endl << "----------------------------------" << endl;
        } else {;
            running1 = false;
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
            cout << endl << "----------------------------------" << endl;
            cout << "'" << list_input << "'" << " is not a valid input.";
            cout << endl << "----------------------------------" << endl;
            cout << endl << "Your current list: " << endl;
            my_linkedlist->Print();
            i--;
        } else {
            my_linkedlist->Insert(list_num, i);
            cout << endl << "Your current list: " << endl;
            my_linkedlist->Print();
        }    
    }
     cout << endl << "2";

  

    return 0;
}