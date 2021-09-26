#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> make_graph(int totalTasks, vector<pair<int, int>> &tasks)
{
    vector<unordered_set<int>> graph(totalTasks);
    for (auto x : tasks)
        graph[x.second].insert(x.first);

    return graph;
}

bool dfs(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
{
    if (visited[node])
        return false;

    onpath[node] = visited[node] = true;

    for (int neigh : graph[node])
        if (onpath[neigh] || dfs(graph, neigh, onpath, visited))
            return true;

    return onpath[node] = false;
}

bool canFinish(int totalTasks, vector<pair<int, int>> &tasks)
{
    vector<unordered_set<int>> graph = make_graph(totalTasks, tasks);
    vector<bool> onpath(totalTasks, false);
    vector<bool> visited(totalTasks, false);

    for (int i = 0; i < totalTasks; i++)
        if (!visited[i] && dfs(graph, i, onpath, visited))
            return false;

    return true;
}

int main()
{
    int totalTasks = 4;

    vector<pair<int, int>> tasks;

    tasks.push_back({1, 0});
    tasks.push_back({2, 1});
    tasks.push_back({3, 2});

    if (canFinish(totalTasks, tasks))
        cout << "Possible to finish all tasks";
    else
        cout << "Impossible to finish all tasks";

    return 0;
}
