#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int tests=0,i=0;
    cin>>tests;

    int a[tests] , b[tests] , c[tests] , k[tests];

    for(i = 0 ; i < tests ; i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }

    for(i = 0 ; i < tests ; i++)
    {
        if(a[i]>b[i])
        {
            if(a[i] > c[i])
                k[i]=a[i];
        else
            k[i]=c[i];
        }
        else
        {
            if(b[i]>c[i])
                k[i]=b[i];
            else
                k[i]=c[i];
        }

    }
    for(i = 0 ; i < tests ; i++)
    {
        cout<<k[i]<<endl;
    }
    return 0;
}

