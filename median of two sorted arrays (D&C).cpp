#include <bits/stdc++.h>
using namespace std;

int median(int arr[] , int n)
{
    if(n%2 == 0)
        return ((arr[n/2 - 1] + arr[n/2]) / 2);
    else
        return arr[n];
}

int findMedian(int a[] , int b[] , int n)
{
    if(n <= 0)
        return -1;
    if(n == 1)
        return ((a[0] + a[0]) / 2);
    if(n == 2)
        return (max(a[0] , b[0]) + min(a[1] , b[1])) / 2;


    int m1 = median(a , n);
    int m2 = median(b , n);

    if(m1 == m2)
        return m1;          //or m2
    //Range : (A)first->m1 and (B)m2->last
    if(m1 > m2)
    {
        if(n % 2 == 0)
            return findMedian(b + n/2-1 , a , n - n/2+1);

        return findMedian(b + n/2 , a , n - n/2);
    }
    //Range : (A)m1->last and (B)first->m2
    if(m2 > m1)
    {
        if(n % 2 == 0)
            return findMedian(a + n/2-1 , b , n - n/2+1);

        return findMedian(a + n/2 , b , n - n/2);
    }
}

int main()
{
    int a[] = {1, 2, 3, 6};
    int b[] = {4, 6, 8, 10};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    if (n1 == n2)
        cout<<"Median is : "<<findMedian(a , b , n1);
    else
        cout<<"Doesn't work for arrays of unequal size";

    return 0;
}

