#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int i=1,tests=0,sum=0,j=0;
    cin>>tests;
    int n[tests];
    for(j=0;j<tests;j++)
        cin>>n[j];
    for(j=0;j<tests;j++)
    {
        for(i=1;i<n[j];i++)
        {
            if(n[j]%i==0)
                sum = sum + i;
        }
        if(sum==n[j])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        sum=0;
        i=1;
    }
    return 0;
}
