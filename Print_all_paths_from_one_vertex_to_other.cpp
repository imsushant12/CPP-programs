#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }

    // int index = 0;
    void dfs(vector<vector<int>> &result, vector<int> &path, int s, int d)
    {
        path.push_back(s);

        if (s == d)
        {
            result.push_back(path);
            return;
        }
        else
        {
            vector<int>::iterator i;
            for (i = graph[s].begin(); i != graph[s].end(); i++)
            {
                //cout << *i << endl;
                dfs(result, path, *i, d);
            }
        }
        path.pop_back();
    }

    void printAllPaths(int s, int d)
    {
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, s, d);

        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
                cout << result[i][j] << "  ";
            cout << endl;
        }
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

    cout << "Following are the paths from " << s << " to " << d << endl;
    g.printAllPaths(s, d);

    return 0;
}