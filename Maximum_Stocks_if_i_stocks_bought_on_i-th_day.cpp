#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int money, int price[])
{
    if (price[0] > money)
        return 0;

    int currentPrice = price[0];
    int stocks = 1;

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < i + 1)
        {
            if (currentPrice + price[i] <= money)
            {
                stocks++;
                currentPrice += price[i];
                j++;
            }
        }
    }

    return stocks;
}

int main()
{
    int price[] = {4, 8, 8, 2};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 65;

    cout << "Maximum stocks can be bought is : " << buyMaximumProducts(n, k, price) << endl;

    return 0;
}
