#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l;

public:
    list<int>::iterator it;
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdges(int e1, int e2)
    {
        l[e1].push_back(e2);
        l[e2].push_back(e1);
    }

    void display(int v)
    {
        cout << "List representation of the graph is : " << endl;
        for (int i = 0; i < v; i++)
        {
            cout << i << " --> ";

            for (it = l[i].begin(); it != l[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
    }

    void DFS(int source, vector<int> &visited)
    {
        visited[source] = 1;
        cout << source << "  ";
        list<int>::iterator it;

        for (it = l[source].begin(); it != l[source].end(); it++)
            if (!visited[*it])
                DFS(*it, visited);
    }
};

int main()
{
    int v = 4;
    Graph g(v);

    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 3);

    g.display(v);

    int source = 0;
    vector<int> visited(v, 0);
    cout << "BFS of the graph is : ";
    g.DFS(source, visited);

    return 0;
}
