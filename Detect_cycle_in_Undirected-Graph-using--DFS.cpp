#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *graph;

public:
    Graph(int v)
    {
        this->v = v;
        graph = new list<int>[v];
    }

    void addEdge(int e1, int e2)
    {
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }

    bool detectCycleDFS(int source, int parent, vector<bool> &visited)
    {
        visited[source] = true;
        for (auto current : graph[source])
        {
            if (!visited[current])
            {
                if (detectCycleDFS(current, source, visited))
                    return true;
            }
            // Checking if the visited vertex is parent or not.
            // If it is parent then the vertex and its parent has same value.
            // Else there is a loop or cycle present.
            else if (current != parent)
                return true;
        }
        return false;
    }
};

int main()
{
    int v = 4;
    Graph g(v);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    //g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);

    bool flag = false;
    int parent = -1;
    vector<bool> visited(v, false);

    for (int source = 0; source < v; source++)
        if (!visited[source] && g.detectCycleDFS(source, parent, visited))
            flag = true;

    if (flag)
        cout << "Cycle is detected!";
    else
        cout << "Cycle is not found!";

    return 0;
}
