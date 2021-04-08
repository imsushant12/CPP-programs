#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    int tests=0,i=0;
    cin>>tests;
    int x[tests];

    for(i = 0 ; i < tests ; i++)
        cin>>x[i];

    for(i = 0 ; i < tests ; i++)
    {
        cout<<x[i]*x[i]<<endl;
    }
    return 0;
}

