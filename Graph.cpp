// ID: 207826694
// GMAIL: didooron@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Graph.hpp"

using namespace std;

namespace ariel
{

    // construtor
    Graph::Graph() {}

    /**
     * according the matrix who get:
     * The function update the matix to be the adjacency matrix of the graph
     * update the count of the vertices and edges
     * check if the graph is directed and update it
     */
    void Graph::loadGraph(vector<vector<int>> &mat)
    {

        for (size_t i = 0; i < mat.size(); i++)
            if (mat.size() != mat[i].size())
                __throw_invalid_argument("Invalid graph: The graph is not a square matrix.");

        Graph::adjacencyMatrix = mat;

        Graph::countOfVer = Graph::adjacencyMatrix.size();
        if (Graph::isMatrixSymetric())
        {
            Graph::isDirect = false;
            Graph::countOfEdges = Graph::edges() / 2;
        }
        else
        {
            Graph::isDirect = true;
            Graph::countOfEdges = Graph::edges();
        }
    }

    /**
     * the function sum the edges of graph
     */
    int Graph::edges()
    {
        int count = 0;
        for (size_t i = 0; i < Graph::countOfVer; i++)
        {
            for (size_t j = 0; j < Graph::adjacencyMatrix[i].size(); j++)
            {
                if (Graph::adjacencyMatrix[i][j] != 0)
                    count++;
            }
        }
        return count;
    }

    /**
     * The function check if the adjacency matrix is symmetric
     */
    bool Graph::isMatrixSymetric()
    {
        for (size_t i = 0; i < Graph::countOfVer; i++)
        {
            for (size_t j = i + 1; j < Graph::countOfVer; j++)
            {
                if (Graph::adjacencyMatrix[i][j] != Graph::adjacencyMatrix[j][i])
                    return false;
            }
        }
        return true;
    }

    /**
     * The function print description of graph according his parameters
     */
    void Graph::printGraphDescription()
    {
        cout << "Graph with " << Graph::countOfVer << " vertices and " << Graph::countOfEdges << " edges. ";
        Graph::isDirect ? cout << "The graph is direct" << endl : cout << "The graph is undirect." << endl;
    }

    /**
     * The function return string of the adjacency matrix of the graph
     */
    string Graph::printGraph(){
        string ans;
        size_t n = Graph::adjacencyMatrix.size();
        for (size_t i = 0; i < n; i++)
        {
            ans += '[';
            for (size_t j = 0; j < n; j++)
            {
                ans += to_string(Graph::adjacencyMatrix[i][j]);
                if(j != Graph::countOfVer-1)
                    ans += ", " ;    
            }
            ans += ']';
            if(i != Graph::countOfVer-1)
                ans += "\n";
        }
        //ans +="\n";
        return ans;
    }
//*********************************************************************************
    
    // Part 2
    /**
     * The function print the adjacency matrix of the graph
     */
    std::ostream& operator<<(std::ostream& os, const Graph& g)
    {
        size_t n = g.adjacencyMatrix.size();
        for (size_t i = 0; i < n; i++)
        {
            os << '[';
            for (size_t j = 0; j < n; j++)
            {
                os << g.adjacencyMatrix[i][j];
                if(j != g.countOfVer-1)
                    os << ", " ;    
            }
            os << ']';
            if(i != g.countOfVer-1)
                os << ",";
            os << '\n';
        }
        os << "\n";
        return os;
    }

