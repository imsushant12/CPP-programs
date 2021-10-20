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

    void dfs(vector<int> &dp, vector<bool> &visited, int u)
    {
        if (visited[u])
            return;

        visited[u] = true;

        for (int neighbour : graph[u])
        {
            if (!visited[neighbour])
                dfs(dp, visited, neighbour);

            dp[u] = max(dp[u], dp[neighbour] + 1);
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(4, 2);

    vector<bool> visited(V, false);
    vector<int> dp(V);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            g.dfs(dp, visited, i);
    }

    cout << "Longest path-length in th DAG is: " << *max_element(dp.begin(), dp.end());

    return 0;
}