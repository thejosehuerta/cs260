#include <stdio.h>
#include <iostream>
#include "Hash.h"

using std::string;
using std::cout;
using std::endl;

Hash::Hash() {
    for(int i = 0; i < table_size; i++) {
        HashTable[i] = new Item;
        HashTable[i]->name = "";
        HashTable[i]->next = NULL;
    }
}

//This function converts a string into its respective hash key
int Hash::HashValue(string name) {
    int hash = 0;
    int index;
    for(int i = 0; i < name.length(); i++) {
        /*By the end of the loop, hash will be the sum of all the 
        string's ASCII values */
        hash = hash + (int)name[i];
    }
    /*The index will be the resulting hash divided by the table_size
    and return its remaninder*/
    index = hash % table_size;
    return index;
}

/*This function inserts a string into its respective hash table
by using its hash value as an index */
void Hash::Insert(string name) {
    //Convert "name" to its hash value
    int index = HashValue(name);
    //If this index in the table is empty, then insert here
    if(HashTable[index]->name == "") {
        HashTable[index]->name =  name;
        //cout << "'" << HashTable[index]->name << "'" << " added to index " << index << "!" << endl;
    /*If item does not exist but its hash value does, items are chained
    together a la linked list  */
    } else {
        //new "item" is created
        Item *head = HashTable[index];
        Item *new_item = new Item();
        new_item->name = name;
        /*new items are inserted at the head of the list in order to keep 
        this operation's time complexity to O(1)*/
        new_item->next = HashTable[index];
        HashTable[index] = new_item;
        //cout << "'" << HashTable[index]->name << "'" << " added to index " << index << "!" << endl;
    }
}
//This function returns whether or not an item exists in the table
void Hash::Contains(string name) {
    bool found_name = false;
    int index = HashValue(name);
    Item *temp = HashTable[index];
    //if element is found and is the only element in index
    if(temp->name == name && temp->next == NULL) {
        cout << endl << "----------------------------------" << endl;
        cout << "'" << name << "' found in index " << index << ". No other elements were found in this index.";
        cout << endl << "----------------------------------" << endl;
    } 
    //if element is found at the head of the index
    else if(temp->name == name) {
        cout << endl << "----------------------------------" << endl;
        cout << "'" << name << "' found at the head of index " << index << "!";
        cout << endl << "----------------------------------" << endl;
    } else {
        while(temp->next != NULL && found_name == false)  {
            temp = temp->next;
            if(temp->name == name) {
                found_name = true;
            }
        }
        //if element is found somewhere in the index
        if(temp->name == name) {
            cout << endl << "----------------------------------" << endl;
            cout << "'" << name << "' found in index " << index << "!";
            cout << endl << "----------------------------------" << endl;
        } else {
            cout << endl << "----------------------------------" << endl;
            cout << "'" << name << "' not found!";
            cout << endl << "----------------------------------" << endl;
        }
    }
}

//This function deletes an item in the table
void Hash::Delete(string name) {
    int index = HashValue(name);
    Item *temp = new Item();
    Item *temp1 = new Item();
    Item *temp2 = new Item();
    //check if index is empty
    if(HashTable[index]->name == "" ) {
        cout << endl << "----------------------------------" << endl;
        cout << "'" << name << "' not found! Nothing deleted.";
        cout << endl << "----------------------------------" << endl;
    }
    //if item is found and is the only item in the index
    else if(HashTable[index]->name == name && HashTable[index]->next == NULL) {
        HashTable[index]->name = "";
        cout << endl << "----------------------------------" << endl;
        cout << "'" << name << "' was found and deleted!";
        cout << endl << "----------------------------------" << endl;
    }
    //if multiple items are in the same index but the item is found at the head
    else if(HashTable[index]->name == name) {
        temp = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete temp;  
        cout << endl << "----------------------------------" << endl;
        cout << "'" << name << "' was found at the head of index " << index << " and was deleted!";
        cout << endl << "----------------------------------" << endl;
    //if item is supposedly found but not at the head of the index   
    } 
    else {
        temp = HashTable[index];
        temp1 = HashTable[index]->next;

        while(temp1 != NULL && temp1->name != name) {
            temp = temp1;
            temp1 = temp1->next;
        }
        //index was checked and item wasn't found
        if(temp1 == NULL) {
            cout << endl << "----------------------------------" << endl;
            cout << "This item's hash value exists, but " << "'" << name << "' was not found!";
            cout << endl << "----------------------------------" << endl;
        } 
        //if item we want to delete is at the end of the list
        else if(temp1->next == NULL){
            temp->next = NULL;
            delete temp1;
            cout << endl << "----------------------------------" << endl;
            cout << "'" << name << "' was found at the end of index " << index << "'s list and was deleted!";
            cout << endl << "----------------------------------" << endl;
        } 
        //if item we want to delete is in the middle of the list
        else {
            temp->next = temp1->next;
            delete temp1;
            cout << endl << "----------------------------------" << endl;
            cout << "'" << name << "' was found in index " << index << " and was deleted!";
            cout << endl << "----------------------------------" << endl;
        }
    }
}

//This function prints all elements in the hash table
void Hash::PrintTable() {
    cout << endl << "Here is your current table: ";
    cout << endl << "----------------------------------" << endl;
    for(int i = 0; i < table_size; i++) {
        cout << "Index " << i << ": " << HashTable[i]->name;
        Item *temp = new Item();
        temp = HashTable[i];
        while(temp->next != NULL) {
            temp = temp->next;
            cout << " -> " << temp->name;   
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}
