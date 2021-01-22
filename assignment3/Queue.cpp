#include <stdio.h>
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

Queue::Queue() {
    front = NULL;
    rear = NULL;
}


void Queue::Enqueue(int new_value) {
    //Create a new node
    Node *temp = new Node();
    //Storing "new_value" to new node's "data" value
    temp->data = new_value;
    //New node will point to null 
    temp->next = 0;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;    
    } else {
        rear->next = temp;
        rear = temp;
    }
}

int Queue::Front() {
    if(front == NULL) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        return front->data;
    }
}
