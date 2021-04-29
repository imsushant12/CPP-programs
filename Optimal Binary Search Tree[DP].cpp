#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n^3)
Space Complexity : O(n*n)
*/

int optimalBST(int a[] , int freq[] , int n)
{
    int dp[n][n];

    for(int gap=0 ; gap<n ; gap++)
    {
        for(int i=0, j=gap ; j<n ; i++, j++)
        {
            if(gap == 0)
                dp[i][j] = freq[i];

            else if(gap == 1)
            {
                int f1 = freq[i];
                int f2 = freq[j];

                dp[i][j] = min((2*f1 + f2) , (f1 + 2*f2));
            }
            //for the cases in which number of nodes is greater than 3
            else
            {
                int minValue = INT_MAX;

                int freqSum = 0;
                for(int x=i ; x<=j ; x++)
                    freqSum += freq[x];

                for(int k=i ; k<=j ; k++)
                {
                    int left = k == i ? 0 : dp[i][k-1];
                    int right = k == j ? 0 : dp[k+1][j];
                    //checking or the minimum value
                    if(left+right+freqSum < minValue)
                        minValue = left + right + freqSum;
                }
                dp[i][j] = minValue;
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
    cout<<"Enter the nodes :\n";
    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    int freq[n];
    cout<<"Enter the frequencies of nodes :\n";
    for(int i=0 ; i<n ; i++)
        cin>>freq[i];

    cout<<"Least comparisons required are : "<<optimalBST(a , freq , n)<<endl;
    return 0;
}
