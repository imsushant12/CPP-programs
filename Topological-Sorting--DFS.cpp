#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        graph[v].push_back(w);
    }

    void topologicalSortDFS(int source, vector<int> &visited, stack<int> &answer)
    {
        visited[source] = 1;

        for (auto i : graph[source])
        {
            if (!visited[i])
                topologicalSortDFS(i, visited, answer);
        }
        // During backtracking, pushing the current node in the stack to print it later.
        answer.push(source);
    }
};

int main()
{
    int v = 6;
    Graph g(v);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> visited(v, 0);
    // For printing the topological sorting, using a stack.
    stack<int> answer;

    for (int source = 0; source < v; source++)
    {
        if (!visited[source])
            g.topologicalSortDFS(source, visited, answer);
    }

    cout << "Following is a Topological Sort of the given graph : ";
    while(!answer.empty())
    {
        cout<<answer.top()<<"  ";
        answer.pop();
    }    

    return 0;
}
