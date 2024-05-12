//ID: 207826694
//GMAIL: didooron@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Graph.hpp"

using namespace std;

namespace ariel{

    //construtor
    Graph::Graph(){}

    /**
     * according the matrix who get:
     * The function update the matix to be the adjency matrix of the graph
     * update the count of the vertices and edges
     * check if the graph is directed and update it
    */
    void Graph::loadGraph(vector<vector<int>> &mat){

        for (size_t i = 0; i < mat.size(); i++)
            if(mat.size()!=mat[i].size())
                __throw_invalid_argument("Invalid graph: The graph is not a square matrix.");
        
        Graph::adjencyMatrix = mat;

        Graph::countOfVer = Graph::adjencyMatrix.size();
        if(Graph::isMatrixSymetric()){
            Graph::isDirect = false;
            Graph::countOfEdge = Graph::edges()/2;
        }
        else{
            Graph::isDirect = true;
            Graph::countOfEdge = Graph::edges();
        }
    }

/**
 * the function sum the edges of graph
*/
    int Graph::edges(){
        int count = 0;
        for (size_t i = 0; i < Graph::countOfVer; i++){
            for (size_t j = 0; j < Graph::adjencyMatrix[i].size(); j++){
                if(Graph::adjencyMatrix[i][j] != 0)
                    count++;
            }            
        }
        return count;
    }

/**
 * The function check if the adjency matrix is symmetric
*/
    bool Graph::isMatrixSymetric(){
        for (size_t i = 0; i < Graph::countOfVer; i++){
            for (size_t j = i+1; j < Graph::countOfVer; j++){
                if(Graph::adjencyMatrix[i][j] != Graph::adjencyMatrix[j][i])
                    return false;
            }
        }
        return true;
    }


/**
 * The function print the graph according his characteristics
*/
    void Graph::printGraph(){
        cout << "Graph with " << Graph::countOfVer << " vertices and " << Graph::countOfEdge << " edges. "; 
        Graph::isDirect?cout<<"The graph is direct"<<endl:cout<<"The graph is undirect."<<endl;
    }

/**
 * The function print the adjency matrix
*/
    void Graph::printMat(vector<vector<int>> mat){
        for(const auto& i:mat){
            for(int j:i){
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;

    }

}