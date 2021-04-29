#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n^2)
Space Complexity : O(n)
*/

void findChanges(int changes[] , int sum , int n)
{
    int dp[sum+1] = {0};
    dp[0] = 1;     //because there is always one way to pay 0

    //iterating over the whole array fr each coin
    for(int i=0 ; i<n ; i++)
    {
        //iterating over the dp array from the current value of coin
        for(int j=changes[i] ; j<=sum ; j++)
        {
            dp[j] += dp[j - changes[i]];
        }
    }
    cout<<"Number of ways to pay "<<sum<<" is : "<<dp[sum]<<endl;
}

int main()
{
    int n;
    cout<<"Enter total number of different coins : ";
    cin>>n;

    int sum;
    cout<<"Enter the sum : ";
    cin>>sum;

    int changes[n];
    cout<<"Enter the coins : "<<endl;
    for(int i=0 ; i<n ; i++)
        cin>>changes[i];

    findChanges(changes , sum , n);

    return 0;
}
