#include <bits/stdc++.h>
using namespace std;

void KadanesAlgo(int a[] , int n)
{
    int currSum = 0;
    int maxSum = 0;

    for(int i=0 ; i<n ; i++)
    {
        currSum += a[i];
        if(currSum > maxSum)
            maxSum = currSum;
        if(currSum < a[i])
            currSum = a[i];
    }

    cout<<"Maximum sum is : "<<maxSum<<endl;
}

int main()
{
    int a[] = {-5 , 4 , 6 , -3 , 4 , -1};
    int n = sizeof(a) / sizeof(a[0]);

    KadanesAlgo(a , n);

    return 0;
}
