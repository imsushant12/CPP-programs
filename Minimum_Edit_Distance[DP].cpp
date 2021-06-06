#include <bits/stdc++.h>
using namespace std;

void minEditDistance(string a , string b)
{
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=m ; j++)
        {
            //string1 is empty, we can only insert
            if(i == 0)
                dp[i][j] = j;

            //string2 is empty, we can only delete
            else if(j == 0)
                dp[i][j] = i;

            else
            {
                //if character is same, no new operation is to be performed.
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                //if characters are different then find the minimum
                else
                {
                    int insertion = dp[i][j-1];
                    int deletion = dp[i-1][j];
                    int replacement = dp[i-1][j-1];

                    dp[i][j] = 1 + min(replacement , min(insertion , deletion));
                }
            }
        }
    }
    cout<<"\nMinimum numbers of operations needed is : "<<dp[n][m]<<endl;
}

int main()
{
    string a,b;

    cout<<"Enter the first string : ";
    cin>>a;
    cout<<"Enter the first string : ";
    cin>>b;

    minEditDistance(a , b);

    return 0;
}
