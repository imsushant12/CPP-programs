#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *graph;

public:
    bool Bipartite = true;
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

    void color(int v)
    {
        // visited or color array
        vector<int> color(v, -1);
        color[0] = 0;

        for (int i = 0; i < v; i++)
        {
            for (auto x : graph[i])
            {
                if (color[x] == -1)
                {
                    // if (color[i] == 0) then color[x] = 1 and vice versa.
                    color[x] = color[i] xor 1;
                }
                else
                {
                    if (color[x] == color[i])
                        Bipartite = false;
                }
            }
        }

        // printing the color array.
        cout << "Color of the vertices : \n";
        for (int i = 0; i < v; i++)
            cout << i << " --> " << color[i] << endl;
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

    g.color(V);

    // To check for disconnected graphs, use visited array and call
    // Bipartitite() on un-visited vertices. (basic DFS)
    if (!g.Bipartite)
        cout << "Graph is not Bipartite!" << endl;
    else
        cout << "Graph is Bipartite!" << endl;

    return 0;
}