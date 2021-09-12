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

    bool Hamiltonian_Path(int source, vector<int> &path, vector<int> &visited)
    {
        if (path.size() == V)
            return true;

        for (auto i : graph[source])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                path.push_back(i);

                if (Hamiltonian_Path(i, path, visited))
                    return true;

                // BACKTRACKING:
                visited[i] = 0;
                path.pop_back();
            }
        }
        return false;
    }
};

int main()
{
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    //g.addEdge(2, 3);
    g.addEdge(3, 0);

    // Checking all the hamiltonian paths and cycles :
    for (int i = 0; i < V; i++)
    {
        vector<int> path;
        vector<int> visited(V, 0);
        path.push_back(i);
        visited[i] = 1;
        if (g.Hamiltonian_Path(i, path, visited))
        {
            for (int j = 0; j < path.size(); j++)
                cout << path[j] << "  ";

            // Checking for the Hamiltonian Cycle:
            vector<int>::iterator it;
            it = find(g.graph[i].begin(), g.graph[i].end(), path[V - 1]);
            if (it != g.graph[V].end())
                cout << "\nHamiltonian Cycle is present! " << endl;
            else
                cout << "\nHamiltonian Cycle is not found!" << endl;
        }
    }

    return 0;
}