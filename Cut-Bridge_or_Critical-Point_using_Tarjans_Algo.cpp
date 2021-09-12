#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }

    void Cut_Bridge_Algorithm(int source, vector<int> &discovery, vector<int> &low, vector<int> &parent)
    {
        static int time = 0;
        discovery[source] = low[source] = ++time;

        for (auto v : graph[source])
        {
            if (discovery[v] == -1)
            {
                parent[v] = source;
                Cut_Bridge_Algorithm(v, discovery, low, parent);
                low[source] = min(low[source], low[v]);
            }
            // checking the CRITICAL POINT during backtracking.
            if (low[v] > discovery[source])
                cout << "The Critical Section or Cut Bridge is : " << source << " to " << v << endl;

            else if (v != parent[source])
                low[source] = min(low[source], discovery[v]);
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++)
        if (discovery[i] == -1)
            g.Cut_Bridge_Algorithm(i, discovery, low, parent);

    return 0;
}