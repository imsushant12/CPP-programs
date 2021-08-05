#include <bits/stdc++.h>
using namespace std;

void printNSE(int a[], int n)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = n - 1; i >= 0; i--)
    {
        q.push(a[i]);

        if (a[i] <= q.top())
        {
            a[i] = -1;
        }
        else
        {
            a[i] = q.top();
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
}

int main()
{
    int a[] = {4, 8, 5, 2, 25};
    int n = sizeof(a) / sizeof(a[0]);
    printNSE(a, n);
    return 0;
}