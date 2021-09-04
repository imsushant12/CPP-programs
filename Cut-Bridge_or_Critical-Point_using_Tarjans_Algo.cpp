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

    void Tarjans_Algorithm(int source, vector<int> &discovery, vector<int> &low, stack<int> &s, vector<int> &inStack)
    {
        static int time = 0;

        discovery[source] = low[source] = ++time;
        s.push(source);
        inStack[source] = 1;

        for (auto v : graph[source])
        {
            if (discovery[v] == -1)
            {
                Tarjans_Algorithm(v, discovery, low, s, inStack);
                low[source] = min(low[source], low[v]);

                // checking the CRITICAL POINT during backtracking.
                if (low[v] > discovery[source])
                    cout <<"The Critical Section or Cut Bridge is : " << source << " to " << v << endl;
            }

            // Changing the low value of vertices that are already presentin the stack.
            else if (inStack[v] == 1)        
                low[source] = min(low[source], discovery[v]);
        }
        
        // popping the elemnts of SCC from stack and marking them unvisited.
        if (discovery[source] == low[source])
        {
            while (s.top() != source)
            {
                inStack[s.top()] == -1;
                s.pop();
            }
            inStack[s.top()] == -1;
            s.pop();
        }
    }
};

int main()
{
    int V = 7;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    stack<int> s;
    vector<int> inStack(V, -1);

    for (int i = 0; i < V; i++)
        if (discovery[i] == -1)
            g.Tarjans_Algorithm(i, discovery, low, s, inStack);

    return 0;
}