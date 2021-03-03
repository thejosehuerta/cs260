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
    //If this position in the table is empty, then insert here
    if(HashTable[index]->name == "") {
        HashTable[index]->name =  name;
        cout << "'" << HashTable[index]->name << "'" << " added to index " << index << "!" << endl;
    }
    else if(HashTable[index]->name == name)  {
        cout << "'" << HashTable[index]->name << "'" << " already exists! Item not added." << endl;
        return;
    } else {
        Item *new_item = new Item;
        new_item->name = name;

        new_item->next = HashTable[index];
        HashTable[index] = new_item;

        cout << "listd" << endl;
        cout << HashTable[index]->name << endl;

        Item *test = new Item();
        test = HashTable[index]->next;
        cout << "test->name: " << test->name << endl;

        

        
    }
}