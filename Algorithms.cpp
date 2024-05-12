//ID: 207826694
//GMAIL: didooron@gmail.com

#include <iostream>
#include <vector>
#include <stdexcept>

#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace std;

namespace ariel
{

    namespace Algorithms
    {

        /**
         * The function make BFS on graph: if the graph direct - the BFS is on all vertices for check strong connected. if undirected - the BFS is on random vertex
         * After BFS, if exist white vertex it's mean that the graph is disconnected
         * The function use two vectors:
         * 1.colors vector - color is vector that each index presents vertex, and the value presents the color of vector
         * 2.visit vector - visit is empty vector. each vertex who pained gray push to vector. when we finish to check all neighbors of any vertex, we pop the next vertex in the vector
         */
        bool isConnected(Graph &g)
        {
            size_t n = (size_t)g.countOfVer;
            vector<int> colors(n, white);
            vector<int> visit;
            if (g.isDirect)
            {
                for (size_t i = 0; i < g.countOfVer; i++)
                {
                    bfs(g, i, visit, colors);
                    for (size_t i = 0; i < colors.size(); i++)
                    {
                        if (colors[i] == white)
                        {
                            cout << "The graph is disconnected" << endl;
                            return false;
                        }
                        colors[i] = white; // return each value in colors to be white for the next bfs on the next vertex
                    }
                }
            }
            else
            {
                bfs(g, 0, visit, colors);
                for (size_t i = 0; i < colors.size(); i++)
                {
                    if (colors[i] == white)
                    {
                        cout << "The graph is not connected" << endl;
                        return false;
                    }
                }
            }
            cout << "The graph is connected" << endl;
            return true;
        }

        /**
         * The function get graph, vertex, and two vectors.
         * The function return vectors of colors according BFS algorithm on the vertex the function received
         */
        void bfs(Graph &g, size_t s, vector<int> &visit, vector<int> &colors)
        {
            visit.push_back(s);
            while (visit.size() > 0)
            {
                size_t v = (size_t)visit.back();
                colors[v] = gray;
                visit.pop_back();
                for (size_t i = 0; i < g.countOfVer; i++)
                {
                    if (g.adjencyMatrix[v][i] != 0 && colors[i] == white)
                    {
                        colors[i] = gray;
                        visit.push_back(i);
                    }
                }
                colors[v] = black;
            }
        }

        /**
         * The function find the shortest path between start to end by Bellman-ford algo
         * The function use vector namely distance that each index is vertex and each value is the shortest path between start to any index in vector
         * The fuction use vector namely path that each index is vertex who contain the easy edge that artiive him
         * Finally the function print the shortest path between start to end if exists or return -1 if doesn't
         */
        string shortestPath(Graph &g, size_t start, size_t end)
        {
            /*if(negativeCycle)
            {
                throw_invalid_argument("Invalid graph: The graph has negative cycle.");
            */
            if(start==end)
            {
                __throw_invalid_argument("Invalid argumaents: 'start' can't be same 'end'.");
            }
           
            string ans;
            size_t n = (size_t)g.countOfVer;
            vector<int> distance(n, infinity);
            vector<int> path(n, -1);
            bellmanFord(g, start, distance, path);
            if (distance[end] != infinity)
            {
                ans = printPath(path, start, end);
            }
            else
            {
                ans = "-1";
                cout << "No path" << endl;
            }
            return ans;
        }

        /**
         * Bellman-Ford Algorithm.
         * The func make relax for all edges in the graph n-1 times
         */
        void bellmanFord(Graph &g, int s, vector<int> &d, vector<int> &p)
        {
            d[(size_t)s] = 0;
            for (int k = 0; k < g.countOfVer - 1; k++)
            {
                for (size_t i = 0; i < g.adjencyMatrix.size(); i++)
                {
                    for (size_t j = 0; j < g.adjencyMatrix[i].size(); j++)
                    {
                        if (g.adjencyMatrix[i][j])
                            relax(d, p, i, j, g.adjencyMatrix[i][j]);
                    }
                }
            }
        }

        /**
         * Realx Algorithm.
         * The function get graph, two vertex and two vectors.
         * if possible to make relax on edge(i,j):
         * 1. "distance" vector save the relly minimal way to arrive to j.
         * 2. "path" vector put the "dad" i in index j
         */
        void relax(vector<int> &d, vector<int> &p, size_t i, size_t j, int w)
        {
            if (d[i] != infinity && d[i] + w < d[j])
            {
                d[j] = d[i] + w;
                p[j] = i;
            }
        }
        /**
         * The function get source and destination vertex and vector who represents the path between them
         * The function print the path.
         */
        string printPath(vector<int> path, size_t start, size_t end)
        {
            string ans;
            vector<int> oppositePath;
            size_t i = end;
            oppositePath.push_back(i);
            while (i != start)
            {
                i = (size_t)path[i];
                oppositePath.push_back(i);
            }
            for (size_t i = oppositePath.size() - 1; i > 0; i--)
            {
                ans += oppositePath[i] + 48;
                ans += "->";
            }
            ans += oppositePath[0] + 48;
            return ans;
        }

