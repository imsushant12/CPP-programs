#include <bits/stdc++.h>
using namespace std;

int Factorial(int n)
{
    int prod = 1;

    for(int i=2 ; i<=n ; i++)
        prod *= i;

    return prod;
}

int main()
{
    int n = 5;
    cout<<"Factorial : "<<Factorial(n);

    return 0;
}
