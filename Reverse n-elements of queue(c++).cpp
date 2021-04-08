#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue <int> q;
    int a[]={10,20,30,40,50,60,70,80,90};
    queue <int> disp;                           //for display
    int i,n=9,k=4;

    for(i=k-1; i >= 0 ; i--)
        q.push(a[i]);

    for(i=k ; i < n ; i++)
        q.push(a[i]);

    disp=q;

    for(i=0 ; i<n ; i++)
    {
        a[i]=disp.front();
        disp.pop();
    }

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}

