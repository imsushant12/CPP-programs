#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/

int tiling(int n)
{
    int dp[n];

    //when length of tile is same as floor, we have only one option
    dp[0] = 1;

    //when length of floor is twice breadth, we have two options
    dp[1] = 2;

    //other cases
    for(int i=2 ; i<n ; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n-1];
}

int main()
{
    int n;
    cout<<"Enter the length of the floor : ";
    cin>>n;

    cout<<"Number of ways to tile the floor is : "<<tiling(n)<<endl;
    return 0;
}

