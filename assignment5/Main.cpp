#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::isdigit;


//Main
int main(int argc, char **argv) {
    //new linked list is created!
    LinkedList *my_linkedlist = new LinkedList();
    my_linkedlist->Insert(5);
    my_linkedlist->Print();

    my_linkedlist->Insert(3);
    my_linkedlist->Print();
   
    my_linkedlist->Insert(1);
    my_linkedlist->Print();
    
    my_linkedlist->Insert(4);
    my_linkedlist->Print();
    
    my_linkedlist->Insert(10);
    my_linkedlist->Print();

    my_linkedlist->Insert(8);
    my_linkedlist->Print();

    my_linkedlist->Insert(-1);
    my_linkedlist->Print();
    return 0;
}