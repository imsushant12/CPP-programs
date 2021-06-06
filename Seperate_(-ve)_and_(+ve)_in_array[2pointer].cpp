#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/

//It is using the two pointer technique.
void rearrangeNumbers(int a[] , int n)
{
    int l=0 , h=n-1;

    while(l <= h)
    {
        //both of them are negative, then just shift low
        if(a[l]<0 && a[h]<0)
            l++;

        //low is negative and high is positive, then just move on
        else if(a[l]<0 && a[h]>0)
        {
            l++;
            h--;
        }

        //low is positive and high is negative, then swap
        else if(a[l]>0 && a[h]<0)
        {
            swap(a[l] , a[h]);
            l++;
            h--;
        }

        //the rest case
        else
            h--;
    }

}

int main()
{
    int a[] = {-1 , 2 , -3 , 4 , 5 , 6 , -7 , 8 , -9};
    int n = sizeof(a) / sizeof(a[0]);

    rearrangeNumbers(a , n);

    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    return 0;
}
