#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *graph;

public:
    bool Bipartite = true;
    vector<int> color;

    Graph(int V)
    {
        this->V = V;
        graph = new vector<int>[V];

        for (int i = 0; i < V; i++)
            color[i] = -1;
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void colorGraph(int v, int source)
    {
        queue<int> q;
        q.push(source);
        color[source] = 0;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i : graph[current])
            {
                if (color[i] == -1)
                {
                    color[i] = color[current] xor 1;
                    q.push(i);
                }
                if (color[current] == color[i])
                {
                    Bipartite = false;
                }
            }
        }
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
    g.addEdge(2, 4);
    g.addEdge(3, 2);

    for (int i = 0; i < V; i++)
        if (g.color[i] == -1)
            g.colorGraph(V, i);

    // To check for disconnected graphs, use visited array and call
    // Bipartitite() on un-visited vertices. (basic DFS)
    if (!g.Bipartite)
        cout << "Graph is not Bipartite!" << endl;
    else
        cout << "Graph is Bipartite!" << endl;

    // printing the color array.
    cout << "Color of the vertices : \n";
    for (int i = 0; i < V; i++)
        cout << i << " --> " << g.color[i] << endl;

    return 0;
}