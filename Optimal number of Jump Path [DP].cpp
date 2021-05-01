#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n^2)
Space Complexity : O(n)
*/

int optimalGame(int a[] , int n)
{
    int dp[n];

    //initializing dp array with max value
    //we can also initialize it with null.
    for(int i=0 ; i<n ; i++)
        dp[i]=INT_MAX;

    //base case, when we are the last position.
    dp[n-1] = 0;

    for(int i=n-2 ; i>=0 ; i--)
    {
        //number of steps allowed
        int steps = a[i];
        int minStep = INT_MAX;

        //(i+j < n) as we need to be in the boundary of the array
        for(int j=1 ; j<=steps && (i+j)<n ; j++)
        {
            if((dp[i+j] < minStep) && (dp[i+j] != INT_MAX))
                minStep = dp[i+j];
        }
        if(minStep != INT_MAX)
            dp[i] = minStep+1;
    }
    return dp[0];
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int a[n];
    cout<<"Enter the values :\n";
    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    cout<<"Maximum jumps needed is : "<<optimalGame(a , n)<<endl;
    return 0;
}

