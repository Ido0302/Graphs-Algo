//ID: 207826694
//GMAIL: didooron@gmail.com

/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace ariel;

int main()
{
    
    Graph g;
    
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    g.printGraph();                  // Should print: "Graph with 3 vertices and 2 edges. The graph is directed."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "disconnected 0" (true).
    cout << "The path is: " << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << "************" << endl;



    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.
    g.printGraph();                                   // Should print: "Graph with 5 vertices and 6 edges. The graph is directed."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << "The path is: " << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;     // Should print: "The cycle is: 2-1-2   "1"".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << "************" << endl;



    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3); // Load the graph to the object.
    g.printGraph();                                  // Should print: "Graph with 5 vertices and 9 edges. The graph is directed."
    cout << Algorithms::isConnected(g) << endl;       // Should print: "0" (true).
    cout << "The path is: " << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4. //10
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0-1-0" (true).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: 0(false) "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
    cout << "************" << endl;



    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
    

/*
vector<vector<int>> graph5 = {
        {0, 7, 8, 0, 0},
        {0, 0, 0, 5, 0},
        {0, -10, 0, 2, 0},
        {0, 0, 0, 0, -1},
        {0, 0, -1, 0, 0}};
    g.loadGraph(graph5); // Load the graph to the object.
    g.printGraph();  //Graph with 5 vertices and 9 edges. The graph is directed."

    cout << g.isDirect << endl;        // Should print: "1" (true).
    cout << Algorithms::isConnected(g) << endl;      // Should print: "1" (true). 
    Algorithms::shortestPath(g,0,1);  //0-2-1 
    Algorithms::shortestPath(g,2,3);  //2-1-3
    Algorithms::shortestPath(g,0,3);  //0-2-1-3
    Algorithms::shortestPath(g,2,4);  //2-1-3-4
    Algorithms::shortestPath(g,1,0);  //-1
    cout << "************" << endl;
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->3->4->0".


    vector<vector<int>> graph6 = {
        {0,3,0,0},
        {0,0,-4,8},
        {0,0,0,-5},
        {7,-6,0,0},
        };
    g.loadGraph(graph6);   // Load the graph to the object. 
    cout << Algorithms::isConnected(g) << endl; 
    cout << Algorithms::shortestPath(g,2,1) << endl;
    cout << Algorithms::shortestPath(g,0,2) << endl;
    cout << Algorithms::isContainsCycle(g) << endl;  
    Algorithms::negativeCycle(g);
    cout << "************" << endl;
      

     vector<vector<int>> graph7 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    cout << ariel::Algorithms::isBipartite(g) << endl; // "The graph is bipartite: A={0, 2, 4}, B={1, 3}";
*/
            
   return 0;
}
