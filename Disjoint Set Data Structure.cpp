#include<iostream>
#include<stdlib.h>
using namespace std;

//Brute force approach:

void makeset(int a[] , int n)
{
    for(int i=n-1 ; i>=0 ; i--)
        a[i]=i;
}

int findset(int a[] , int data)
{
    while(1)
    {
        if(a[data] == data)
            return data;
        else
            return(findset(a , a[data]));                       //because a[data] contains parent of data
    }
}

void unionset(int a[] , int data1 , int data2)
{
    if(findset(a , data1) == findset(a, data2))
        return;
    else
        a[data1] = data2;
}

int main()
{
    int n,choice,data,data1,data2;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter array : ";
    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    makeset(a , n);

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
                cout<<"\nEnter element to find parent : ";
                cin>>data;
                cout<<"\nParent is = "<<findset(a , data);

                break;
            }

        case 2:
            {
                cout<<"\nEnter elements for union: ";
                cin>>data1>>data2;
                unionset(a , data1 , data2);

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
