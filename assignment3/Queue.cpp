#include <stdio.h>
#include <iostream>
#include <string>
#include "Queue.h"

using std::string;
using std::cout;
using std::endl;

//Construct a queue
Queue::Queue() {
    front = NULL;
    rear = NULL;
}

/*Simple function that checks whether queue is empty
or not (by checking whether or not both 'front' and 'rear' are NULL)*/
bool Queue::isEmpty() {
    bool empty = true;
    if(front == NULL && rear == NULL) {
        return empty;
    } else {
        empty = false;
        return empty;
    }
}

//Enqueues int value
void Queue::Enqueue(int new_value) {
    //Create a new node
    Node *temp = new Node();
    //Storing "new_value" to new node's "data" value
    temp->data = new_value;
    //New node will point to null 
    temp->next = NULL;
    //Calls isEmpty() function to check if queue is empty
    if(isEmpty()) {
        front = rear = temp;
        return;    
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void Queue::Dequeue() {
    Node *temp = front;
    if(isEmpty()) {
        cout << endl << "Queue is empty! Nothing to dequeue." << endl;
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    } else {
        //the front pointer will point to the next element in the queue
        front = front->next;
    }
    //because front is now pointing to the second element, the original "first" element will be deleted and memory will be freed
    free(temp);
}

//Returns the value belonging to the front node
int Queue::Front() {
    if(isEmpty()) {
        cout << endl << "Queue is empty! No element in front." << endl;
        return -1;
    } else {
        return front->data;
    }
}

//Prints all elements in queue
void Queue::Print() {
    if(isEmpty()) {
        cout << endl << "Queue is empty! Nothing to print." << endl;
        return;
    } else {
        Node *temp = front;
        cout << "Front\t";
        //prints elements until temp == NULL (when the last node is reached)
        while(temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "Rear";
        return;
    }
}
