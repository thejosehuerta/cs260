#include <stdio.h>
#include <iostream>
#include <string>
#include "BST.h"

using std::string;
using std::cout;
using std::endl;

//Construct a Binary Search Tree
BST::BST() {
    root = NULL;
}

//Insert an element into your binary search tree recursively based on criteria
Node *BST::Insert(Node *new_node, int data) {
    /* if tree is empty/non-existant, a new node is created as root.
    if tree already contains elements, a new node will be created and placed
    in the appropriate location */
    if(new_node == NULL) {
        new_node = new Node();
        new_node->data = data;
        new_node->left = new_node ->right = NULL;
    }
    /*if "data" is less than or equal to the data in the root/previous node's
    data, then insert in the left subtree */
    else if(data <= new_node->data) {
        new_node->left = Insert(new_node->left, data);
    } else {
        //else, insert in the right subtree
        new_node->right = Insert(new_node->right, data);
    }
    return new_node;
}

void BST::Insert(int data) {
    root = Insert(root, data);
}

//Function to print the tree in "in-order" traversal
void BST::InOrderPrint(Node *node) {
    //return if no node is found
    if(node == NULL) {
        return;
    }

    //
    InOrderPrint(node->left);

    //Print data
    cout << node->data << " ";

    //
    InOrderPrint(node->right);

}

void BST::InOrderPrint() {
    //Start at the root
    InOrderPrint(root);
    cout << endl;
}
