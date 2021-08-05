#include <bits/stdc++.h>
#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
    int V;
    //Array of lists
    //we don't know the size of array so using pointer to allocate memory dynamically.
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; //important, dynamically allocating memory
    }

    void addEdges(int e1, int e2)
    {
        l[e1].push_back(e2);
        l[e2].push_back(e1);
    }

    void display(int V)
    {
        cout << "List representation is : " << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << " --> ";
            list<int>::iterator it;
            for (it = l[i].begin(); it != l[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);

    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 3);

    g.display(4);

    return 0;
    /*
    Graph:
             1
           / \
         /   \
        0----2
            |
           |
          3
    */
}
