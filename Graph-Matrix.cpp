#include <bits/stdc++.h>
using namespace std;

int visited[100] = {0};
int a[10][10];

void createGraph(int i, int j)
{
    a[i][j] = 1;
    a[j][i] = 1;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void DFS_recursive(int source, int V, vector<int> &visited)
{
    if (visited[source] == 0)
    {
        cout << source << "  ";
        visited[source] = 1;
        for (int i = 1; i <= V; i++)
        {
            if (a[source][i] == 1) //means if there is an edge between s and i
                DFS_recursive(i, V, visited);
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BFS(int source, int V, vector<int> &visited)
{
    queue<int> q;
    cout << source << "  ";
    visited[source] = 1;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 1; i <= V; i++)
        {
            if ((a[node][i] == 1) && (visited[i] == 0))
            {
                cout << i << "  ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

int findMinVertex(int *distance, int V)
{
    int minVertex = -1; //initially we are assuming that first index in minimum index
    for (int i = 1; i <= V; i++)
    {
        if ((!visited[i]) && (minVertex == -1 || distance[minVertex] > distance[i]))
            minVertex = i;
    }
    return minVertex;
}

void Dijkrasta(int s, int V)
{
    int *distance = new int[V];

    for (int i = 1; i <= V; i++)
        distance[i] = INT_MAX; //initially all the vertex are at infinite distance.
    distance[s] = 0;           //distance of source is 0.

    for (int i = 1; i <= V; i++)
    {
        int minVertex = findMinVertex(distance, V);
        visited[minVertex] = 1;

        for (int j = 1; j <= V; j++)
        {
            if ((a[minVertex][j] != 0) && (!visited[j])) //important STEP
            {
                int dist = (distance[minVertex]) + (a[minVertex][j]);
                if (dist < distance[j])
                    distance[j] = dist;
            }
        }
    }

    for (int i = 1; i <= V; i++)
        cout << "Minimum distance from " << s << " to " << i << " is = " << distance[i] << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BellmanFord(int s, int V)
{
    int *distance = new int[V];

    for (int i = 1; i <= V; i++)
        distance[i] = INT_MAX;                  //initially all the vertex are at infinite distance.
    distance[s] = 0;                            //distance of source is 0.

    for (int i = 0; i < V - 1; i++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if ((a[i][j] != 0))
                {
                    int dist = (distance[i]) + (a[i][j]);
                    if (dist < distance[j])
                        distance[j] = dist;
                }
            }
        }
    }

    //Checking a cycle
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if ((a[i][j] != 0))
            {
                int dist = (distance[i]) + (a[i][j]);
                if (dist < distance[j])
                    cout << "There is a negative edge cycle" << endl;
            }
        }
    }
    for (int i = 1; i <= V; i++)
        cout << "Distance from " << s << " to " << i << " is = " << distance[i] << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void Prim(int s, int V)
{
    int *distance = new int[V];
    int *parent = new int[V];
    for (int i = 1; i <= V; i++)
    {
        distance[i] = INT_MAX; //initially all the vertex are at infinite distance.
        parent[i] = -1;        //parent of source vertex is NULL so marking it 1.
    }
    distance[s] = 0;

    for (int i = 1; i <= V; i++)
    {
        int minVertex = findMinVertex(distance, V);
        visited[minVertex] = 1;

        for (int j = 1; j <= V; j++)
        {
            if (a[minVertex][j] != 0 && (!visited[j]))
            {
                if (a[minVertex][j] < distance[j])
                {
                    distance[j] = a[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i <= V; i++)
        cout << "Parent of " << i << " is " << parent[i] << endl;

    for (int i = 1; i <= V; i++)
        cout << "Updated distance from " << s << " to " << i << " is = " << distance[i] << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

int FIND(int i, int *parent)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void UNION(int i, int j, int *parent)
{
    int a = FIND(i, parent);
    int b = FIND(j, parent);
    parent[a] = b;
}

void Kruskal(int s, int V)
{
    int mincost = 0, edges = 0;
    int *parent = new int[V];
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    while (edges < V - 1) //will help to keep track of number of vertex visited.
    {
        int minValue = INT_MAX, u = -1, v = -1;
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (FIND(i, parent) != FIND(j, parent) && a[i][j] < minValue)
                {
                    minValue = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        UNION(u, v, parent);
        cout << "Edge--> " << edges++ << " ( " << u << " ," << v << " )"
             << " : It's cost = " << minValue << endl;
        mincost += minValue;
    }
    cout << "Minimum cost = " << mincost << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

bool isCyclic(int s, int V)
{
    if (visited[s] == 1)
        return true;
    bool FLAG = false;

    if (visited[s] == 0)
    {
        visited[s] = 1;
        for (int i = 1; i <= V; i++)
        {
            if (a[s][i] == 1 && (!visited[i]))
            {
                FLAG = isCyclic(i, V);
                if (FLAG == true)
                    return true;
            }
        }
    }
    return FLAG;
}

int main()
{
    int choice, E, V, e1, e2, i, j;
    cout << "\nEnter the number of vertex : ";
    cin >> V;

    for (i = 1; i <= V; i++)
    {
        for (j = 1; j <= V; j++)
            a[i][j] = 0;
    }

    while (1)
    {
        cout << "\n1. Create Graph" << endl;
        cout << "2. To view array-matrix" << endl;
        cout << "3. DFS Traversal" << endl;
        cout << "4. BFS Traversal" << endl;
        cout << "5. Single Source Shortest Path [Dijkstra]" << endl;
        cout << "6. Single Source Shortest Path []Bellman Ford]" << endl;
        cout << "7. Minimum Spanning Tree - Prims Algorithm" << endl;
        cout << "8. Minimum Spanning Tree - Kruskal's Algorithm" << endl;
        cout << "9. To detect cycle in the graph" << endl;
        cout << "10. EXIT" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            for (i = 1; i <= V; i++)
            {
                while (1)
                {
                    cout << "Enter the edges from " << i << " or press -1 : ";
                    cin >> e2;
                    if (e2 == -1)
                        break;
                    createGraph(i, e2);
                }
            }
            break;
        }

        case 2:
        {
            cout << "Array  matrix of the graph is :" << endl;
            for (i = 1; i <= V; i++)
            {
                for (j = 1; j <= V; j++)
                    cout << a[i][j] << "   ";
                cout << endl;
            }
            break;
        }

        case 3:
        {
            vector<int> visited(V, 0);
            cout << "Graph Traversal is [DFS] : ";
            DFS_recursive(1, V, visited);
            break;
        }

        case 4:
        {
            vector<int> visited(V, 0);
            cout << "Graph Traversal is [BFS] : ";
            BFS(1, V, visited);
            break;
        }

        case 5:
        {
            Dijkrasta(1, V);
            break;
        }

        case 6:
        {
            BellmanFord(1, V);
            break;
        }

        case 7:
        {
            Prim(1, V);
            break;
        }

        case 8:
        {
            for (i = 1; i <= V; i++)
            {
                for (j = 1; j <= V; j++)
                    if (a[i][j] == 0)
                        a[i][j] = INT_MAX;
            }
            Kruskal(1, V);
            a[V][V] = {0};
            cout << "\nPlease create the graph again!" << endl;
            break;
        }

        case 9:
        {
            if (isCyclic(1, V))
                cout << "\nCycle is present" << endl;
            else
                cout << "\nCycle is not present" << endl;
            visited[100] = {0};
            break;
        }

        case 10:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE..." << endl;
        }
    }
    return 0;
}

/*
void shortest_distance(int s , int d , int V , int *distance , vector <int> *ans)
{
    int visited[10] = {0};
    queue <int> q;
    visited[s] = 1;
    q.push(s);
    while( !q.empty() )
    {
        int node = q.front();
        q.pop();
        for(int i=1 ; i<=V ; i++)
        {
            if((a[node][i] == 1) && (visited[i] == 0))
            {
                distance = (distance + 1);
                ans->push_back(i);
                visited[i] = 1;
                q.push(i);

                if(a[node][i] == d)
                    return;
            }
        }
    }
}
*/
