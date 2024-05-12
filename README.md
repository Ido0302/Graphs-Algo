# Exe1 - Graphs - (Classes and Namespaces)

Graph: graph consists of 2 files: 
1. Graph.hpp - contains the declaraiton of class "graph", the members of the class(adjacency matrix, count of vertices and edges and boolean variable to define if graph is direct or not) and the declaration of the methods in class.  
2. Graph.cpp - contains the implements of the methods in graph.hpp 
The methods are:
a. loadgraph - get matrix and update the members according the matrix.
b. edges - count the edges in graph.
c. isSymmetric - check if the matrix is symmetric.
d. printgraph - display the graph(print the count of vertices, of edges and if direct\undirect)
e. printMat - print the adjency matrix of the graph

Algorithms: algorithms include 2 files:
1. Algorithms.hpp - define the namespace "Algorithms" which include const varriables, and statements of methods.
2. Algorithms.cpp - include the implements of all methods in namespace "Algorithms":
a.1 isConnected - get graph and return if it's connected strong or not.
    The function use BFS(a.2) algorithms on the graph and check if all the vertices painted.
    If the graph is direct - perform BFS on all vertices. if undirect - on one vertex.

b.1 shortestPath - the function get graph, source vertex and destination vertex and return string of
    shortest path between them if exist or "-1" if does not exist path.
    The function throw exception if the graph contains negative cycle. 
    The function use Bellman-Ford algorithms(b.2)- becuase negative weights are possible- which perform relax(b.3) on all edges in graph n-1 times and save the path(in vector) each time. 
    Finally the function print the graph with printGraph(b.4) function who get vector of path and return string of path.

c.1 isContainsCycle - the function get graph and return true if exist cycle or false if not.
    The function pass on all vertices in graph and perform recursivy function dfs(c.2) like original "DFS" (but not same) and stop when founded circle.
    In dfs, The function "paint" each vertex who visited with vector namely "color", and save the previous vertex with verctor namely "path".If the vertex already painted so it's a cycle
    If exist circle the function print the circle with printCicle(c.3) function. 

d.1 isBipartite - The function get graph. If the graph is bipartite, return string of the division of.
    graph to two groups, or "0" if isn't bipartite.
    The function pass on all edges of graph, mark vertices we visited them with "visited" vector and use whichGroup(d.2) function to distribute the vertices to groups 'A' or 'B' with "team" vector.
    Finally, if were not "accidents" of vertices of edge in same group(print "0"), the function print the distribution with printGroups(d.3) function. 
    
e.1 negativeCycle - The function get graph and check if exist negative function in the graph.
    The function call function isNegativeCircle(e.2) which use "Bellman-Ford" algorithms and do relax n-1 times on the graph.
    After that the function do another relax to check if one of the edge was change.
    If changed, the function use the vertex of the edge and use vector "path" from the bellman-ford algorithm and print the circle.
    If did not change print nessege and return false.