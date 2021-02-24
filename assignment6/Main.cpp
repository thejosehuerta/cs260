#include <iostream>
#include <stdio.h>
#include "BST.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char **argv) {
    BST *tree = new BST();

    tree->Insert(44);
    tree->Insert(17);
    tree->Insert(32);
    tree->Insert(78);
    tree->Insert(50);
    tree->Insert(48);
    tree->Insert(62);
    tree->Insert(88);

    tree->PrintPreOrder();
    tree->PrintInOrder();
    tree->PrintPostOrder();
    tree->PrintLevelOrder();

    cout << "min: " << tree->FindMin() << endl;


    return 0;
}