//ID: 207826694
//GMAIL: didooron@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{

class Graph{
    public:
    vector<vector<int>> adjacencyMatrix;
    int countOfVer;
    int countOfEdge;
    bool isDirect;

    Graph();

    void loadGraph(vector<vector<int>> &g);
    void printGraph();
    
    int edges();
    bool isMatrixSymetric();
    void printMat(vector<vector<int>> mat);

 };

};
#endif