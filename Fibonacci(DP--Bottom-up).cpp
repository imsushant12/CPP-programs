#include <bits/stdc++.h>
using namespace std;

int fib[9];

int Fibonacci(int n)
{
    if(n == 0 || n == 1)
        return 1;

    fib[0] = 1;
    fib[1] = 1;

    for(int i=2 ; i<n ; i++)
        fib[i] = fib[i-1] + fib[i-2];

    return(fib[n-1]);
}

int main()
{
    cout<<"Fibonacci : "<<Fibonacci(9);

    return 0;
}
