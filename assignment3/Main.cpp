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
    Queue *my_queue = new Queue();

    bool running = true;
    cout << endl << "----------------------------------" << endl;
    cout << "Welcome to your linked-list queue.";

    while(running) {
        cout << endl << "----------------------------------";
        cout << endl << "What do you want to do?" << endl;
        cout << endl << "1. Enqueue an number";
        cout << endl << "2. Dequeue number in front";
        cout << endl << "3. View number in front of queue";
        cout << endl << "4. Print all numbers in queue";
        cout << endl << "5. Exit" << endl;

        string input;
        string enq_input;

        cout << "Enter a number: ";
        cin >> input;
        //if loop checks for numeric input
        if (isNumeric(input)) {
            //if input is numeric, stoi turns it into an int and passes it to num_input
            int num_input = stoi(input);
            switch (num_input) {
            case 1:
                cout << "Enter a number to enqueue: ";
                cin >> enq_input;
                if(isNumeric(enq_input)) {
                     //if enq_input is numeric, stoi turns it into an int and passes it to enq_int
                    int enq_int = stoi(enq_input);
                    my_queue->Enqueue(enq_int);
                    cout << endl << enq_int << " successfully enqueued!";
                } else {
                    //if enq_input is non-numeric
                    cout << endl << "Not a number.";
                }
                break;

            case 2:
                if(my_queue->isEmpty()) {
                    my_queue->Dequeue();
                } else {
                    my_queue->Dequeue();
                    cout << endl << "Number in front successfully dequeued." << endl;
                }
                break;

            case 3:
                cout << endl << "Number in front of queue: " << my_queue->Front() << endl;
                break;

            case 4:
                cout << endl << "Printing queue:" << endl;
                my_queue->Print();
                break;

            case 5:
                cout << "Exiting." << endl;
                running = false;
                break;
            
            default:
                cout << endl << "Out of range." << endl;
                break;
            }
        //if inout is non-numeric, it returns this statement
        } else {
            cout << endl << "'" << input << "'" << " is not a number." << endl;
        }
    }
    return 0;
}