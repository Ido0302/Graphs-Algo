//ID: 207826694
//GMAIL: didooron@gmail.com


#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

namespace ariel{

    namespace Algorithms{

        #define infinity 2147483647// max value for integer
        #define white 1
        #define gray 2
        #define black 3

        bool isConnected(Graph &g);
        void bfs(Graph &g, size_t s, vector<int>& visit, vector<int>& colors);

        string shortestPath(Graph &g, size_t start, size_t end);
        void bellmanFord(Graph &g, int s, vector<int>& d, vector<int>& p);
        void relax(vector<int>& d, vector<int>& p, size_t i, size_t j, int w);
        string printPath(vector<int> path, size_t start, size_t end);

        bool isContainsCycle(Graph &g);
        bool dfs(Graph &g, vector<int> color, vector<int> path, size_t v);
        void printCircle(vector<int> path, size_t s, size_t end);

        string isBipartite(Graph &g);
        bool whichGroup(size_t i, size_t j, vector<bool>& visit, vector<char>& team);
        string printGroups(vector<char> group);


        bool negativeCycle(Graph& g);





    };
};

#endif