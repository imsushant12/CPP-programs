#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l;

public:
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
            list<int>::iterator it;
            for (it = l[i].begin(); it != l[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
    }

    void DFS(int source)
    {
        stack<int> s;
        vector<int> visited(v, 0);
        list<int>::iterator it;

        s.push(source);
        visited[source] = 1;
        cout << source << "  ";

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            for (it = l[top].begin(); it != l[top].end(); it++)
            {
                if (!visited[*it])
                {
                    cout << *it << "  ";
                    visited[*it] = 1;
                    s.push(*it);
                }
            }
        }
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

    cout << "BFS of the graph is : ";
    g.DFS(source);

    return 0;
}
