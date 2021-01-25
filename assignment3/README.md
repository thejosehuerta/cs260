### Jose Huerta
#### CS 260 - Assignment 3
##### Designed with the help of mycodeschool: [Linked List implementation of Queue](https://www.youtube.com/watch?v=A5_XdiK4J8A&ab_channel=mycodeschool)
---
A queue is a list or collection with the restriction that insertion can be performed at one end (usually the rear), and the deletion is performed at the other end (the front).

#### Operations/functions in a queue:
1.  Enqueue(x)
    * This function takes an int as a parameter and will be responsible for inserting said parameter to the rear of the queue.
2.  Dequeue()
    * This function will dequeue/delete the value that is in the front of a queue.
3.  isEmpty()
    * This function will simply check if the queue is empty or not. 
4.  Front()
    * This function will return the value that is at the front of the queue.
5.  Print()
    * This function prints all elements that are currently in the queue.
    
#### Time Complexity:
All operations stated above (except for Print) will run at constant time or O(1). This is because insertion is always perfromed at the rear, deletion is always performed at the front, the queue is always either empty or not, and (assuming the queue is not empty) there is always a value in the front. 
Moreover, the print function will be O(n) because its time complexity will always depend on the number of elements present in the queue.  
