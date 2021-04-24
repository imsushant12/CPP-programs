#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O((W+1)*N)
//Space Complexity: O(W+1).
int UKS(int W[], int P[], int wt, int n)
{
    //initializing the array with 0.
    int dp[wt+1] = {0};

    for(int currentWt=0 ; currentWt<=wt ; currentWt++)
    {
        //Traversing the weight array
        for(int i=0 ; i<n ; i++)
        {
            //accommodation case
            if(W[i] <= currentWt)
                dp[currentWt] = max(dp[currentWt] , dp[currentWt-W[i]] + P[i]);
        }
    }
    return dp[wt];
}

int main()
{
    int n;
    cout<<"Enter size of the weight/profit array : ";
    cin>>n;

    int wt;
    cout<<"Enter weight of the carry-bag : ";
    cin>>wt;

    int P[n] , W[n];

    cout<<"Enter weights : ";
    for(int i=0 ; i<n ; i++)
        cin>>W[i];
    cout<<"Enter profits: ";
    for(int i=0 ; i<n ; i++)
        cin>>P[i];

    cout<<"Maximum weight that can be assigned is : "<<UKS(W , P , wt , n);

    return 0;
}
