#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/

int tiling(int n , int m)
{
    int dp[n+1];

    for(int i=1 ; i<=n ; i++)
    {
        if(i<m)
            dp[i] = 1;
        else if(i == m)
            dp[i] = 2;
        else
            dp[i] = dp[i-1] + dp[i-m];
    }
    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the length of the floor : ";
    cin>>n;

    int m;
    cout<<"Enter the width of the floor : ";
    cin>>m;

    cout<<"Number of ways to tile the floor is : "<<tiling(n , m)<<endl;
    return 0;
}

