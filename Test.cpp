//ID: 207826694
//GMAIL: didooron@gmail.com

//Clarifications:
//All graph who presented by simmetric matrix is undirected graph.
//Connected consider as "strong" connected. It's means that possible to arrive any vertex from any vertex
//If exists atleast two different vertices in path between vertex to himself, is a cycle. For exampla: 0->1->0 is a cycle. 0->0 isn't a cycle


#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel::Algorithms;


//Tests were exist before 

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g; 
    vector<vector<int>> graph = { 
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}


TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}


TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
    
}


//Test I added myself

TEST_CASE("Undirected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == true);
    CHECK(shortestPath(g, 0, 2) == "0->1->2");
    CHECK(isContainsCycle(g) == true);
    CHECK(isBipartite(g) == "0");
    //CHECK(negativeCycle(g) == "0");
}

TEST_CASE("Directed graph without weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == false);
    CHECK(shortestPath(g, 0, 2) == "0->2");
    CHECK(isContainsCycle(g) == false);
    CHECK(isBipartite(g) == "0");
    //CHECK(negativeCycle(g) == "0");
}

TEST_CASE("Directed Graph with non-negative weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 3, 0, 6},
        {0, 0, 4, 1},
        {8, 0, 0, 0},
        {0, 0, 2, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == true);
    CHECK(shortestPath(g, 0, 2) == "0->1->3->2");
    CHECK(isContainsCycle(g) == true);
    CHECK(isBipartite(g) == "0");
    //CHECK(negativeCycle(g) == "0");
}

TEST_CASE("Directed Graph with negative weights without negative cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -6, 0, -8},
        {0, 0, 4, 0},
        {0, -2, 0, 0},
        {10, 0, 3, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == false);
    CHECK(shortestPath(g, 0, 2) == "0->3->2");
    CHECK(isContainsCycle(g) == true);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
    //CHECK(negativeCycle(g) == "0");
}

TEST_CASE("Directed Graph with negative cycle")
{
    
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -6, 0, -8},
        {0, 0, 4, 0},
        {0, -2, 0, 0},
        {10, 0, 3, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == false);
    CHECK(shortestPath(g, 0, 2) == "0->3->2");
    CHECK(isContainsCycle(g) == true);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
    //CHECK(negativeCycle(g) == "0");
    
}


TEST_CASE("Forest with two trees")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -1, 0, 0},
        {-1, 0, 0, 0},
        {0, 0, 0, -1},
        {0, 0, -1, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == false);
    CHECK(shortestPath(g, 0, 2) == "-1");
    CHECK(isContainsCycle(g) == true);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
    //CHECK(negativeCycle(g) == "0");
}



TEST_CASE("Test throw exceptins")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
    {0,-3,0},
    {0,0,-5},
    {-7,0,0}};
    g.loadGraph(graph);
    //CHECK_THROWS(shortestPath(g,0,2));

    vector<vector<int>> graph2 = {{0}};
    g.loadGraph(graph2);
    CHECK_THROWS(shortestPath(g,0,0));
    
}


