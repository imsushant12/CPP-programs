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

    void printStack(stack<int> &s, int source, vector<int> &inStack)
    {
        while (s.top() != source)
        {
            cout << s.top() << "  ";
            inStack[s.top()] == -1;
            s.pop();
        }
        cout << s.top() << "  " << endl;
        inStack[s.top()] == -1;
        s.pop();
    }

    void Tarjans_Algorithm(int source, vector<int> &discover, vector<int> &low, stack<int> &s, vector<int> &inStack)
    {
        static int time = 0;

        discover[source] = low[source] = ++time;
        s.push(source);
        inStack[source] = 1;

        for (auto v : graph[source])
        {
            if (discover[v] == -1)
            {
                Tarjans_Algorithm(v, discover, low, s, inStack);
                // Important STEP
                low[source] = min(low[source], low[v]);
            }
            else if (inStack[v] == 1)
            {
                // Important STEP
                low[source] = min(low[source], discover[v]);
            }
        }
        // Lastly printing the stack to get one component.
        if (discover[source] == low[source])
            printStack(s, source, inStack);
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

    vector<int> discover(V, -1);
    vector<int> low(V, -1);
    // Stack to print the vertices of one component.
    stack<int> s;
    // Vector to store the vertices present in the stack.
    vector<int> inStack(V, -1);

    cout << "Strongly connected components are : \n";
    for (int i = 0; i < V; i++)
    {
        // To make sure that no vertex is left un-discovered.
        if (discover[i] == -1)
            g.Tarjans_Algorithm(i, discover, low, s, inStack);
    }

    return 0;
}