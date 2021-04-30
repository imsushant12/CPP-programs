#include <bits/stdc++.h>
using namespace std;

#define N 6
#define M 5

/*
Time Complexity  : O(m*n)
Space Complexity : O(m*n)
*/

int maximumMatrix(int a[][6])
{
    int dp[M][N];

    int maxlen = 0;

    for(int i=M-1 ; i>=0 ; i--)
    {
        for(int j=N-1 ; j>=0 ; j--)
        {
            //for the last cell i.e. column is (n-1) and row is (m-1)
            if(i == M-1 && j == N-1)
                dp[i][j] = a[i][j];

            //for the last row
            else if(i == M-1)
                dp[i][j] = a[i][j];

            //for the last column
            else if(j == N-1)
                dp[i][j] = a[i][j];

            //for the rest of the cell, compare the diagonal, below and right cell
            //to find the minimum of them and 1 to the result.
            else
            {
                if(a[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    int right = dp[i+1][j];
                    int diagonal = dp[i+1][j+1];
                    int below = dp[i][j+1];

                    int result = min(diagonal , min(right , below));

                    dp[i][j] = result+1;

                    //finding the maximum length of the square
                    if(dp[i][j] > maxlen)
                        maxlen = dp[i][j];
                }
            }
        }
    }

    for(int i=0 ; i<M ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout<<dp[i][j]<<"    ";
        }
        cout<<endl;
    }
    return maxlen;
}

int main()
{
    int matrix[M][N] =
    {
        { 0 , 1 , 0 , 1 , 0 , 1 },
        { 1 , 0 , 1 , 0 , 1 , 0 },
        { 0 , 1 , 1 , 1 , 1 , 0 },
        { 0 , 0 , 1 , 1 , 1 , 0 },
        { 1 , 1 , 1 , 1 , 1 , 1 }
    };

    cout<<"Maximum possible size possible is : "<<maximumMatrix(matrix);
    return 0;
}

