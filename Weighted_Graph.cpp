#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

int visited[100] = {0};
int graph[10][10];

void createGraph(int i , int j , int weight)
{
    graph[i][j] = weight;
    graph[j][i] = weight;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void DFS_recursive(int s , int V)
{
    if(visited[s] == 0)
    {
        cout<<s<<"  ";
        visited[s]=1;
        for(int i=1 ; i<=V ; i++)
        {
            if(graph[s][i] != 0)            //means if there is an edge between s and i
                DFS_recursive(i , V);
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BFS(int s , int V)
{
    queue <int> q;
    cout<<s<<"   ";
    visited[s] = 1;
    q.push(s);
    while( !q.empty() )
    {
        int node = q.front();
        q.pop();
        for(int i=1 ; i<=V ; i++)
        {
            if((graph[node][i] != 0) && (visited[i] == 0))
            {
                cout<<i<<"  ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

int findMinVertex(int* distance , int V)
{
    int minVertex = -1;                     //initially we are assuming that first index in minimum index
    for(int i=1 ; i<=V ; i++)
    {
        if((!visited[i]) && (minVertex == -1 || distance[minVertex] > distance[i]))
            minVertex = i;
    }
    return minVertex;
}

void Dijkrasta(int s , int V)
{
    int* distance = new int[V];

    for(int i=1 ; i<=V ; i++)
        distance[i] = INT_MAX;              //initially all the vertex are at infinite distance.
    distance[s] = 0;                        //distance of source is 0.

    for(int i=1 ; i<=V ; i++)
    {
        int minVertex = findMinVertex(distance , V);
        visited[minVertex] = 1;

        for(int j=1 ; j<=V ; j++)
        {
            if((graph[minVertex][j] != 0) && (!visited[j]))             //important STEP
            {
                int dist = (distance[minVertex]) + (graph[minVertex][j]);
                if(dist < distance[j])
                    distance[j] = dist;
            }
        }
    }

    for(int i=1 ; i<=V ; i++)
        cout<<"Distance from "<<s<<" to "<<i<<" is = "<<distance[i]<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void Prim(int s , int V)
{
    int* distance = new int[V];
    int* parent = new int[V];
    for(int i=1 ; i<=V ; i++)
    {
        distance[i] = INT_MAX;              //initially all the vertex are at infinite distance.
        parent[i] = -1;                     //parent of source vertex is NULL so marking it 1.
    }
    distance[s] = 0;

    for(int i=1 ; i<=V ; i++)
    {
        int minVertex = findMinVertex(distance , V);
        visited[minVertex] = 1;

        for(int j=1 ; j<=V ; j++)
        {
            if(graph[minVertex][j] != 0 && (!visited[j]))
            {
                if(graph[minVertex][j] < distance[j])
                {
                    distance[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i=1 ; i<=V ; i++)
        cout<<"Parent of "<<i<<" is "<<parent[i]<<endl;

    for(int i=1 ; i<=V ; i++)
        cout<<"Updated distance from "<<s<<" to "<<i<<" is = "<<distance[i]<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

int FIND(int i , int* parent)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void UNION(int i , int j , int* parent)
{
    int a = FIND(i , parent);
    int b = FIND(j , parent);
    parent[a] = b;
}

void Kruskal(int s , int V)
{
    int mincost=0;
    int* parent = new int[V];
    for(int i=1 ; i<=V ; i++)
        parent[i] = i;

    int edges=0;                  //will help to keep track of number of vertex visited.
    while(edges < V-1)
    {
        int minValue = INT_MAX, a = -1, b = -1;
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (FIND(i , parent) != FIND(j , parent) && graph[i][j] < minValue)
                {
                    minValue = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        UNION(a , b , parent);
        cout<<"Edge--> "<<edges++<<" ( "<<a<<" ,"<<b<<" )"<<" : It's cost = "<<minValue<<endl;
        mincost += minValue;
    }
    cout<<"Minimum cost = "<<mincost<<endl;
}


int main()
{
    int choice,E,V,e1,e2,i,j,weight;
    cout<<"\nEnter the number of vertex : ";
    cin>>V;

    for(i=1 ; i<=V ; i++)
    {
        for(j=1 ; j<=V ; j++)
            graph[i][j] = 0;
    }

    while(1)
    {
        cout<<"\n1. Create Graph"<<endl;
        cout<<"2. To view array-matrix"<<endl;
        cout<<"3. DFS Traversal"<<endl;
        cout<<"4. BFS Traversal"<<endl;
        cout<<"5. Single Source Shortest Path(Dijkstra)"<<endl;
        cout<<"6. Prims Algorithm - MST"<<endl;
        cout<<"7. Prims Algorithm - MST"<<endl;
        cout<<"8. EXIT"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                for(i=1 ; i<=V ; i++)
                {
                    while(1)
                    {
                        cout<<"Enter the edges from '"<<i<<"' or press -1 : ";
                        cin>>e2;
                        if(e2 == -1)
                            break;
                        cout<<"Enter weight : ";
                        cin>>weight;
                        createGraph(i , e2 , weight);
                    }
                }
                break;
            }

        case 2:
            {
                cout<<"Array  matrix of the graph is :"<<endl;
                for(i=1 ; i<=V ; i++)
                {
                    for(j=1 ; j<=V ; j++)
                        cout<<graph[i][j]<<"   ";
                    cout<<endl;
                }
                break;
            }

        case 3:
            {
                cout<<"Graph Traversal is : ";
                DFS_recursive(1 , V);
                visited[100] = {0};
                break;
            }

        case 4:
            {
                cout<<"Graph Traversal is : ";
                BFS(1 , V);
                visited[100] = {0};
                break;
            }

        case 5:
            {
                Dijkrasta(1 , V);           //passing source and number of vertex
                break;
            }

        case 6:
            {
                Prim(1 , V);
                visited[100] = {0};
                break;
            }

        case 7:
            {
                for(i=1 ; i<=V ; i++)
                {
                    for(j=1 ; j<=V ; j++)
                        if(graph[i][j] == 0)
                            graph[i][j] = INT_MAX;
                }
                Kruskal(1 , V);
                graph[V][V] = {0};
                cout<<"\nPlease create the graph again!"<<endl;
                break;
            }

        case 8:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE..."<<endl;
        }
    }
    return 0;
}
