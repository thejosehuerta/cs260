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
#### 1.  Create some tests for our BST to pass before coding.
For a binary search tree, and for our assignment, we know we will need a **function to insert a value to the appropriate place**, a **function to
delete a specific value from the tree** and a **function to traverse the tree and print the tree's elements**.<br>
**Insert Function:**
* For the Insert() function, we want to create a root node and have the function follow the ordering rule of ***any element less than or equal to the root's value will
go to the left side***, and ***any element greater than the root's value will go to the right side***.
