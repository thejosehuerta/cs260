#include <iostream>
#include <ctype.h>
#include <string>
#include "Queue.h"

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


int main(int argc, char **argv) {
    bool running = true;
    cout << endl << "----------------------------------" << endl;
    cout << "Welcome to your linked-list queue.";

    while(running) {
        cout << endl << "----------------------------------";
        cout << endl << "What do you want to do?" << endl;
        cout << endl << "1. Enqueue an element";
        cout << endl << "2. Dequeue front element";
        cout << endl << "3. View front element";
        cout << endl << "4. Print all elements";
        cout << endl << "5. Exit" << endl;

        string input;
        cout << "Enter a number: ";
        cin >> input;
        //if loop checks for numeric input
        if (isNumeric(input)) {
            int num_input = stoi(input);
            switch (num_input) {
            case 1:
                cout << "1" << endl;
                break;

            case 2:
                cout << "2" << endl;
                break;

            case 3:
                cout << "3" << endl;
                break;

            case 4:
                cout << "4" << endl;
                break;

            case 5:
                cout << "Exiting." << endl;
                running = false;
                break;
            
            default:
                cout << "Out of range." << endl;
                break;
            }
        //if inout is non-numeric, it returns this statement
        } else {
            cout << endl << "'" << input << "'" << " is not a number." << endl;
        }

    





    }

   


    //Create a new queue named my_queue
    Queue *my_queue = new Queue();
    //Call front() function to return the first element
    //cout << "my_queue->Front: " << my_queue->Front() << endl;
    //my_queue->Print();
    //my_queue->Dequeue();

    //my_queue->Enqueue(3);
    //my_queue->Enqueue(6);

    //cout << "my_queue->Front: " << my_queue->Front() << endl;
   

    //my_queue->Dequeue();

    //cout << "my_queue->Front: " << my_queue->Front() << endl;
    //my_queue->Print();




    return 0;
}