#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n^2)
Space Complexity : O(n^n)
*/
int LPString(string s)
{
    int n = s.size();
    int dp[n][n] = {0};

    int len = 0;

    for(int gap=0 ; gap<s.length() ; gap++)
    {
        for(int i=0, j=gap ; j<n ; i++, j++)
        {
            //we have only one option to choose when gap is 1
            //as the character itself is the LPS, so put 1
            if(gap == 0)
                dp[i][j] = 1;

            //for the gap is 2 we have two options
            //if both characters are equal then true, else false
            else if(gap == 1)
                dp[i][j] = s[i] == s[j] ? 1 : 0;

            //for the cases in which gap is more than 1
            else
            {
                if((s[i]==s[j]) && (dp[i+1][j-1]==1))
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            //updating longest length
            if(dp[i][j])
                len = gap + 1 ;
        }
    }
    return len;
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"Longest Palindromic Substring is of length : "<<LPString(s)<<endl;
    return 0;
}
