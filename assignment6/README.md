### Jose Huerta
#### CS 260 - Assignment 6: Binary Search Tree (BST)
##### Completed with the help of [mycodeschool.com](http://www.mycodeschool.com/work-outs/binary-search-trees)
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
### 1.  Tests
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

Creating a node to store values is as simple as creating a "Node" struct and having it be composed of an *int to store our data, pointer to left Node, and pointer to right Node*.
> ***An add function that adds a new value in the appropriate location based on ordering rules***

For this function, I called it Insert() and I made sure it followed the rule of ordering (less than or equal values go to left sub-tree, greater values go to right sub-tree). Then, it recursively calls itself until it finds where it belongs. 
> ***A remove function that finds and removes a value and then picks an appropriate replacement node***

For this function, I called it Delete() and first, similarly to the Insert() function, it recursively calls itself until the value it is searching for is found. Then, it passes one of the three cases stated in **step 1:**<br>
   1. ***The node we are trying to delete is a leaf node and has no children***
      + Simply enough, we just unlink the node we wish to delete from its root node and deallocate it from memory.
   2. ***The node we are trying to delete has one child, either in the left side or the right side***
      + In this case, a temporary node is created that points to the root node. Then the root node is pointed to either its left or right element (depending on           which one is NULL), then the temp pointer is deleted. Basically, it finds the node its meant to delete, fixes the links by unlinking itself and linking           its child to its root node, then the correct node is deleted.
   3. ***The node we are trying to delete has two children***
      + This case is a little trickier. A new function is created, called FindMin() that finds the minimum value in a sub-tree. In order to delete a node with           two children, the FindMin() function is utilized to find the minimum value of its right sub-tree and that value will replace the node we wish to delete.         Next, at this point we would have duplicate nodes (the replaced node and the original node). We use the logic from **case 2** described above to delete           the original node and then we're good. 
> ***At least one tree traversal function***
 
For this function, or I should say for these four functions, I applied the three common traversal methods (pre/in/post-order) and the level order traversal method.<br>
***For the three common traversals:***<br>
They were as simple as printing the node's data value, then either recursively traversing to the left, and right nodes. This obviously varied depending on what method of traversing was being applied.<br>
***For the level order function:***<br>
I used a video posted by [mycodeschool](https://www.youtube.com/watch?v=86g8jAQug04&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=33&ab_channel=mycodeschool)
that utilized queue logic to print the tree's elements in a level order manner.
### 3. Time Complexity
