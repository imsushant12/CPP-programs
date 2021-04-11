#include <bits/stdc++.h>
using namespace std;

int fib[9];

int Fibonacci(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;

    if(fib[n] != 0)
        return fib[n];

    return (fib[n] = Fibonacci(n-1) + Fibonacci(n-2));
}

int main()
{
    cout<<"Fibonacci : "<<Fibonacci(9);

    return 0;
}
