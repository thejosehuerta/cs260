### Jose Huerta
#### CS 260 - Assignment 6: Binary Search Tree (BST)
---
For this assignment, our duty was to complete three tasks:
1.  Create some tests for our BST to pass before coding.
2.  Implement a binary search tree that includes:
    * Nodes to store values
    * An add function that adds a new value in the appropriate location based on ordering rules
    * A remove function that finds and removes a value and then picks an appropriate replacement node
    * At least one tree traversal function
3. Analyze and compare the complexity of functions, including the difference between binary search trees that are ordered and unordered.
---
### 1.  Create some tests for our BST to pass before coding
For a binary search tree, and for our assignment, we know we will need a **function to insert a value to the appropriate place**, a **function to
delete a specific value from the tree** and a **function to traverse the tree and print the tree's elements**.
#### Insert Function:
* For the Insert function, when inserting an element into the tree, we want to follow the ordering rule of ***any element less than or equal to the root's value will go to the left side***, and ***any element greater than the root's value will go to the right side***. We want to make sure this aspect of the tree is working before doing anything else as it is the foundation of our binary search tree.
#### Delete Function:
* For the Delete function, we will need to check for three cases for our function to pass:
   1. The node we are trying to delete is a leaf node and has no children.
   2. The node we are trying to delete has one child, either in the left side or the right side. 
   3. The node we are trying to delete has two children.
#### Traverse Function:
* For this function, we need to make sure our BST is sorted, i.e. the Insert function is working properly, first. Then we need to implement at least one of the common traversal methods (e.g. pre-order, in-order, etc.) in this function. 
### 2. Implementation
> ***Nodes to store values***

Creating a node to store values is as simple as creating a "Node" struct and having it be composed of an *int, pointer to left Node, and pointer to right Node*.
