#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.h"

using std::string;
using std::cout;
using std::endl;

//Construct a LinkedList
LinkedList::LinkedList() {
    head = NULL;
}

//Inserts an int value "data" at position "n" of LinkedList
void LinkedList::Insert(int data, int n) {
    /*Create new node called Temp1 with its "data" field as 
    the data entered as the argument, and its "next"  field 
    pointing to NULL
    */
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    //Inserting at the head (front of the list)
    //Time complexity of O(1) constant time because if n = 1, it will always add at the front.
    if(n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    //Time complexity for this is O(n). It will always need to traverse throughout the list in order to find nth position
    for(int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

//Removes an element from the list at the "n"th position
void LinkedList::Remove(int n) {
    //Create node "temp1" to point to (n-1)th node in list
    Node *temp1 = head;
    //if deleting first element (n = 1)
    //Time complexity of O(1) constant time because if n = 1, it will always remove the front.
    if(n == 1) {
        //Make head now point to the second node in list
        head = temp1->next;
        free(temp1);
        return;
    }
    //Time complexity for this is O(n). It will always need to traverse throughout the list in order to find nth position
    for(int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
    //Create node "temp2" to point to nth node
    Node *temp2 = temp1->next;
    //Then, make temp1 point to (n+1)th node
    temp1->next = temp2->next;
    free(temp2);
}

//Retrieves an element from the list at the nth position
int LinkedList::Retrieve(int n) {
    //Create node "temp1" to point to (n-1)th node in list
    Node *temp1 = head;
    //Time complexity of O(1) constant time because if n = 1, it will always return the front.
    if(n == 1) {
        //Make head now point to the second node in list
        return temp1->data;
    }
    //Time complexity for this is O(n). It will always need to traverse throughout the list in order to find nth position
    for(int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
    //Create node "temp2" to point to nth node
    Node *temp2 = temp1->next;
    return temp2->data;
}

//Prints all elements in LinkedList
void LinkedList::Print() {
    Node *temp = head;
    cout << "Head -> ";
    //Time complexity for this is O(n). It will always need to traverse throughout the list in order to find nth position
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << endl;
}

//Counts the number of elements present in the list and returns said number
int LinkedList::Count() {
    Node *temp = head;
    int num = 0;
    //Time complexity for this is O(n). It will always need to traverse throughout the list in order to find nth position
    while(temp != NULL) {
        num++;
        temp = temp->next;
    }
    return num;
}