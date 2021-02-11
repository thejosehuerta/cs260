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

//Inserts an int value "data" in numerical order
void LinkedList::Insert(int data) {
    /*Create new node called Temp1 with its "data" field as 
    the data entered as the argument, and its "next"  field 
    pointing to NULL
    */
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    //Inserting at the head (front of the list) if list is empty or if "data" is less than the first element
    //Time complexity of O(1) constant time because if n = 1, it will always add at the front.
    if(head == NULL || data < head->data) {
        temp1->next = head;
        head = temp1;
        return;
    } else {
        Node *prev;
        Node *current = head;
        //Traverse through list to find where to insert "data"
        /*By the end of this loop, "prev" should point to the node "temp1" will go after,
        and "current" will be the node that "temp1" will precede*/
        while(current != NULL && current->data <= data) {
            prev = current;
            current = current->next;
        }
        //New end of list
        if(current == NULL) {
            prev->next = temp1;
        } else {
            //Somewhere in the list
            temp1->next = current;
            prev->next = temp1;
        }
        
    }  

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

void LinkedList::Delete(int data) {
    Node *temp = head;
    Node *temp1 = head;
    int num = 0;
    //checks if list is empty
    if(temp1 == NULL) {
        cout << "----------------------------------" << endl;
        cout << "List is empty! Insert an element before deleting!" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    //if "data" is first element in list
    if(temp1->data == data) {
        cout << "----------------------------------" << endl;
        cout << "'" << data << "'" << " found in the first position!" << endl;
        head = temp1->next;
        free(temp1);
        cout << "Element deleted." << endl;
        cout << "----------------------------------" << endl;  
        return;
    }

    //while loop traverses through list until data is no longer greater than temp1->data
    while(temp1->next != NULL && temp1->data < data) {
        temp1 = temp1->next;
        //num is for counting how many times it takes until loop breaks, i.e. temp1 points to the node
        //containing the integer closest to "data"
        num++;
        temp = temp->next;
        if(num == 1) {
            temp = head;
        }
    }

    if(temp1->next == NULL) {
        temp->next = NULL;
        free(temp1);
    }
    //This is true when all elements in list are searched and "data" is both not found and bigger than any element in the list
    if(temp1->next == NULL && data > temp1->data) {
        cout << "----------------------------------" << endl;
        cout << "Searched through all " << num + 1 << " elements and " << "'" << data << "' was not found!" << endl;
        cout << "No elements were deleted." << endl;
        cout << "----------------------------------" << endl;
    }
    //This is true when "data" is found in the list
    else if(temp1->data == data) {
        cout << "----------------------------------" << endl;
        cout << "'" << data << "'" << " found!" << endl;
        cout << num << " elements were traversed before finding '" << data << "'!" << endl;
        //if "data" is last element in the list
        if(temp1->next == NULL) {
            Node *temp2 = temp1->next;
            temp->next = NULL;
            free(temp2);
            cout << "Last element deleted!" << endl;
            cout << "----------------------------------" << endl;  
        } else {
        //Create node "temp2" to point to nth node
        Node *temp2 = temp1->next;
        //Then, make temp1 point to (n+1)th node
        temp->next = temp2;
        free(temp1);
        cout << "Element deleted." << endl;
        cout << "----------------------------------" << endl;  
        }    
      ////This is true when all elements in list are searched and "data" is both not found and SMALLER than any element in the list
    } else {
        cout << "----------------------------------" << endl;
        cout << "Your number was smaller than any number in the list. '" << data << "' was not found!" << endl;
        cout << "No elements were deleted." << endl;
        cout << "----------------------------------" << endl;
    }
}

//Searches LinkedList for "data" parameter.
void LinkedList::Search(int data) {
    Node *temp1 = head;
    int num = 0;
    //checks if list is empty
    if(temp1 == NULL) {
        cout << "List is empty! Insert an element first!" << endl;
        return;
    }
    //while loop traverses through list until data is no longer greater than temp1->data
    while(temp1->next != NULL && temp1->data < data) {
        temp1 = temp1->next;
        //num is for counting how many times it takes until loop breaks, i.e. temp1 points to the node
        //containing the integer closest to "data"
        num++;
    }
    //This is true when all elements in list are searched and "data" is both not found and bigger than any element in the list
    if(temp1->next == NULL && data > temp1->data) {
        cout << "----------------------------------" << endl;
        cout << "Searched through all " << num + 1 << " elements and " << "'" << data << "' was not found!" << endl;
        cout << "----------------------------------" << endl;
    }
    //This is true when "data" is found in the list
    else if(temp1->data == data) {
        cout << "----------------------------------" << endl;
        cout << "'" << data << "'" << " found!" << endl;
        cout << num << " elements were traversed before finding '" << data << "'!" << endl;
        cout << "----------------------------------" << endl;      
      ////This is true when all elements in list are searched and "data" is both not found and SMALLER than any element in the list
    } else {
        cout << "----------------------------------" << endl;
        cout << "Your number was smaller than any number in the list. '" << data << "' was not found!" << endl;
        cout << "----------------------------------" << endl;
    }
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