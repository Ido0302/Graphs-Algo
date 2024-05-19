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
    int countOfEdges;
    bool isDirect;

    Graph();

    //Part 1
    void loadGraph(vector<vector<int>> &g);
    void printGraphDescription();
    int edges();
    bool isMatrixSymetric();

    string printGraph();

    //Part 2
    friend std::ostream& operator<<(std::ostream& os, const Graph& g);

    Graph operator+(const Graph& other);
    Graph operator-(const Graph& other);
    Graph operator*(const Graph &other);
    int mul(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, size_t raw, size_t col);


    Graph& operator+=(const Graph& other);
    Graph& operator-=(const Graph& other);

    Graph& operator+(); //unary plus  
    Graph& operator-(); //unary minus 
    Graph& operator*=(const int num);

    Graph& operator++(); //(prefix)
    Graph operator++(int); //(postfix)
    Graph& operator--(); //(prefix)
    Graph operator--(int); //(postfix)

    bool operator==(const Graph& other);
    bool operator!=(const Graph& other);

    bool operator<(const Graph& other);
    bool operator<=(const Graph& other);
    bool operator>(const Graph& other);
    bool operator>=(const Graph& other);










 };

};
#endif