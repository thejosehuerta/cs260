#include <stdio.h>
#include <iostream>
#include <string>
#include "Queue.h"

using std::string;
using std::cout;
using std::endl;

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

void Queue::Enqueue(int new_value) {
    //Create a new node
    Node *temp = new Node();
    //Storing "new_value" to new node's "data" value
    temp->data = new_value;
    //New node will point to null 
    temp->next = 0;
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
        cout << "Queue is empty!" << endl;
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

int Queue::Front() {
    if(isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        return front->data;
    }
}
