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
    
    void dfs(vector<vector<int>> &result, vector<int> &path, vector<bool> &visited,int s, int d)
    {
        path.push_back(s);
        visited[s] = true;

        if (s == d)
            result.push_back(path);
        else
        {
            for(auto i : graph[s])
                if(!visited[i])
                    dfs(result, path, visited, i, d);
        }
        // Before popping the last element in the backtracking, make sure that 
        // the element is marked unvisited , so that it can be used in other path.
        visited[path.back()] = false;
        path.pop_back();
    }

    vector<vector<int>> dfsutil(int source, int dest)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(this->V, false);

        dfs(result, path, visited, source, dest);

        return result;

    }

    void printAllPaths(int s, int d)
    {
        vector<vector<int>> result;
        result = dfsutil(s, d);

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