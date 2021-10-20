#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    int M;
    vector<int> *graph;

public:
    bool Bipartite = true;
    Graph(int V, int M)
    {
        this->V = V;
        this->M = M;
        graph = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int check_available(bool available[])
    {
        int i;
        for (i = 0; i < V; i++)
        {
            // it resembles that the current color i.e. "i" is available.
            if (available[i] == false)
            {

                // if i is greater than m, it means we have used more than m colors.
                // we are using (m - 1) because indexing is 0-based.
                if (i > (M - 1))
                    Bipartite = false;
                break;
            }
        }

        return i;
    }

    void color(int v)
    {
        int chromaticNumber = 0;
        // colors will store color of each node.
        // available will check available colors for each node.
        int color[v];
        for (int i = 0; i < v; i++)
            color[i] = -1;

        bool available[v];
        for (int i = 0; i < v; i++)
            available[i] = false;

        // initially the color of first vertex i.e. "0" is 0.
        color[0] = 0;
        available[0] = true;
        // Iterating each vertex.
        for (int i = 1; i < V; i++)
        {
            for (auto x : graph[i])
            {
                // if adjacent vertex is already colored.
                if (color[x] != -1)
                {
                    available[color[x]] = true;
                }
            }

            // color available for the current vertex after checking all adjacent vertices.
            int colorAvailabe = check_available(available);
            color[i] = colorAvailabe;

            // updating the chromatic number.
            chromaticNumber = max(chromaticNumber, colorAvailabe + 1);

            // finally reseting the availabe array after current vertex's iteration.
            for (auto x : graph[i])
            {
                if (color[x] != -1)
                    available[color[x]] = false;
            }
        }

        // Outputing the reult.
        cout << "Color of each node : " << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << " --> " << color[i] << "  " << endl;
        }
    }
};

int main()
{
    int V = 5;
    int M = 2;
    Graph g(V, M);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    // g.addEdge(2, 4);
    g.addEdge(3, 2);

    g.color(V);

    if (!g.Bipartite)
        cout << "\nColoring is not possible with " << M << " colors!" << endl;
    else
        cout << "\nColoring is possible!" << endl;

    return 0;
}