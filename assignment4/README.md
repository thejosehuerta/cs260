### Jose Huerta
#### CS 260 - Assignment 4
##### Designed with the help of mycodeschool: [Linked List implementation](https://www.youtube.com/watch?v=vcQIFT79_50&ab_channel=mycodeschool)
---
For this assignment, our duty was to create an array-based list or a linked-list. An outcome for this assignment was for us to begin thinking about trade-offs
we may have to weigh before using one structure over another.
I chose to do a linked-list because I believe it is more effecient at inserting data and there is no size limitation (other than memory).

#### Requirements:
The requirements for this assignment were to add three functions that can do the following:
1.  an add function that takes a value and inserts it into a given position into the list
    (example: myList.add(someValue, somePosition) )

2.  a remove function that takes a position and removes the value stored at that position of the list and returns it
    (example: myList.remove(somePosition) )

3.  a get function that takes a position and returns that value without removing it
    (example: myList.get(somePosition) )

#### Operations/functions:
The following are the functions used in my assignment: 
1.  void Insert(int data, int n);
    * This function takes two int parameters: data and n. Data is the element that will be inserted into the list, n is the position in which the 
      element will be added. Because it has the ability to add an element at any position in the list, most of the time the time complexity will be O(n). This is       because it would need to traverse the list 'n' number of times (starting at the head/beginning) in order to reach the nth position. I believe this is a decent 
    trade-off for being able to have a relatively limitless sized list.
2.  void Remove(int n);
    * This function takes one int parameter: n. this value will be the number of the position the user will enter. The function takes this number and deletes the 
      element present at that position. Because it has the ability to delete an element at any position in the list, most of the time the time complexity will be       O(n). This is because it would need to traverse the list 'n' number of times (starting at the head/beginning) in order to reach the nth position.
3.  int Retrieve(int n);
    * This function is nearly identical to the "Remove" function described above. The only difference is that it does not delete or change anything. It simply 
      returns an element at the nth position. Everything else, including time complexity is the same.
4.  void Print();
    * This function loops through the linked list 'n' number of times, printing every element until NULL is reached (the end of the list). The time complexity         for this function is always O(n) because it will always need to traverse the list in order to print out every element.
5.  int Count();
    * Similar to the "Print" function, this function loops through the linked list 'n' number of times, adding 1 to an int variable until the end of the list
      is reached. It will return the number of elements present in the list. The time complexity for this function is always O(n) because it will always need to       traverse the list in order to count every element.
