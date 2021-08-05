#include <bits/stdc++.h>
using namespace std;

int graph[10][10];

void createGraph(int i, int j, int weight)
{
    graph[i][j] = weight;
    graph[j][i] = weight;
}

void BellmanFordAlgorithm(int source, int v, vector<int> &distance)
{
    //Setting distance of source vertex as 0.
    distance[source] = 0;

    for (int i = 1; i < v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (graph[i][j] != 0)
                distance[j] = min(distance[j], distance[i] + graph[i][j]);
        }
    }

    for (int i = 1; i <= v; i++)
        cout << "\nDistance of " << source << " to " << i << " is : " << distance[i];
}

int main()
{
    int v, i, j, edge, weight;
    cout << "Enter the number of vertex : ";
    cin >> v;

    // Initializing the graph matrix with 0.
    for (i = 1; i <= v; i++)
        for (j = 1; j <= v; j++)
            graph[i][j] = 0;

    // Creating Graph
    for (i = 1; i <= v; i++)
    {
        while (1)
        {
            cout << "Enter the edges from " << i << " or press -1 : ";
            cin >> edge;
            if (edge == -1)
                break;
            cout << "Enter its weight : ";
            cin >> weight;

            createGraph(i, edge, weight);
        }
    }

    vector<int> distance(v + 1, 9999);

    BellmanFordAlgorithm(1, v, distance);

    return 0;
}

/*
if (graph[minEdge][j] != 0 && !visited[j])
                distance[j] = min(distance[j], distance[minEdge] + graph[minEdge][j]);
                */