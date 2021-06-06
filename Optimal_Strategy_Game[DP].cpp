#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n^2)
Space Complexity : O(n*n)
*/

int optimalGame(int a[] , int n)
{
    int dp[n][n];

    for(int gap=0 ; gap<n ; gap++)
    {
        for(int i=0, j=gap ; j<n ; i++, j++)
        {
            //we have only one option to choose
            if(gap == 0)
                dp[i][j] = a[i];

            //will choose maximum of the a[i] and a[j]
            else if(gap == 1)
            {
                dp[i][j] = max(a[i] , a[j]);
            }
            //for the cases in which number of nodes is greater than 3
            else
            {
                int val1 = a[i] + min(dp[i+2][j] , dp[i+1][j-1]);
                //choice is : i ---->  i+1 , j
                //------------------------------
                //either i+1 -->  i+2 , j
                //or     j   -->  i+1 , j-1
                int val2 = a[j] + min(dp[i+1][j-1] , dp[i][j-2]);
                //choice is : j ---->  i , j-1
                //-------------------------------
                //either i   -->  i+1 , j-1
                //or     j-1 -->  i   , j-2

                dp[i][j] = max(val1 , val2);
            }
        }
    }
    return dp[0][n-1];
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

    cout<<"Maximum possible choice that can be made is : "<<optimalGame(a , n)<<endl;
    return 0;
}
