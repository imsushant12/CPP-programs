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

    // USING TOPOLOGICAL SORTING (BFS):
    void detectCycleBFS(int source, vector<bool> &visited, vector<int> &indegree)
    {
        queue<int> q;

        // Assigning the indegree of each vertex.
        for (int i = 0; i < v; i++)
        {
            for (auto v : graph[i])
                indegree[v]++;
        }

        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int v : graph[current])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
    }
};

int main()
{
    int v = 4;
    Graph g(v);

    vector<int> indegree(v);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);

    bool flag = false;
    vector<bool> visited(v, false);

    for (int source = 0; source < v; source++)
        if (!visited[source])
            g.detectCycleBFS(source, visited, indegree);

    // After Topological Sorting, Checking if any of the vertex has in-degree more than 0 then there is a cycle or loop.
    for (int i = 0; i < v; i++)
        if (indegree[i] > 0)
            flag = true;

    if (flag)
        cout << "Cycle is detected!";
    else
        cout << "Cycle is not found!";

    return 0;
}
