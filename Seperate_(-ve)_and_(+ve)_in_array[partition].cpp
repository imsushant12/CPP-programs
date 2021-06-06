#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/

//It is using the the partitioning algorithm of Quick Sort.
void rearrangeNumbers(int a[] , int n)
{
    int j=0;

    for(int i=0 ; i<n ; i++)
        if(a[i] < 0)
        {
            if(i != j)
                swap(a[i] , a[j]);
            j++;
        }
}

int main()
{
    int a[] = {-1 , 2 , -3 , 4 , 5 , 6 , -7};
    int n = sizeof(a) / sizeof(a[0]);

    rearrangeNumbers(a , n);

    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    return 0;
}

