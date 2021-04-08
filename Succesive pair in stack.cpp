#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    stack <int> s1,s2;
    int i,n,x,count=1;

    int a[]={4,5,-2,-3,11,10,5,6,20};
    n=9;

    for(i=0 ; i<n ; i++)
        s1.push(a[i]);

    while(!s1.empty())
    {
        i=0;
        a[i]=s1.top();
        s1.pop();
        s2.push(a[i]);
        i++;
    }

    if(!s2.empty())
    {
        int m=s2.top();
        s2.pop();
        int n=s2.top();
        s2.pop();
        if(abs (n-m) != 1)
            count=0;
    }

    if(count == 1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
