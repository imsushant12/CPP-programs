#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<int> *graph;

    Graph(int V)
    {
        this->V = V;
        graph = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }

    void dfs(int source, vector<bool> &visited)
    {
        visited[source] = true;

        for (auto v : graph[source])
        {
            if (!visited[v])
                dfs(v, visited);
        }
    }

    bool checkifConnected(int source)
    {
        int counter = 0;
        vector<bool> visited(V, false);

        dfs(source, visited);

        for (int i = 0; i < V; i++)
            if (visited[i])
                counter++;

        // If visited count is same as the number of vertices then it is a connected graph.
        if (counter == V)
        {
            cout << "The Graph is connected from the vertex : " << source;
            return true;
        }
        else
            return false;
    }
};

int main()
{
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 0);

    bool flag = false;

    //Since it is a directed graph so we need to check from every vertex.
    for (int source = 0; source < V; source++)
        if (g.checkifConnected(source))
            flag = true;

    if (!flag)
        cout << "The Graph is dis-connected!";

    return 0;
}