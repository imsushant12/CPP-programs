#include <bits/stdc++.h>
using namespace std;

//Time complexity : O(n*target)
//Space Complexity: O(n*target)
void subsetSum(int a[] , int n , int target)
{
    int dp[n+1][target+1] = {0};
    //for traversing rows that contains sum/target
    for(int i=0 ; i<=n; i++)
    {
        //for traversing the numbers of array
        for(int j=0 ; j<=target ; j++)
        {
            //when numbers and target both are 0
            if(i==0 && j==0)
                dp[i][j] = 1;
            //when the target itself is 0, we cannot find any subset
            else if(i==0)
                dp[i][j] = 0;
            //when we have numbers but no target
            else if(j==0)
                dp[i][j] = 1;
            //the actual case to find the subset
            else
            {
                //if we have found target before the current number
                //so basically we have a subset whose sum is target
                if(dp[i-1][j] == 1)
                    dp[i][j] = 1;
                //we haven't found the subset till now
                //so we need to consider current value
                else
                {
                    //calculating the rest value to get the target
                    int restValue = a[i-1];
                    if(j >= restValue)
                        if(dp[i-1][j-restValue] == 1)
                            dp[i][j] = 1;
                }
            }
        }
    }
    if(dp[n][target] == 1)
        cout<<"There are 2 subsets whose sum are equal.\n";
    else
        cout<<"No such subset is found.\n";
}

int main()
{
    int n;
    cout<<"Enter size of the array : ";
    cin>>n;

    int a[n];
    cout<<"Enter the array: \n";
    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    int sum = 0;
    for(int i=0 ; i<n ; i++)
        sum += a[i];

    if(sum%2 == 0)
        subsetSum(a , n , sum/2);
    else
        cout<<"No such subset is found.\n";

    return 0;
}
