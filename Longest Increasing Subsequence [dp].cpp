#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(n^2)
//Space Complexity: O(n)
void LIS(int a[] , int n)
{
    int dp[n] = {0};
    dp[0] = 1;

    //int overallMax = 0;

    for(int i=1 ; i<n ; i++)
    {
        int maxValue = 0;
        //checking all the numbers smaller than current number i.e. ->i
        //and finding max of all the numbers before i
        for(int j=0 ; j<i ; j++)
            if(a[j] < a[i])
                if(dp[j] > maxValue)
                    maxValue = dp[j];

        dp[i] = maxValue+1;
        /*
        //Basically we are finding the maximum value of the dp array
        if(dp[i] > overallMax)
            overallMax = dp[i];
        //Or we can simply use *max_element(dp,dp+n)
        */
    }
    cout<<"Longest Increasing Subsequence is : "<<*max_element(dp,dp+n)<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int a[n];
    cout<<"Enter the array : \n";
    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    LIS(a , n);

    return 0;
}
