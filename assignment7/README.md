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
    + We need to make sure this calculation makes sense and is consistent for it is the foundation for the rest of the program.
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
After initially creating a hash table that overwrote its old values with new ones, I went ahead and started making it smarter. I created and tested the functions 
stated above as follows:
1. **int HashValue(string name);**
   * This function takes a string and calculates its hash value from said string.<br>
      Let's say you want to insert the value "rat". First it adds up the ASCII values
      of the string: r = 114 + a = 97 + t = 116 (sum of 327), mods it by the table size, and returns that value as the index for the hash table. In this case, it
      is 327 % table_size (which is initially 10, but can be changed), and the result is 7. The index for "rat" would then be 7.
2. **void Insert(string name);**
   * This function takes a string, uses the HashValue() function to get its hash value, and inserts the string into the correct index in the hash table.<br>
     In order to handle collisions, I decided to chain values together a la linked list. In order to keep the time complexity for this function at O(1), I            decided to always insert new values at the head of an index. 
3. **void Contains(string name);**
   * This function takes a string, gets its index value aka its hash value, and searches for it in the table.<br>
     This function checks for three cases:
     1. The value is the only one in the index. It does this by checking if its "next" pointer is NULL.
     2. The value is at the head of the index. It does this if it skips the first case, but the value is still a match.
     3. The value's hash value exists but is not at the head of the index. At this point, it knows it needs to traverse through the exisiting linked list to 
        try and find the value. There could still be a chance it doesn't find it (in the case that the hash value exists but the value does not). At this                 point, if it skips through all cases, it does not exist in the table. 
4. **void Delete(string name);**
   * This function takes a string, calculates its index value, finds it in the table, then deletes it.<br>
     This function checks for a number of cases:
     1.  If there is nothing in the index, it does not exist and nothing is deleted.
     2.  If the values match, and its "next" pointer is NULL, then it is the only element in the index and is deleted.
     3.  If the values match, but it skipped the previous case, then it is at the head of the index and is deleted.
     4.  If the hash value matches, but its value does not match the head of the index, then it is somewhere in the index's list.
         + If the entire list is traversed and it is not found, then it does not exist in the index and therefore not found in the table. Nothing was deleted.
         + If the list is traversed and it is found then it is deleted. It might be found somewhere in the middle of the list, or at the end of the list.
           Either way, the value is deleted and the links are fixed.
5. **void PrintTable();**
   * This function traverses through the entire list, including its chained values, and prints them out in a readable manner.<brk>
     This function was created to simply not only create a way for us humans to read the data, but to also make sure the other functions are working properly.
---
### 4. Time Complexity
For the time complexity in this program, the Contains(), and Delete() functions are nearly identical. Both share a time complexity of O(n) as its worst case
as it would have to traverse through an entire linked list to find a value. For the Insert() function, its time complexity is O(1) as I decided to always insert
values at the head of every index. Lastly, for the PrintTable() function, its time complexity is O(n), as it will always have to traverse through not just every index in the list, but also every index's contents.
  
