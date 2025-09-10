#include <iostream>
#include <vector>
using namespace std;

bool mColoring(int node, vector<int> &color, int V, int E, int M, vector<vector<int>> &graph)
{
    if (node == V)
    {
        return true;
    }

    for (int i = 1; i <= M; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};
    int V = 4;            // vertices
    int E = graph.size(); // edges
    int M = 3;            // colors
    vector<int> color(V);
}