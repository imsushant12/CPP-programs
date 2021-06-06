#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n)
{
    int a = 1 , b = 1 , sum , i;

    for(i=2 ; i<n ; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

int main()
{
    cout<<"Fibonacci : "<<Fibonacci(9);

    return 0;
}
