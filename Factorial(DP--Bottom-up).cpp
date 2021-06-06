#include <bits/stdc++.h>
using namespace std;

int fac[5];

int Factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    fac[0] = 1;
    fac[1] = 1;

    for(int i=2 ; i<=n ; i++)
        fac[i] = i * fac[i-1];

    return(fac[n]);
}

int main()
{
    int n = 5;
    cout<<"Factorial : "<<Factorial(n);

    cout<<endl;
    for(int i=0 ; i<=n ; i++)
        cout<<fac[i]<<"   ";

    return 0;
}

