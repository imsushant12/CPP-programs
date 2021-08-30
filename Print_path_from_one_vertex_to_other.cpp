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

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }

    void printPath(int s, int d, vector<int> &answer, vector<int> &visited)
    {
        answer.push_back(s);
        visited[s] = 1;
        if (s == d)
        {
            for (int i = 0; i < answer.size(); i++)
                cout << answer[i] << " ";
            cout << endl;
        }

        list<int>::iterator i;
        for (i = graph[s].begin(); i != graph[s].end(); i++)
            if (!visited[*i])
                printPath(*i, d, answer, visited);

        answer.pop_back();
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    vector<int> answer;
    vector<int> visited(4, 0);

    cout << "Following is the path from " << s << " to " << d << endl;
    g.printPath(s, d, answer, visited);

    return 0;
}
