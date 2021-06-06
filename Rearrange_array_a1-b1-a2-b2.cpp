#include <bits/stdc++.h>
using namespace std;

// function to shuffle an array of size 2n
void shuffleArray(int a[], int n)
{
    // Rotate the element to the left
    for(int i=0 , q=1 , k=n ; i<n ; i++ , k++ , q++)
        for(int j=k ; j>i+q ; j--)
        {
            //cout<<"We are swapping "<<a[j-1]<<" and " <<a[j]<<endl;
            swap(a[j - 1] , a[j]);
        }
}

int main()
{
    int a[] = { 1 , 3 , 5 , 7 , 2 , 4 , 6 , 8 };
    int n = sizeof(a) / sizeof(a[0]);

    shuffleArray(a , n/2);

    cout<<"Suffled array is = ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    return 0;
}

