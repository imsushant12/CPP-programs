#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n*w).
Space Complexity: O(n*w).
*/

int KS_01(int W[] , int P[] , int wt , int n)
{
    int dp[n+1][wt+1];

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=wt ; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            //The condition when we can accommodate the weight
            //i.e. we can take or leave it, so maximum of the two.
            else if(W[i-1] <= wt)
                dp[i][j] = max(dp[i-1][j] , (P[i-1] + dp[i-1][j - W[i-1]]));
            //The case in which we skip the current value
            //current weight of the bag (j) is less than weight at i-1 , j.
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][wt];
}

int main()
{
    int n;
    cout<<"Enter size of the weight/profit array : ";
    cin>>n;

    int wt;
    cout<<"Enter weight of the carry-bag : ";
    cin>>wt;

    int P[n] , W[n];

    cout<<"Enter weights : ";
    for(int i=0 ; i<n ; i++)
        cin>>W[i];
    cout<<"Enter profits: ";
    for(int i=0 ; i<n ; i++)
        cin>>P[i];

    cout<<"Maximum weight that can be assigned is : "<<KS_01(W , P , wt , n);

    return 0;
}
