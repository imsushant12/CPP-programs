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
        graph[v].push_back(u);
    }

    int type_of_Graph()
    {
        int oddCount = 0;

        for (int i = 0; i < V; i++)
        {
            if (graph[i].size() % 2 != 0)
                oddCount++;
        }

        return oddCount;
    }
};

int main()
{
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.type_of_Graph() == 0)
        cout << "Eularian Graph!";
    else if (g.type_of_Graph() == 2)
        cout << "Semi-Eularian Graph!";
    else
        cout << "Non-Eularian Graph!";

    return 0;
}