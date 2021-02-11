### Jose Huerta
#### CS 260 - Assignment 5
---
For this assignment, our duty was to create an array-based list or a linked list that:
1.  automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words)
2.  efficiently searches for elements (likely binary search for the array list, but what about the linked-list?)
---
First, I stuck with a linked-list and did not attempt an array-based list. I reused my linked-list code from [assignment 4](https://github.com/thejosehuerta/cs260/tree/main/assignment4),
and knew I had to:
1.  Update my Insert() function to always automatically insert a value in numerical order.
2.  Create a new function that searches for a specific integer.
3.  Not required, but using similar logic as the function above, delete a specific integer.

#### For my Insert() function:
All I did was add if loops and modify my pointers to basically satisfy three conditions:
If I have a list of 5 elements: 1 -> 3 -> 4 -> 5 -> 8 
1.  Insert at the head of the list when the number I want to insert is smaller than the first element in the list, i.e. inserting a '0' in the list above.
2.  Insert somewhere in the middle of the list, i.e. inserting a '6' in the list above.
3.  Insert at the end of the list, i.e. any number bigger than '8' in the list above.

#### For the Delete() and Search() functions:
I used my code from assignment 4 and modified my old functions: Remove() and Retrieve(). What I changed in a nutshell is, you enter a number you wish to delete from
the list. It does the usual checking of whether or not it's an integer, if it's in the list and so forth. Then similar to the Insert() function, it traverses through the 
list until the number is found instead of searching through the entire list.

### Time Complexity:

![BigO Chart][bigochart]

[bigochart]: https://miro.medium.com/max/2544/1*FkQzWqqIMlAHZ_xNrEPKeA.png

For the time complexity, it didn't change much compared to assignment 4. For the most part, in continues to be O(n) except for inserting/deleting at the head of the
list, which run at constant time O(1). The Delete() and Search() functions have been updgraded to search in traversal order until it finds the number in the list, but worst case scenario will end 
up being O(n).
