#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n^2)
Space Complexity : O(n*n)
*/

int LPS(string s)
{
    int n = s.size();

    int dp[n][n] = {0};

    for(int gap=0 ; gap<s.length() ; gap++)
    {
        for(int i=0, j=gap ; j<n ; i++, j++)
        {
            //we have only one option to choose when gap is 1
            //as the character itself is the LPS, so put 1
            if(gap == 0)
                dp[i][j] = 1;

            //for the gap is 2 we have two options
            //if both characters are equal then 2, else 1
            else if(gap == 1)
            {
                if(s[i] == s[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
                //or we can simply write:
                //dp[i][j] = s[i] == s[j] ? 2 : 1;
            }
            //for the cases in which gap is more than 1
            else
            {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1] , dp[i+1][j]);
            }
        }
    }

    /*
    //Visualizing the dp array
    for(int i=0 ; i<n ; i++)
    {
        for(int j =0 ; j< n ; j++)
            cout<<dp[i][j]<<"    ";
        cout<<endl;

    */

    return dp[0][n-1];
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"Longest Palindromic Subsequence is of length : "<<LPS(s)<<endl;
    return 0;
}