        /**
         * The function pass on each vertex in graph and look for circle from this vertex.
         * If exist print the circle and if doesn't return 0.
         */
        bool isContainsCycle(Graph &g)
        {
            bool ans = false;
            if (g.edges() == 0)
                return ans;
            size_t n = (size_t)g.countOfVer;
            vector<int> color(n, white);
            vector<int> path(n, -1);
            for (size_t i = 0; i < n; i++)
            {
                ans = dfs(g, color, path, i);
                if (ans)
                    break;
            }
            if (!ans)
                cout << "No cycles" << endl;
            return ans;
        }

        /**
         * The function is similar to originaal DFS
         * The function get graph and any vertex and return true if exists circle from him in the graph and return false if does not.
         * The function "paint" each vertex who visited with vector namely "color",
         * and save the previous vertex with verctor namely "path".
         * If the vertex already with color so it's a cycle
         */
        bool dfs(Graph &g, vector<int> color, vector<int> path, size_t v)
        {
            for (size_t i = 0; i < g.adjencyMatrix[v].size(); i++)
            {
                if (g.adjencyMatrix[v][i])
                {
                    if (color[i] == white)
                    {
                        color[i] = gray;
                        path[i] = v;
                        return dfs(g, color, path, i);
                    }
                    else if (color[i] == gray)
                        printCircle(path, v, i); 
                    return true;
                }
            }
            return false;
        }
        /**
         * The function get source and destination vertices and vector of path between them.
         * The function print the path according the vector
         */
        void printCircle(vector<int> path, size_t start, size_t end)
        {
            cout << "The circle is: " << start << "->";
            string ans = printPath(path, end, start);
            cout << ans << endl;
        }


        /**
         * The function pass on all edges in the graph and return appropriate string if the graph is bipartite
         */
        string isBipartite(Graph &g)
        {
            string ans;
            size_t n = g.adjencyMatrix.size();
            vector<bool> visit(n, false); // visit is boolean vector of vertices that contain true if the vertex already visited and false if not
            vector<char> team(n, 'X');    // team is char vector of vertices that contain the team of the vertex(A or B) or X if the vertex has not team
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if (g.adjencyMatrix[i][j])
                    {
                        bool flag = whichGroup(i, j, visit, team); // flag symbol if we can continue in loop after call to "whichGroup"
                        if (!flag)
                            return "0";
                    }
                }
            }
            ans = printGroups(team);
            return ans;
        }

        /**
         * The function get edge (two vertices) and part the vertices to the appropriate groups
         * The function return true if the division succeed and return false if the vertices in same group
         */
        bool whichGroup(size_t i, size_t j, vector<bool> &visit, vector<char> &team)
        {
            if (!visit[i] && !visit[j])
            {
                team[i] = 'A';
                team[j] = 'B';
                visit[i] = true;
                visit[j] = true;
            }
            else if (visit[i] && !visit[j])
            {
                if (team[i] == 'A')
                    team[j] = 'B';
                if (team[i] == 'B')
                    team[j] = 'A';
                visit[j] = true;
            }
            else if (!visit[i] && visit[j])
            {
                if (team[j] == 'A')
                    team[i] = 'B';
                if (team[j] == 'B')
                    team[i] = 'A';
                visit[i] = true;
            }
            else
            {
                if (team[i] == team[j])
                    return false;
            }
            return true;
        }

        /**
         * The function get vector of vertices that contain the group of each vertex and return string of the division of vertices to groups
         */
        string printGroups(vector<char> group)
        {
            //  "The graph is bipartite: A={0, 2, 4}, B={1, 3}"
            string ans = "The graph is bipartite: A={";
            // cout << "Group A: ";
            for (size_t i = 0; i < group.size(); i++)
            {
                if (group[i] == 'A')
                {
                    ans += i + 48;
                    ans += ", ";
                }
            }
            ans.pop_back();
            ans[ans.length() - 1] = '}';
            ans += ", B={";
            // cout << endl;
            // cout << "Group B: ";
            for (size_t i = 0; i < group.size(); i++)
            {
                if (group[i] == 'B')
                {
                    ans += i + 48;
                    ans += ", ";
                }
            }
            ans.pop_back();
            ans[ans.length() - 1] = '}';
            return ans;
        }

        bool negativeCycle(Graph &g)
        {
            string ans;
            size_t start = 0;
            bool isNegativeCycle = false;
            size_t n = (size_t)g.countOfVer;
            vector<int> d(n, infinity);
            vector<int> path(n, -1);
            vector<int> c(n, white);
            bellmanFord(g, start, d, path);
            for (size_t i = 0; i < g.adjencyMatrix.size(); i++)
            {
                for (size_t j = 0; j < g.adjencyMatrix[i].size(); j++)
                {
                    if (g.adjencyMatrix[i][j] && d[i]!=infinity && d[i] + g.adjencyMatrix[i][j] < d[j])
                    {
                        isNegativeCycle = dfs(g,c,path,i);
                        break;
                    }
                }
            }
            return isNegativeCycle;
        }

    };

};
