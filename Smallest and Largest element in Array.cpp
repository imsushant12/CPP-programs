#include <bits/stdc++.h>
using namespace std;

void findLargestSmallest(int a[] , int n)
{
    int large = INT_MIN , small = INT_MAX;
    for(int i=0 ; i<n ; i++)
    {
        //when a[i] is smaller than a[i+1]
        if(a[i] < a[i+1])
        {
            if(a[i] < small)
                small = a[i];
            if(a[i+1] > large)
                large = a[i+1];
        }
        //when a[i] is larger than a[i+1]
        else
        {
            if(a[i+1] < small)
                small = a[i+1];
            if(a[i] > large)
                large = a[i];
        }
    }
    cout<<"Smallest element = " <<small<<endl;
    cout<<"Largest element = " <<large<<endl;
}

int main()
{
    int a[] = { -8 , 10 , 2 , 15 , 13 , 0 };
    int n = sizeof(a) / sizeof(a[0]);

    findLargestSmallest(a , n);
    return 0;
}

