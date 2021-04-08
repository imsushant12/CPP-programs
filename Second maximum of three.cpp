#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int tests=0,i=0;
    cin>>tests;
    int a[tests],b[tests],c[tests],result[tests];
    for(i=0;i<tests;i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    for(i=0;i<tests;i++)
    {
        if(a[i]>b[i] && a[i]<c[i])
            result[i]=a[i];
        else if(b[i]>a[i] && b[i]<c[i])
            result[i]=b[i];
        else
            result[i]=c[i];
    }
    for(i=0;i<tests;i++)
        cout<<result[i]<<endl;

}
