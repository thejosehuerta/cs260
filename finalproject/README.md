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
### 0.5 How It Works
I tried to make it a seamless experience before letting the user take over. First, the user is prompted to create a name for a new state since {some random USA state} was unexplicably destroyed. Then the user is asked how many cities they would want in their new state. This number is essentially the number of vertices (how big the graph is gonna be) in the graph. The program asks for at least two because two cities will be created, then connected (via an edge) by the user. Think of the beginning of the program like a tutorial. The user will be asked for a numerical value that will be the distance in miles between the two cities. After all of this, the user should have a good idea of how the program works and will be free to choose what to do next via a text interface composed with a switch statement (Joseph's favorite 🥳). The user will then be able to create new cities (no duplicates), and create connections (edges) between them. 
### 1.  Tests
Per the requirements of the assignment, we know we will need to test at least four different functions:
1. A function that adds a new vertext to the graph.
   * For this function 
