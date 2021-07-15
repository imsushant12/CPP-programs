#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> buy;
    vector<pair<int, int>> sell;

    cout << "Enter number of houses : ";
    cin >> n;

    cout << "Enter the wines : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x >= 0)
            buy.push_back({x, i});
        else
            sell.push_back({x, i});
    }

    int ans = 0, i = 0, j = 0;

    while (i < buy.size() and j < sell.size())
    {
        int work = min(buy[i].first, -(sell[j].first));

        //updating buy and sell vectors.
        buy[i].first -= work;
        sell[j].first += work;

        int diff = abs(buy[i].second - sell[j].second);
        ans += (work * diff);

        if (buy[i].first == 0)
            i++;
        if (sell[j].first == 0)
            j++;
    }

    cout << "Minimum amount of work units needed is : " << ans;

    return 0;
}