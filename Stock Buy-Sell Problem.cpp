#include <bits/stdc++.h>
using namespace std;

void stockBuySell(int prices[] , int n)
{
    if(n == 1)
    {
        cout<<"Cannot buy or sell."<<endl;
        return;
    }

    int i = 0 , j = 1;
    int low = prices[i] , high = prices[j];

    while((j<n) && (j<n))
    {
        //while cost is lower than next day -->(BUY)
        while((i < n) && (prices[i] > prices[i+1]))
            i++;

        cout<<"BUY @ "<<prices[i]<<" and ";

        //while cost is higher than next day --> (SELL)
        while((j < n) && (prices[j+1] > prices[j]))
            j++;

        cout<<"SELL @ "<<prices[j]<<endl;

        //Cannot buy further hence break
        if(j == n-1)
            break;

        i = j+1;
        j = j+1;
    }




}

int main()
{
    int prices[] = {100 , 180 , 260 , 310 , 40 , 535 , 695};
    int n = sizeof(prices) / sizeof(prices[0]);

    stockBuySell(prices , n);

    return 0;
}
