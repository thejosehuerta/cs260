### Jose Huerta
#### CS 260 - Assignment 7: Hash Table
---
For this assignment, our duty was to complete four main tasks:
1.  Create some tests that you want your hashtable to pass before you start coding.
2.  Create a hashtable that resolves collisions by simply overwriting the old value with the new value, including at least:
    * Describe the way that you decide on hashing a value
    * An insert function that places the value at the appropriate location based on its hash value
    * A contains function that returns whether the value is already in the hashtable
    * (optional) A delete function that removes a value based on its hash and then returns that value…
3.  Then create a smarter hashtable (double hashing or chaining) including at least the same functions as the simple hashtable
4.  Compare some information relating to collisions (frequency) and their effect on complexity (of insert and contains methods)
---
### 1.  Tests
Per the requirements of this assignment, we know we will need to test at least four different functions:
1.  Some Hash function that takes a value and calculates its hash value.
    + We need to make sure this calculation makes sense and is consistent for its the foundation for the rest of the program.
2.  An Insert function that inserts a value into the hash table based on its hash value.
    + Apart from inserting a value correctly, we need a way to handle collisions. 
3.  A Contains function that searches for a value and returns whether or not said value exists in the table.
    + For this function, we need make sure we're able to find values that have "collided" with other values. In the case of chaining values a la linked list,
      we need to handle two cases:
        * Finding a value at the head of the linked list
        * Finding a value somewhere in the linked list
4.  A Delete function that finds and deletes a value.
    + Similar to the Contains function, we need to find a value depending on how we decided to handle collisions. In the case of utilizing a linked list,
      we'd need to be able to handle three cases:
      * Deleting at the head of the list
      * Deleting somewhere in the list
      * Deleting at the end of the list
---
### 2 & 3.  Creating a Functional Hash Table
test
