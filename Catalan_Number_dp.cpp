#include <bits/stdc++.h>
using namespace std;


//Time complexity : O(n^2)
//Space Complexity : O(n)
int catalan(int n)
{
    int cat[n+1];
    cat[0] = cat[1] = 1;

    for(int i=2 ; i<=n ; i++)
    {
        cat[i] = 0;
        for(int j=0 ; j<i ; j++)
            cat[i] += cat[j] * cat[i-j-1];
    }
    return cat[n];
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<"Catalan number is : "<<catalan(n);

    return 0;
}
