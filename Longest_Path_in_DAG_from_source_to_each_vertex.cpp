#include <bits/stdc++.h>
using namespace std;

class Node
{
    int v;
    int weight;

public:
    Node(int v, int weight)
    {
        this->v = v;
        this->weight = weight;
    }

    int getV()
    {
        return v;
    }

    int getWeight()
    {
        return weight;
    }
};

class Graph
{
    int V;
    list<Node> *graph;

    void topologicalSortUtil(int v, bool visited[], stack<int> &s)
    {
        visited[v] = true;

        list<Node>::iterator i;
        for (i = graph[v].begin(); i != graph[v].end(); i++)
        {
            Node node = *i;
            if (!visited[node.getV()])
                topologicalSortUtil(node.getV(), visited, s);
        }
        s.push(v);
    }

public:
    Graph(int V)
    {
        this->V = V;
        graph = new list<Node>[V];
    }

    ~Graph()
    {
        delete[] graph;
    }

    void addEdge(int u, int v, int weight)
    {
        Node node(v, weight);
        graph[u].push_back(node);
    }

    void longestPath(int s)
    {
        stack<int> st;
        int distance[V];

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topologicalSortUtil(i, visited, st);
        }

        for (int i = 0; i < V; i++)
            distance[i] = INT_MIN;

        distance[s] = 0;
        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            list<Node>::iterator i;
            if (distance[u] != INT_MIN)
            {
                for (i = graph[u].begin(); i != graph[u].end(); i++)
                {
                    if (distance[i->getV()] < distance[u] + i->getWeight())
                        distance[i->getV()] = distance[u] + i->getWeight();
                }
            }
        }

        for (int i = 0; i < V; i++)
            (distance[i] == INT_MIN) ? cout << "INFINITY  " : cout << distance[i] << "  ";

        delete[] visited;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int source = 1;
    cout << "Following are longest distanceances from vertex : " << source << " --> ";
    g.longestPath(source);

    return 0;
}
