/*
Two numbers are given: N and K. Need to find total number of weird-numbers in the range 1 to N. A weird number
is that number which is not divisible by K, but the sum of digits of that number is divisible by K
*/

#include <bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum;
    for (sum = 0; n > 0; sum += n % 10, n /= 10)
        ;
    return sum;
}

bool isWeird(int n, int k)
{
    if (n % k != 0)
    {
        if (getSum(n) % k == 0)
            return true;
    }
    return false;
}

int find(int n, int k)
{
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isWeird(i, k))
            counter++;
    }
    return counter;
}

int main()
{
    int n, k;

    cout << "Enter the range : ";
    cin >> n;
    cout << "Enter K's value : ";
    cin >> k;

    cout << "Total weird numbers between 1 and " << n << " is : " << find(n, k);

    return 0;
}