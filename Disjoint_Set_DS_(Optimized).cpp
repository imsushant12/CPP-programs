#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node
{
    int parent;
    int r;
};
vector <node> Set;

int Find(int n)
{
    if(Set[n].parent == -1)
        return n;
    return Set[n].parent = Find(Set[n].parent);               //path compression
}

void Union(int data1 , int data2)
{
    if(Set[data1].r > Set[data2].r)
        Set[data2].parent = data1;
    else if(Set[data1].r < Set[data2].r)
        Set[data1].parent = data2;
    else
    {
        //Both have same rank so anyone can be made parent
        Set[data1].parent = data2;
        Set[data2].r++;
    }
}

int main()
{
    int n,i,choice,data,data1,data2;
    cout<<"Enter number of elements : ";
    cin>>n;
    Set.resize(n);
    cout<<"\nEnter elements : ";
    for(i=0 ; i<n ; i++)
    {
        cin>>data;
        Set[data].parent = -1;                 //make-set basically
        Set[data].r=0;
    }

    while(1)
    {
        cout<<"\n1. Find";
        cout<<"\n2. Union";
        cout<<"\n3. EXIT";
        cout<<"\nEnter choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                cout<<"\nEnter element to find its parent : ";
                cin>>data;
                cout<<"\nParent is = "<<Find(data);
                break;
            }

        case 2:
            {
                cout<<"\nEnter elements for union: ";
                cin>>data1>>data2;
                Union(data1 , data2);
                break;
            }

        case 3:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE\n";
        }

    }
    return 0;
}
