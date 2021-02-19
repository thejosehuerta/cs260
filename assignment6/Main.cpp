#include <iostream>
#include <stdio.h>
#include "BST.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char **argv) {
    BST *tree = new BST();

    tree->Insert(40);
    tree->Insert(25);
    tree->Insert(10);
    tree->Insert(32);
    tree->Insert(78);

    tree->InOrderPrint();
    return 0;
}