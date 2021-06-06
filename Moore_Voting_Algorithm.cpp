#include <bits/stdc++.h>
using  namespace std;

int MooreAlgorithm(int a[] , int n)
{
    int result = 0;
    int frequency = 0;

    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == a[result])
            frequency++;

        else
            frequency--;

        //as the frequency is 0 then move to the next index which is our current index(i)
        if(frequency == 0)
        {
            result = i;
            frequency = 1;
        }
    }
    return a[result];
}


int main()
{
    int n , majority=0;
    cout<<"\nEnter size of array : ";
    cin>>n;

    int a[n];

    cout<<"\nEnter array : "<<endl;
    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    int answer = MooreAlgorithm(a , n);

    for(int i=0 ; i<n ; i++)
        if(a[i] == answer)
            majority++;

    if(majority > (n/2))
        cout<<"\nMajority Element is = "<<answer<<endl;
    else
        cout<<"\nNo majority element is present"<<endl;

    return 0;
}

