#include <bits/stdc++.h>
using namespace std;

/*
//Brute Force - O(n*n)
int maxIndexDiff(int a[] , int n)
{
    int maxdiff = -1;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=0 ; j--)
        {
            if(a[j] > a[i]  &&  maxdiff < (j-1))
                maxdiff = j-i;
        }
    }
    return maxdiff;
}
*/

//Optimized Solution - O(n)
int maxIndexDiff(int a[] , int n)
{
    int LMin[n] , RMax[n];

    LMin[0] = a[0];
    for(int i=1 ; i<n ; i++)
        LMin[i] = min(a[i] , LMin[i-1]);

    RMax[n-1] = a[n-1];
    for(int i=(n-2) ; i>=0 ; i--)
        RMax[i] = max(a[i] , RMax[i+1]);

    int i=0 , j=0 , maxdiff=-1;
    while( j<n && i<n )
    {
        if(LMin[i] < RMax[j])
        {
            maxdiff = max(maxdiff , (j - i));
            j++;
        }
        else
            i++;
    }

    return maxdiff;
}

int main()
{
    int arr[] = { 9 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 18 , 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxDiff = maxIndexDiff(arr, n);
    cout<<"Maximum difference is = "<<maxDiff<<endl;

    return 0;
}
