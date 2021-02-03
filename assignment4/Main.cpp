#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    LinkedList *my_linkedlist = new LinkedList();

    my_linkedlist->Insert(6,1);
    my_linkedlist->Insert(5,2);
    my_linkedlist->Insert(2,1);
    my_linkedlist->Insert(4,2);

    my_linkedlist->Print();

    int value;
    cout << "\nEnter a position" << endl;
    cin >> value;

    //my_linkedlist->Remove(value);
    cout << my_linkedlist->Retrieve(value) << endl;

    my_linkedlist->Print();

    return 0;
}