
#include <bits/stdc++.h>
using namespace std;

int fac[5];

int Factorial(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;

    // Can comment this line as well
    if(fac[n] != 0)
        return fac[n];

    return (fac[n] = n * Factorial(n-1));
}

int main()
{
    cout<<"Fibonacci : "<<Factorial(5);

    return 0;
}
