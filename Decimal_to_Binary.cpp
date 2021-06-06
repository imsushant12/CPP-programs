#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    int rem,tests,i;
    cin>>tests;
    int number[tests];
    for(i = 0 ;i < tests ; i++)
        cin>>number[i];
    for(i = 0 ; i < tests ; i++)
    {
        while(number[i] > 0)
        {
            rem = number[i] %2;
            number[i] = number[i] /2;
            s.push(rem);
        }
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
