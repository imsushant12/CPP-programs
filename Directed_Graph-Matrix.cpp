#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int visited[100] = {0};
int indegree[100] = {0};         //for topology
int a[10][10];
stack <int> stk;

void createGraph(int i , int j , int weight)
{
    a[i][j] = weight;
    indegree[j]++;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void DFS_recursive(int s , int V)
{
    if(visited[s] == 0)
    {
        cout<<s<<"  ";
        visited[s] = 1;
        for(int i=1 ; i<=V ; i++)
        {
            if(a[s][i] != 0)            //means if there is an edge between s and i
                DFS_recursive(i , V);
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BFS(int s , int V)
{
    queue <int> q;
    cout<<s<<"   ";
    visited[s]=1;
    q.push(s);

    while( !q.empty() )
    {
        int node = q.front();
        q.pop();
        for(int i=1 ; i<=V ; i++)
        {
            if((a[node][i] != 0) && (visited[i] == 0))
            {
                cout<<i<<"  ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void topology(int v)
{
    vector <int> result;
    queue <int> q;

    for(int i=1 ; i<=v ; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while( !q.empty() )
    {
        int node = q.front();
        result.push_back(node);
        q.pop();

        for(int i=1 ; i<=v ; i++)
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }

    cout<<"\nTopological Sort = ";
    for(int i=1 ; i<=result.size() ; i++)
        cout<<i<<"  ";
}

//-----------------------------------------------------------------------------------------------------------------------------------

void dfs_topology(int v , int s)
{
    visited[s]=1;
    for(int i=1 ; i<=v ; i++)
        if(!visited[i])
            dfs_topology(v , i);
    stk.push(s);
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BellmanFord(int s , int V)
{
    int* distance = new int[V];

    for(int i=1 ; i<=V ; i++)
        distance[i] = INT_MAX;          //initially all the vertex are at infinite distance.
    distance[s] = 0;                    //distance of source is 0.

    for(int i=0 ; i<V-1  ; i++)
    {
        for(int i=1 ; i<=V ; i++)
        {
            for(int j=1 ; j<=V ; j++)
            {
                if((a[i][j] != 0))
                {
                    int dist = (distance[i]) + (a[i][j]);
                    if(dist < distance[j])
                        distance[j] = dist;
                }
            }
        }
    }

    //Checking a cycle
    for(int i=1 ; i<=V ; i++)
    {
        for(int j=1 ; j<=V ; j++)
        {
            if((a[i][j] != 0))
            {
                int dist = (distance[i]) + (a[i][j]);
                if(dist < distance[j])
                    cout<<"There is a negative edge cycle"<<endl;
            }
        }
    }
    for(int i=1 ; i<=V ; i++)
        cout<<"Distance from "<<s<<" to "<<i<<" is = "<<distance[i]<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

int findMinVertex(int* distance , int V)
{
    int minVertex = -1;      //initially we are assuming that first index in minimum index
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
        distance[i] = INT_MAX;          //initially all the vertex are at infinite distance.
    distance[s] = 0;                    //distance of source is 0.

    for(int i=1 ; i<=V ; i++)
    {
        int minVertex = findMinVertex(distance , V);
        visited[minVertex] = 1;

        for(int j=1 ; j<=V ; j++)
        {
            if((a[minVertex][j] != 0) && (!visited[j]))             //important STEP
            {
                int dist = (distance[minVertex]) + (a[minVertex][j]);
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
            if(a[minVertex][j] != 0 && (!visited[j]))
            {
                if(a[minVertex][j] < distance[j])
                {
                    distance[j] = a[minVertex][j];
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
        int minValue = INT_MAX, u = -1, v = -1;
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (FIND(i , parent) != FIND(j , parent) && a[i][j] < minValue)
                {
                    minValue = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        UNION(u , v , parent);
        cout<<"Edge--> "<<edges++<<" ( "<<u<<" ,"<<v<<" )"<<" : It's cost = "<<minValue<<endl;
        mincost += minValue;
    }
    cout<<"Minimum cost = "<<mincost<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

bool isCyclic(int s , int V)
{
    if(visited[s] == 1)
        return true;
    bool FLAG = false;

    if(visited[s] == 0)
    {
        visited[s]=1;
        for(int i=1 ; i<=V ; i++)
        {
            if(a[s][i] == 1 && (!visited[i]))
            {
                FLAG = isCyclic(i , V);
                if(FLAG == true)
                    return true;
            }
        }
    }
    return FLAG;
}

//-----------------------------------------------------------------------------------------------------------------------------------

/*
void printHamiltonian(int v , vector<int> &path , int N)
{
    if (path.size() == N)
    {
        for (int i : path)
			cout << i << " ";
		cout << endl;

		return;
    }

    for (int w=1 ; w<=N ; w++)
    {
        if (!visited[w])
        {
            if(a[v][w] != 0)
            {
                visited[w] = 1;
                path.push_back(w);
                printHamiltonian(w , path , N);
                visited[w] = 0;
                path.pop_back();
            }
        }
    }
}
*/



int main()
{
    int choice,E,V,e1,e2,i,j,weight;
    cout<<"\nEnter the number of vertex : ";
    cin>>V;

    for(i=1 ; i<=V ; i++)
    {
        for(j=1 ; j<=V ; j++)
            a[i][j]=0;
    }

    while(1)
    {
        cout<<"\n1. Create Directed Graph"<<endl;
        cout<<"2. To view array-matrix"<<endl;
        cout<<"3. DFS Traversal"<<endl;
        cout<<"4. BFS Traversal(undirected)"<<endl;
        cout<<"5. Topological Sorting(using queue)"<<endl;
        cout<<"6. Topological Sorting(using stack)"<<endl;
        cout<<"7. Single Source Shortest Path(Bellman Ford)"<<endl;
        cout<<"8. Single Source Shortest Path(Dijkstra)"<<endl;
        cout<<"9. Minimum Spanning Tree - Prims Algorithm"<<endl;
        cout<<"10. Minimum Spanning Tree - Kruskal Algorithm"<<endl;
        cout<<"11. To detect cycle in the graph"<<endl;
        cout<<"12. EXIT"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {/*
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
                }*/
                    createGraph(1,2,1);
                    createGraph(1,3,1);
                    createGraph(2,3,1);
                    createGraph(2,4,1);
                    createGraph(3,5,1);
                    createGraph(5,4,1);
                       break;
            }

        case 2:
            {
                cout<<"Array  matrix of the graph is :"<<endl;
                for(i=1 ; i<=V ; i++)
                {
                    for(j=1 ; j<=V ; j++)
                        cout<<a[i][j]<<"  ";
                    cout<<endl;
                }
                break;
            }

        case 3:
            {
                cout<<"Graph Traversal is : ";
                for (int i=1 ; i<=V ; i++)
                {
                    DFS_recursive(i , V);
                    visited[i] = 0;
                }
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
                topology(V);
                visited[100] = {0};
                break;
            }

        case 6:
            {
                dfs_topology(V , 1);
                while( !stk.empty() )
                {
                    cout<<stk.top()<<"  ";
                    stk.pop();
                }
                visited[100] = {0};
                break;
            }

        case 7:
            {
                Dijkrasta(1 , V);
                visited[100] = {0};
                break;
            }

        case 8:
            {
                BellmanFord(1 , V);
                visited[100] = {0};
                break;
            }

        case 9:
            {
                Prim(1 , V);
                visited[100] = {0};
                break;
            }

        case 10:
            {
                for(i=1 ; i<=V ; i++)
                {
                    for(j=1 ; j<=V ; j++)
                        if(a[i][j] == 0)
                            a[i][j] = INT_MAX;
                }
                Kruskal(1 , V);
                a[V][V] = {0};
                cout<<"\nPlease create the graph again!"<<endl;
                break;
            }

        case 11:
            {
                if(isCyclic(1 , V))
                    cout<<"\nCycle is present"<<endl;
                else
                    cout<<"\nCycle is not present"<<endl;
                visited[100] = {0};
                break;
            }

        case 12:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE..."<<endl;
        }
    }
    return 0;
}

