#include <bits/stdc++.h>
using namespace std;

int graph[10][10];

void createGraph(int i, int j, int weight)
{
    graph[i][j] = weight;
    graph[j][i] = weight;
}

int minimumEdge(vector<int> &visited, vector<int> &distance, int v)
{
    // int minVertex = -1; //initially we are assuming that first index in minimum index
    // for (int i = 1; i <= v; i++)
    // {
    //     if ((!visited[i]) && (minVertex == -1 || distance[minVertex] > distance[i]))
    //         minVertex = i;
    // }
    // return minVertex;
    int minEdge = INT_MAX;
    int result = -1;
    for (int i = 0; i < v; i++)
    {
        if (distance[i] < minEdge and visited[i] == 0)
        {
            minEdge = distance[i];
            result = i;
        }
    }

    return result;
}

void DijkstraAlgorithm(int source, int v, vector<int> &visited, vector<int> &distance)
{
    //Setting distance of source vertex as 0.
    distance[source] = 0;

    for (int i = 1; i <= v; i++)
    {
        int minEdge = minimumEdge(visited, distance, v);
        visited[minEdge] = 1;

        for (int j = 1; j <= v; j++)
        {
            if (graph[minEdge][j] != 0 && !visited[j])
                distance[j] = min(distance[j], distance[minEdge] + graph[minEdge][j]);
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
    {
        for (j = 1; j <= v; j++)
            graph[i][j] = 0;
    }

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

    vector<int> visited(v + 1, 0);
    vector<int> distance(v + 1, 9999);

    DijkstraAlgorithm(1, v, visited, distance);

    return 0;
}