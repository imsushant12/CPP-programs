#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n*n), n is number of coins and w is sum to be paid
Space Complexity : O(n*n)
*/
int findSquare(int n)
{
    if(n <= 3)
        return n;

    int dp[n+1];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4 ; i<=n ; i++)
    {
        //max value is i as i can always be represented as 1*1 + 1*1 + ...
        dp[i] = i;

        for(int x=1 ; x<=sqrt(i) ; x++)
        {
            int temp = x*x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i] , 1 + dp[i-temp]);
        }
    }
    return dp[n];
}

int main()
{
    int sum;
    cout<<"Enter the sum : ";
    cin>>sum;

    cout<<"Minimum number of squares to form "<<sum<<" is : "<<findSquare(sum)<<endl;

    return 0;
}

