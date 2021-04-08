#include<bits/stdc++.h>
using namespace std;

//Time Complexity = O(n) and Space Complexity = O(1);
void Seperate(int a[] , int n)
{
    int i=0 , j=(n-1);

    while(j >= i)
    {
        if(a[i]%2 != 0)
        {
            if(a[j]%2 == 0)
            {
                //cout<<"\nBefore swap a[i] and a[j] = "<<a[i]<<"  "<<a[j];
                swap(a[i] , a[j]);
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }

    cout<<"Seperated array = ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

}

/*
//Space complexity = O(n) and Time Complexity = O(n);
void Seperate(int a[] , int n)
{
    int b[n];
    int j,k;
    j=0,k=n-1;

    for(int i=0 ; i <n ; i++)
    {
        if(a[i]%2 == 0)
            b[j++] = a[i];
        else
            b[k--] = a[i];
    }

    cout<<"Seperated array = ";
    for(int i=0 ; i<n ; i++)
        cout<<b[i]<<"  ";
}
*/

int main()
{
    int a[] = {12,34,45,9,8,90,3};
    int n = sizeof(a) / sizeof(a[0]);

    Seperate(a , n);

    return 0;
}
