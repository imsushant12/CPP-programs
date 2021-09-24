#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

vector<int> graph[maxN];
int indegree[maxN];
int answer[maxN];

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    indegree[v]++;
}

void printOrder(int v, int m)
{
    // Performing Topological Sorting.
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            answer[i] = 1;
        }
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto x : graph[current])
        {
            indegree[x]--;

            if (indegree[x] == 0)
            {
                answer[x] = answer[current] + 1;
                q.push(x);
            }
        }
    }

    // Printing the answer.
    for (int i = 1; i <= v; i++)
        cout << answer[i] << "  ";
}

int main()
{
    int V = 10;
    int edges = 13;

    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    printOrder(V, edges);

    return 0;
}
