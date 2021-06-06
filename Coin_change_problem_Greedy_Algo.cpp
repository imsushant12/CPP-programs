#include <bits/stdc++.h>
using namespace std;

void findChanges(int changes[] , int sum , int n)
{
    sort(changes , changes+n);
    for(int i=n-1 ; i>=0 ; i--)
    {
        while(sum >= changes[i])
        {
            sum -= changes[i];
            cout<<changes[i]<<"  ";
        }
    }
}

int main()
{
    int sum;
    cout<<"Enter the sum : ";
    cin>>sum;

    int changes[] = {1 , 2 , 5 , 10 , 20 , 50 , 100};

    int n = sizeof(changes) / sizeof(changes[0]);

    cout<<"The minimal changes for "<<sum<<" is : ";
    findChanges(changes , sum , n);

    return 0;
}
