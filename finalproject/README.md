### Jose Huerta
#### CS 260 - Final Project: Graph
---
For our final project, our duty was to complete three main tasks:
1.  Create some tests before you start coding.
2.  Implement a graph class with at least:
    * a function to add a new vertex to the graph (perhaps add_vertex(vertex_name))
    * a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination))
    * a function for a shortest path algorithm (perhaps shortest_path(source, destination))
    * a function for a minimum spanning tree algorithm (example min_span_tree()).
3.  Analyze the complexity of all of your graph behaviors.
---
### 0.  Introduction & My Idea
To save any potential confusion this program might produce, I will start by saying it is unfinished. I believe I created a strong foundation and the only thing I needed to complete it was time. I successfully created a function that added vertices to the graph, and another function that created an edge between them. Unfortunately, I did not get to the shortest path and minimum spanning tree algorithms. With that out of the way, let me discuss the idea I had for this program.<br>
I wanted to create an interactive city creator (I would call it a game, but games are usually fun 🐷) where vertices in the program would be cities and the edges would be the distance between them via a highway. The user would be able to create a multiple cities and create connections between them. Then, they would be able to find the shortest path between them, and also be able to utilize the minimum spanning tree algorithm.
<br>
I was successful with all of this except implementing the algorithms. It's still not perfect, and I imagine you could break it if you really tried, but it works the way I hoped it would. 

---
### 0.5. How It Works
I tried to make it a seamless experience before letting the user take over. First, the user is prompted to create a name for a new state since {some random USA state} was unexplicably destroyed. Then the user is asked how many cities they would want in their new state. This number is essentially the number of vertices (how big the graph is gonna be) in the graph. The program asks for at least two because two cities will be created, then connected (via an edge) by the user. Think of the beginning of the program like a tutorial. The user will be asked for a numerical value that will be the distance in miles between the two cities. After all of this, the user should have a good idea of how the program works and will be free to choose what to do next via a text interface composed with a switch statement (Joseph's favorite 🥳). The user will then be able to create new cities (no duplicates), and create connections (edges) between them. There also exists other functions like being able to print all the elements in the graph and their connections.

---
### 1.  Tests
Because I only completed two of the four functions I was assigned to do, I will explain them and their tests:
1. A function that adds a new vertext to the graph.
   * For this function, since I wanted my vertices to be cities, I knew that I wanted every city to be unique and to be created by the user. If a city already        exists in the graph, then no new vertex would be created, else create a new city vertex.
2. A function that adds an adge between two vertices.
   * For this function, I wanted to be able to create an undirected connection between two different cities. First, I wanted to make sure the start and end of        the connection (the cities) actually existed before creating a connection between them. Then, we'd want to check whether or not a specific connection has        alread been established.
   * 
---
### 2.  Implementing a Graph With These Functions
1.  **AddNode(string name);**
    * This function takes a string and creates a new node (vertex/city) with that string. There exists a set that contains every city as it is added and only           unique values are allowed. Every time a new city wishes to be created, it checks its name with the set to make sure it doesn't already exist. If it               doesn't, then a new node is created. Every node has a city which by definition (in this program) is a pair of two elements: a string (its name), and an int       (its ID). Every new city has a unique ID that is produced from a simple counter that starts at 0 and goes up by one as a new city is created. Thid ID also       acts as its index in the graph's adgacency list. This proves useful In the next function.
2. **AddEdge(string start, string end, int dist);**
   * This function takes two strings and an int. The first two strings (start and end) are the names of the cities the user wishes to connect. The int (dist)          will be the distance (in miles) that will be between them. After making sure the cities exist, the cities will be connected a la linked list from the            adjacency list. This connection is not made by the city's names, however. Utilizing the map template, we can find the ID of a city by searching for it using      its name value. This find() function will return it's ID value, which is also its index value in the adjacency list. Subsequently, we are able to create a        connection using pointers a la linked list. 

---
### 3.   Time Complexity
As for the time complexity, I feel like it could've been more effecient, but it also could've been worse.
1.  AddNode(); - **O(n) Worst Case**
    * While creating and inserting a new city into the graph is O(1), it will always check to see if this city already exists in the set before creating and           inseting a city.
2.  AddEdge(); - **O(n) Worst Case**
    * Every new city that is created and inserted into the adjacency list a la linked list, will always be added to the end of the list. It always has to               traverse through all the elements in the list in order to get to the end.
