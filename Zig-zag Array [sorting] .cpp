#include <bits/stdc++.h>
using namespace std;

void zigzag(int a[] , int n)
{
    for(int i=1 ; i<n ; i+=2)
    {
        if(i+1 < n)
            swap(a[i] , a[i+1]);
    }

    cout<<"\nZig-Zag array is : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";
}

int main()
{
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a , a+n);

    cout<<"Original array is : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    zigzag(a , n);

    return 0;
}

