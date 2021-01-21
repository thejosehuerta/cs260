### Jose Huerta 
CS 260 -
Assignment 2

---
#### 1.  Based on what we know about linked lists, stacks, and queues, design a queue data structure:
    a.  What functions are we likely to need for a queue?
    
        Similar to a stack, we would need a peek function (gets the front element without removing it), an 
        isfull function (checks to see if the queue is full), and an isempty function (checks to see if the queue 
        is empty). Furthermore, we would also need an enqueue function that adds an item to the queue, and a dequeue 
        function that removes an item from the queue.
    
    b.  What values will we need to know about the structure for our queue to function properly?
    
        A queue data structure is open at both ends where one end is always used to insert data, and the 
        other is used to remove data. There are two main functions in queues: enqueue (inserts data) and 
        dequeue (removes data). In order for our queue to function properly, we would need front and rear values
        (or more specifically, pointers) to point to the next empty space to add data or point to the front of the
        queue in order to remove it.   
![queue example][queue]

[queue]: https://github.com/thejosehuerta/cs260/blob/main/assignment2/images/queue_example.jpg?raw=true

[Source](https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm)

---
#### 2.  Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):
    a.  What functions are we likely to need for a list to function like this?
    
        Some functions needed for a linked list include an insertion function, a deletion function, a display
        function (displays the complete list), a search function (searches for a specific element), and a 
        delete function.
    
    b.  What values will we need to know about the structure for our list to function properly?
    
        In order to create a properly functioning linked list, we will first need to visualize a linked list as a chain of nodes 
        where every node points to the next node. Every link carries data and a link field called next that links to
        the next link. This continues until the last link which points to null to mark the end of the list. 
        in order to add values at a given location, we need to point the new node's next field to the exisiting node it will 
        precede (the right node). Then, the node that is on the left side of our new node, will need its next value
        to point to the new node. 
        
#### Linked List insert example. 
![linked list example][linkedlist]

[Source](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)

[linkedlist]: https://github.com/thejosehuerta/cs260/blob/main/assignment2/images/linkedlist.jpg?raw=true












