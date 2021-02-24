#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include "BST.h"

using std::string;
using std::cout;
using std::endl;
using std::queue;

//Construct a Binary Search Tree
BST::BST() {
    root = NULL;
}

//--------------------------------------------------
//This function will create and return new node and insert it in your tree based on the criteria
Node *BST::Insert(Node *new_node, int data) {
    /* if tree is empty/non-existant, a new node is created as root.
    if tree already contains elements, a new node will be created and placed
    in the appropriate location via recursion */
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
//Insert an element into your binary search tree recursively based on criteria
void BST::Insert(int data) {
    //Update root
    root = Insert(root, data);
}

//--------------------------------------------------
//Function to find the minimum value in tree/sub-tree
Node *BST::FindMin(Node *node) {
    while(node->left != NULL) {
        node = node->left;
    }
    return node;
} 
//FindMin function invoked and root is used as argument to return smallest value as an int
int BST::FindMin() {
    Node *temp = FindMin(root);
    return temp->data;
}

//--------------------------------------------------
//This function searches for the value to be deleted and returns its node
Node *BST::Delete(Node *node, int data) {
    //if tree is empty
    if(node == NULL) 
        return node;
    /*if data is less than the current node's data (but not equal to), recursively 
    call Delete function to traverse through tree until node with value is found */
    else if(data < node->data) 
        node->left = Delete(node->left, data);
    /*if data is greater than the current node's data (but not equal to), recursively 
    call Delete function to traverse through tree until node with value is found */
    else if(data > node->data) 
        node->right = Delete(node->right, data);
    /*if data is equal to the current node's data, then the value is found.
    At this point, each case is checked and the value is deleted. */
    else {
        // Case 1:  Deleting a leaf node with no children
		if(node->left == NULL && node->right == NULL) { 
			delete node;
			node = NULL;
		}
		//Case 2: Deleting a node with one child 
        //if left child is NULL
		else if(node->left == NULL) {
			Node *temp = node;
			node = node->right;
			delete temp;
		}
        //if right child is NULL
		else if(node->right == NULL) {
			Node *temp = node;
			node = node->left;
			delete temp;
		}
		// case 3: Deleting a node with two children
		else { 
			Node *temp = FindMin(node->right);
			node->data = temp->data;
			node->right = Delete(node->right, temp->data);
		}
	}
	return node;
}
//
void BST::Delete(int data) {
    root = Delete(root, data);
}



//--------------------------------------------------
//Function to print the tree in "Pre-order" traversal
void BST::PrintPreOrder(Node *node) {
    //return if no node is found i.e. tree/sub-tree is empty
    if(node == NULL) return;
    //Print data
    cout << node->data << " ";
    //visit left sub-tree
    PrintPreOrder(node->left);
    //visit right sub-tree
    PrintPreOrder(node->right);
}
//Invoke the PrintPreOrder function and use the root as the argument
void BST::PrintPreOrder() {
    //Start at the root
    PrintPreOrder(root);
    cout << endl;
}

//--------------------------------------------------
//Function to print the tree in "in-order" traversal
void BST::PrintInOrder(Node *node) {
    //return if no node is found i.e. tree/sub-tree is empty
    if(node == NULL) return;
    //visit left sub-tree
    PrintInOrder(node->left);
    //Print data
    cout << node->data << " ";
    //visit right sub-tree
    PrintInOrder(node->right);

}
//Invoke the PrintInOrder function and use the root as the argument
void BST::PrintInOrder() {
    //Start at the root
    PrintInOrder(root);
    cout << endl;
}

//--------------------------------------------------
//Function to print the tree in "in-order" traversal
void BST::PrintPostOrder(Node *node) {
    //return if no node is found i.e. tree/sub-tree is empty
    if(node == NULL) return;
    //visit left sub-tree
    PrintPostOrder(node->left);
    //visit right sub-tree
    PrintPostOrder(node->right);
    //Print data
    cout << node->data << " ";
}
//Invoke the PrintInOrder function and use the root as the argument
void BST::PrintPostOrder() {
    //Start at the root
    PrintPostOrder(root);
    cout << endl;
}

void BST::PrintLevelOrder(Node *node) {
    if(node == NULL) return;
	queue <Node*> Q;
	Q.push(node);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node *current = Q.front();
		Q.pop(); // removing the element at front
		cout << current->data << " ";
		if(current->left != NULL) 
            Q.push(current->left);
		if(current->right != NULL) 
            Q.push(current->right);  
	}
}

void BST::PrintLevelOrder() {
    PrintLevelOrder(root);
    cout << endl;
}