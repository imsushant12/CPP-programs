#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue <int> q;
    int a[]={11,12,13,14,15,16,17,18,19,20};
    int b[10];
    int i=0,n=10;
    int l=n/2;
    while(i != n)
    {
        q.push(a[i]);
        q.push(a[i+l]);
        i++;
    }
    for(i=0;i<n;i++)
    {
        b[i]=q.front();
        q.pop();
    }
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
}
