#include <bits/stdc++.h>
using namespace std;

void printNSE(int a[], int n)
{
    vector<int> answer(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() >= a[i])
            s.pop();

        if (s.empty())
            answer[i] = -1;
        else
            answer[i] = s.top();

        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << answer[i] << "  ";
}

int main()
{
    int a[] = {4, 8, 5, 2, 25};
    int n = sizeof(a) / sizeof(a[0]);
    printNSE(a, n);

    return 0;
}