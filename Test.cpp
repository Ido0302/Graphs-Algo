//ID: 207826694
//GMAIL: didooron@gmail.com

//Notes:
//All graph who presented by simmetric matrix is undirected graph.
//Connected consider as "strong" connected. It's means that possible to arrive any vertex from any vertex
//If exists atleast two different vertices in path between vertex to himself, is a cycle. For exampla: 0->1->0 is a cycle. 0->0 isn't a cycle


#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel::Algorithms;
using namespace ariel;


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



//Tests I added myself!

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
    CHECK(isContainsCycle(g) == true); //"0->1->0"
    CHECK(isBipartite(g) == "0");
    CHECK(negativeCycle(g) == false); //"No negative cycle"
    cout << "*****************" << endl;
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
    CHECK(isContainsCycle(g) == false); //"No cycle"
    CHECK(isBipartite(g) == "0");
    CHECK(negativeCycle(g) == false); //"No negative cycle"
    cout << "*****************" << endl;

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
    CHECK(isContainsCycle(g) == true); //"0->1->2->0"
    CHECK(isBipartite(g) == "0");
    CHECK(negativeCycle(g) == false); //"No negative cycle"
    cout << "*****************" << endl;

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
    CHECK(isContainsCycle(g) == true); //"2->1->2"
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
    CHECK(negativeCycle(g) == false); //"No negative cycle"
    cout << "*****************" << endl;

}


TEST_CASE("Directed Graph with negative cycle")
{
    
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0, 0},
        {0, 0, 4, 0},
        {0, 0, 0, 6},
        {8, -12, 0, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == true);
    CHECK_THROWS(shortestPath(g,0,2)); //has negative circle
    CHECK(isContainsCycle(g) == true); //"0->1->2->3->0"
    CHECK(isBipartite(g) == "0"); 
    CHECK(negativeCycle(g) == true); //"1->2->3->1"
    cout << "*****************" << endl;



}


TEST_CASE("Forest with two trees")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -1, 0, 0},
        {-1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(isConnected(g) == false);
    CHECK_THROWS(shortestPath(g,0,2)); //has negative circle
    CHECK(isContainsCycle(g) == true); //"0->1->0"
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
    CHECK(negativeCycle(g) == true); //"0->1->0"
    cout << "*****************" << endl;

}



TEST_CASE("Test throw exceptins")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
    {0,-3,0},
    {0,0,-5},
    {-7,0,0}};
    g.loadGraph(graph);
    CHECK_THROWS(shortestPath(g,0,2));

    vector<vector<int>> graph2 = {{0}};
    g.loadGraph(graph2);
    CHECK_THROWS(shortestPath(g,0,0));

    vector<vector<int>> graph3 = {
    {0, 1, 0},
    {1, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph3));
    
}
//**********************************


//Tests Part 2

TEST_CASE("Test graph addition and subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    string ans = g3.printGraph();
    CHECK(ans == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    g3 -= g2;
    CHECK(g3.printGraph()==g1.printGraph());

    vector<vector<int>> graph4 = {
        {0, 1, 0, 3},
        {1, 0, 4, 0},
        {0, 4, 0, -2},
        {3, 0, -2, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph4);

    vector<vector<int>> graph5 = {
        {0, 1, -1, -5},
        {1, 0, -3, 1},
        {-1, -3, 0, 2},
        {-5, 1, 2, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph5);

    vector<vector<int>> weightedGraph2 = {
        {0, 2, -1, -2},
        {2, 0, 1, 1},
        {-1, 1, 0, 0},
        {-2, 1, 0, 0}};
    ariel::Graph g6;
    g6.loadGraph(weightedGraph2);
    g4+=g5;
    CHECK(g4.printGraph()==g6.printGraph());

    g5 = g6 - g4;
    CHECK(g5.printGraph()=="[0, 0, 0, 0]\n[0, 0, 0, 0]\n[0, 0, 0, 0]\n[0, 0, 0, 0]");

}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g3.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 3},
        {1, 0, 4, 0},
        {0, 4, 0, -2},
        {3, 0, -2, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph4);

    vector<vector<int>> graph5 = {
        {0, 1, -1, -5},
        {1, 0, -3, 1},
        {-1, -3, 0, 2},
        {-5, 1, 2, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph5);

    vector<vector<int>> weightedGraph2 = {
        {0, 3, 3, 1},
        {-4, 0, -1, 3},
        {14, -2, 0, 4},
        {2, 9, -3, 0}};
    ariel::Graph g6;
    g6.loadGraph(weightedGraph2);
    ariel::Graph g7 = g4 * g5;
    CHECK(g6.printGraph()==g7.printGraph());  
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));

    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Another arithmetic operation on graphs"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ++g1;
    g1++;
    g2 *= 3;
    CHECK(g1.printGraph()==g2.printGraph());

    g1--;
    --g2;
    CHECK(g1.printGraph()==g2.printGraph());


    g1*= -1;
    -g2;
    CHECK(g1.printGraph()==g2.printGraph());
}


TEST_CASE("Test compare operation on graphs"){
    bool result1, result2, result3;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); 

    //compare between matrix to herself
    result1 = g1 == g1;
    result2 = g1 != g1;
    result3 = g1 <= g1;
    CHECK(result1==true);
    CHECK(result2==false);
    CHECK(result3==true);

    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    //comapre between 3X3 matrices
    result1 = g1 < g2;
    result2 = g1 > g2;
    result3 = g1 == g2;
    CHECK(result1==true);
    CHECK(result2==false);
    CHECK(result3==false);

    vector<vector<int>> graph4 = {
        {0, 1, 0, 3},
        {1, 0, 4, 0},
        {0, 4, 0, -2},
        {3, 0, -2, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph4);

    vector<vector<int>> graph5 = {
        {0, 1, -1, -5},
        {1, 0, -3, 1},
        {-1, -3, 0, 2},
        {-5, 1, 2, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph5);

    //compare between 4X4 matrices
    result1 = g5 > g4;
    result2 = g5 >= g2;
    result3 = g4 <= g5;
    CHECK(result1==true);
    CHECK(result2==true);
    CHECK(result3==true);
    
    //compare between matrices wth different sizes
    result1 = g1 < g5;
    result2 = g2 < g4;
    result3 = g1 >= g4;
    CHECK(result1==true);
    CHECK(result2==false);
    CHECK(result3==false);

}

TEST_CASE("Operators&Algorithms"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -1, 0},
        {0, 0, -2},
        {4, 0, 0}};
    g.loadGraph(graph);
    CHECK(negativeCycle(g) == false);
    -g;
    CHECK(negativeCycle(g) == true); 

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g1.loadGraph(graph1);
    CHECK(isConnected(g1)==false);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);   

    g1+=g2;
    CHECK(isConnected(g1)==true);
}