    /**
     * The function get graph and return new graph who the sum of current graph with the graph the function got
     */
    Graph Graph::operator+(const Graph &other)
    {
        if (this->countOfVer != other.countOfVer)
        {
            __throw_invalid_argument("There are two matrix with difference sizes");
        }
        size_t n = (size_t)this->countOfVer;
        Graph newGraph;
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                result[i][j] = this->adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
            }
        }
        newGraph.loadGraph(result);
        return newGraph;
    }

    /**
     * The function get graph and return new graph who the sub of current graph with the graph the function got
     */
    Graph Graph::operator-(const Graph &other)
    {
        if (this->countOfVer != other.countOfVer)
        {
            __throw_invalid_argument("There are two matrix with difference sizes");
        }
        size_t n = (size_t)this->countOfVer;
        Graph newGraph;
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                result[i][j] = this->adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
            }
        }
        newGraph.loadGraph(result);
        return newGraph;
    }

    /**
     * The function get graph and add it to the current graph
     */
    Graph &Graph::operator+=(const Graph &other)
    {
        if (this->countOfVer != other.countOfVer)
        {
            __throw_invalid_argument("There are two matrix with difference sizes");
        }
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                this->adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        
        return *this;
    }

    /**
     * The function get graph and sub it to the current graph
     */

    Graph &Graph::operator-=(const Graph &other)
    {
        if (this->countOfVer != other.countOfVer)
        {
            __throw_invalid_argument("There are two matrix with difference sizes");
        }
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                this->adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    /**
     * The function make unary plus on the weights of graph's edges
     */
    Graph& Graph::operator+() 
    {
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] *= 1;
            }
        }
        return *this;
    }

    /**
     * The function make unary minus on the weights of graps's edges
     */
    Graph& Graph::operator-()
    {
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] *= (-1);
            }
        }
        return *this;
    }

    /**
     * The function get a number and mul all weigths of edges in graph with the number
     */
    Graph &Graph::operator*=(const int num)
    {
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] *= num;
            }
        }
        return *this;
    }

    /**
     * The function increase at 1 all weigths of edges in graph (prefix)
     */
    Graph &Graph::operator++()
    {
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] += 1;
            }
        }
        return *this;
    }

    /**
     * The function decrease at 1 all weigths of edges in graph (prefix)
     */
    Graph &Graph::operator--()
    {
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] -= 1;
            }
        }
        return *this;
    }

    /**
     * The function increase at 1 all weigths of edges in graph (postfix)
     */
    Graph Graph::operator++(int)
    {
        Graph g = *this;
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] += 1;
            }
        }
        return g;
    }

    /**
     * The function decrease at 1 all weigths of edges in graph (postfix)
     */
    Graph Graph::operator--(int)
    {
        Graph g = *this;
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j])
                    this->adjacencyMatrix[i][j] -= 1;
            }
        }
        return g;
    }

    /**
     * The function get graph and return true if the current graph and the graph the function got are equals.
     * Two graphs are equal if they have same count of vertices and the same edges between their vertices and same weights of edges
     * Else return false
     */
    bool Graph::operator==(const Graph &other)
    {
        if (this->countOfVer != other.countOfVer)
            return false;
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j])
                    return false;
            }
        }
        return true;
    }

    /**
     * The function get graph and return true if the graph and the current graph are not equals, else return false
     */
    bool Graph::operator!=(const Graph &other)
    {
        return !(this == &other);
    }

    /**
     * The function get a graph and check if it's bigger the current graph
     * graph smaller than other if it's completely contained in other (not equal)
     * If impossoble to check inclusion the function compare the count of graph's edges
     * If the count of edges are equal the function check the count of graph's vertices
     * The function return true if the current graph smaller than other graph else return false
     */
    bool Graph::operator<(const Graph &other)
    {
        if (this == &other)
            return false;
        if (this->countOfVer > other.countOfVer)
            return false;
        if (this->countOfEdges > other.countOfEdges)
            return false;
        size_t n = (size_t)this->countOfVer;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->adjacencyMatrix[i][j] && !other.adjacencyMatrix[i][j])
                    return false;
            }
        }
        return true;
    }

    /**
     * The function return true if the current graph smaller or equal than other graph, else return false
     */
    bool Graph::operator<=(const Graph &other)
    {
        return (this < &other || this == &other);
    }

    /**
     * The function return true if the current graph bigger than other graph, else return false
     */
    bool Graph::operator>(const Graph &other)
    {
        return !(this <= &other);
    }

    /**
     * The function return true if the current graph bigger or equal than other graph, else return false
     */
    bool Graph::operator>=(const Graph &other)
    {
        return !(this < &other);
    }


/**
 * The function get graph and return new graph that his adjacency matrix is the result of the adjacency matrix of the cuurrent graph mul the adjacency matrix of other
 * (According the rules of multiplication matrices)
*/
    Graph Graph::operator*(const Graph &other)
    {
        if (this->countOfVer != other.countOfVer)
        {
            __throw_invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        size_t n = (size_t)this->countOfVer;
        Graph newGraph;
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                result[i][j] = mul(this->adjacencyMatrix, other.adjacencyMatrix, i, j);
            }
        }
        for (size_t t = 0; t < n; t++){
            result[t][t] = 0;
        }
        newGraph.loadGraph(result);
        return newGraph;
    }

/**
 * The function get two matrices and number of raw in the first natrix and number of col in the second matrix
 * The function return the result of the multiplication between the raw with the col
*/
    int Graph::mul(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, size_t raw, size_t col)
    {
        size_t n = (size_t)mat1.size();
        int  result = 0;
        size_t i = 0;
        size_t j = 0;
        for (size_t k = 0; k < n; k++){
            result = result + (mat1[raw][j] * mat2[i][col]);
            i++;
            j++;
        }
        
        return result;
    }


}