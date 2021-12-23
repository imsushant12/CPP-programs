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
        graph[v].push_back(u);
    }

    void dfs(int source, vector<bool> &visited)
    {
        visited[source] = true;

        for (int i : graph[source])
            if (!visited[i])
                dfs(i, visited);
    }

    bool checkConnected()
    {
        vector<bool> visited(V + 1, false);
        // checking if there is any edge in the graph or not.
        // if there is 0 edge then the graph is disconnected. (Euler Graph Theory)
        int source = -1;
        for (int i = 0; i < V; i++)
        {
            if (graph[i].size() > 0)
            {
                source = i;
                break;
            }
        }

        // if there is no edge then returning true as it is Euler Graph.
        if (source = -1)
            return true;

        dfs(source, visited);

        // checking if there is any vertex left to be discovered:
        for (int i = 0; i < V; i++)
        {
            // if we have edges in the multi-components
            if (!visited[i] and graph[i].size() > 0)
                return false;
        }

        return true;
    }

    void checkEuler()
    {
        if (!checkConnected())
        {
            cout << "Not an Eularian Graph!" << endl;
            return;
        }

        int oddCount = 0;
        for (int i = 0; i < V; i++)
        {
            if (graph[i].size() & 1)
                oddCount += 1;
        }

        if (oddCount > 2)
            cout << "Not an Eularian Graph!" << endl;
        if (oddCount == 2)
            cout << "Semi-Eularian Graph!" << endl;
        else
            cout << "Eularian Graph!" << endl;
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(0, 3);

    g.checkEuler();

    return 0;
}