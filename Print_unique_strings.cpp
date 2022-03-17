/*
Problem Statement:
------------------
Given N strings, print unique strings in lexicographical order with their frequency.
N <= 10^5
|S| <= 100
*/

# include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m;

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        if (m.find(s) != m.end())
            m[s]++;

        else
            m.insert({s, 1});
    }

    for (auto i : m)
        cout << i.first << "  ->  " << i.second << endl;
    

    return 0;
}