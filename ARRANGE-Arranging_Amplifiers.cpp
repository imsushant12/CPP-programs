#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> a, int n)
{
    int counter = 0, ones = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            ones++;

    sort(a.begin(), a.end(), greater<int>());

    // Printing ones as ones should be in start to maximize the output.
    for (int i = 0; i < ones; i++)
        cout << "1 ";

    // Checking for (2,3) case:
    if ((n - ones) == 2)
    {
        if (a[0] == 3 and a[1] == 2)
            cout << "2 3." << endl;
    }
    else
    {
        for (int i = 0; i < (n - ones); i++)
            cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of amplifiers : ";
    cin >> n;

    vector<int> a;

    cout << "Enter their amplification loads : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << "Order of amplifiers to get the strongest amplification is : ";
    solve(a, n);

    return 0;
}