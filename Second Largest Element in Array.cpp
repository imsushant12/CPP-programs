#include <bits/stdc++.h>
using  namespace std;

int secondLargest(int a[] , int n)
{
    int largest,second;
    largest = second = INT_MIN;

    for(int i=0 ; i<n ; i++)
    {
        //if a[i] is greater than largest then
        //a[i] becomes largest and
        //largest becomes second largest
        if(a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if( a[i] < largest)
        {
            if((second == INT_MIN) || (a[i] > second))
                second = a[i];
        }
    }
    return second;
}

int main()
{
    int a[] = { 8 , 10 , 2 , 15 , 23 , -1 };
    int n = sizeof(a) / sizeof(a[0]);

    int answer = secondLargest(a , n);
    cout<<"Second largest element is = "<<answer<<endl;

    return 0;
}
