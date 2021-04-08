#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int visited[100] = {0};
int indegree[100] = {0};
int degree[100] = {0};
vector <int> graph[100];
vector <int> rev_graph[100];
vector <int> result;

void createGraph(vector <int> graph[] , int i , int j)              //list STL can be used as well
{
    graph[i].push_back(j);
    indegree[i]++;
    degree[i]++;        //this will help in the Euler graph
    degree[j]++;
    graph[j].push_back(i);
}

//-----------------------------------------------------------------------------------------------------------------------------------

void display(vector<int> graph[], int v)
{
    for(int i=1 ; i<=v ; i++)
    {
        cout << i << "--->";
        vector<int> :: iterator it;
        for(it = graph[i].begin(); it != graph[i].end(); ++it)
            cout << *it << " ";
        cout << endl;
   }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void DFS_iterative(int s)
{
    stack <int> stk;
    stk.push(s);
    visited[s] = 1;

    while(!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        cout<<node<<"  ";

        //important -> checking first vector then second so on..
        for(int i=1 ; i<graph[node].size() ; i++)
        {
            if(!visited[ graph[node][i] ])
            {
                stk.push(graph[node][i]);
                visited[ graph[node][i] ] = 1;
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BFS(int s , int V)
{
    queue <int> q;
    cout<<s<<"  ";
    visited[s] = 1;
    q.push(s);
    while( !q.empty() )
    {
        int node = q.front();
        q.pop();
        for(int i=1 ; i<graph[node].size() ; i++)
        {
            if( !visited[ graph[node][i] ] )
            {
                cout<<graph[node][i]<<"  ";
                visited[ graph[node][i]  ] = 1;
                q.push( graph[node][i] );
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

void Euler_DFS(int curr)
{
	visited[curr] = 1;
	for(auto it: graph[curr])
	{
		if(!visited[it])
			Euler_DFS(it);
	}
}

bool connected(int V)
{
    int node = -1;
    for(int i=0 ; i<V ; i++)
    {
        if(graph[i].size() > 0)
        {
            node = i;
            break;
        }
    }
    if(node == -1)
        return true;

    Euler_DFS(node);

    for(int i=0 ; i<V ; i++)
    {
        if((visited[i] == 0) && (graph[i].size() > 0))
            return false;
    }
    return true;
}

int Euler(int V)
{
    if(!connected(V))
        return 0;

    int odd=0;
    for(int i=0 ; i<V ; i++)
    {
        if((graph[i].size()) & 1)
            odd += 1;
    }

    if(odd > 2)
        return 0;

    return (odd == 0) ? 2 : 1 ;	    //1->Semi-Eulerian...2->Eulerian
}

void check_Euler(int V)
{
    int ans = Euler(V);

    if(ans == 0)
        cout<<"\nThis is not a Euler Graph"<<endl;
    else if(ans == 1)
        cout<<"\nThis is Semi-Euler Graph"<<endl;
    else
        cout<<"\nThis is an Euler Graph"<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void DFS1(int i , stack<int> &mystack)
{
	visited[i] = 1;
	for(int j : graph[i])
		if(visited[j] == 0)
			DFS1(j , mystack);

	mystack.push(i);
}

void reverse_stack(int V)
{
	for(int i=0 ; i<V ; i++)
	{
		for(int j: graph[i])
			rev_graph[j].push_back(i);
	}
}

void DFS2(int i)
{
	cout<<i<<" ";
	visited[i] = 1;
	for(int j: rev_graph[i])
		if(!visited[j])
			DFS2(j);
}

void Kosaraju(int V)
{
	stack<int> mystack;

	for(int i=0 ; i<V ; i++)
		if(!visited[i])
			DFS1(i , mystack);

	reverse_stack(V);

	for(int i=0 ; i<V ; i++)
		visited[i] = 0;

	cout<<"\nStrongly Connected Components are :\n";
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr] == 0)
		{
			DFS2(curr);
			cout<<endl;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------

void printPath(vector <int> const &path)
{
    for (int i: path)
        cout << i <<" ";
    cout << endl;
}

void printAllHamiltonianPaths(int v , vector<int> &path , int N)
{
    if(path.size() == N)                // && path[0]== path[N-1]
    {
        printPath(path);
        return;
    }

    for (int w : graph[v])
    {
        if (!visited[w])
        {
            visited[w] = 1;
            path.push_back(w);

            printAllHamiltonianPaths(w , path , N);

            visited[w] = 0;
            path.pop_back();
        }
    }
}


int main()
{
    int choice,V,e,i;
    cout<<"\nEnter the number of vertex : ";
    cin>>V;

    while(1)
    {
        cout<<"\n1. Create Graph"<<endl;
        cout<<"2. To view List-matrix"<<endl;
        cout<<"3. DFS Traversal"<<endl;
        cout<<"4. BFS Traversal"<<endl;
        cout<<"5. Check for Euler Graph"<<endl;
        cout<<"6. Print strongly connected components"<<endl;
        cout<<"7. Print Hamiltonian Path"<<endl;
        cout<<"8. EXIT"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                /*
                for(i=1 ; i<=V ; i++)
                {
                    while(1)
                    {
                        cout<<"Enter the edges from '"<<i<<"' or press -1 : ";
                        cin>>e;
                        if(e == -1)
                            break;
                        createGraph(graph , i , e);
                    }
                }
                */
                    createGraph(graph,1,2);
                    createGraph(graph,1,3);
                    createGraph(graph,2,3);
                    createGraph(graph,2,4);
                    createGraph(graph,3,5);
                    createGraph(graph,5,4);
            break;
            }

        case 2:
            {
                display(graph , V);
                break;
            }

        case 3:
            {
                cout<<"Graph Traversal is : ";
                DFS_iterative(1);
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
                check_Euler(V);
                visited[100] = {0};
                break;
            }

        case 6:
            {
                Kosaraju(V);
                visited[100] = {0};
                break;
            }

        case 7:
            {
                vector <int> path;
                printAllHamiltonianPaths(1 , path , V);
                visited[100] = 0;
                break;
            }

        case 8:
            {
                exit(0);
                break;
            }

        default:
            cout<<"\nINVALID CHOICE..."<<endl;
        }
    }
    return 0;
}

