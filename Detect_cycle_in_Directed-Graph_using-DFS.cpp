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
    }

    bool detectCycleDFS(int source, vector<bool> &stack, vector<bool> &visited)
    {
        stack[source] = true;
        if (!visited[source])
        {
            visited[source] = true;
            for (auto v : graph[source])
            {
                if (!visited[v] && detectCycleDFS(v, stack, visited))
                    return true;
                // if the node is already present in the stack then there is a loop.
                if (stack[v] == true)
                    return true;
            }
        }
        // If not found any cycle form the source, remove it.
        // BACKTRACKING...
        stack[source] = false;
        return false;
    }
};

int main()
{
    int v = 4;
    Graph g(v);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    bool flag = false;
    vector<bool> stack(v, false);
    vector<bool> visited(v, false);

    for (int source = 0; source < v; source++)
        if (!visited[source] && g.detectCycleDFS(source, stack, visited))
            flag = true;
    

    if (flag)
        cout << "Cycle is detected!";
    else
        cout << "Cycle is not found!";

    return 0;
}
