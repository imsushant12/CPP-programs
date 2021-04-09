#include <bits/stdc++.h>
using namespace std;

long long int calculateKtoN(int K, int n)
{
    long long int temp;
    if(n == 1)
        return K;

    if(n%2 == 0)
    {
        temp = calculateKtoN(K , n/2);
        return temp*temp;
    }
    else
    {
        temp = calculateKtoN(K , (n-1)/2);
        return K*temp*temp;
    }
}


int main()
{
    int K = 9;
    int n = 6;

    cout<<K<<" to power "<<n<<" is : "<<calculateKtoN(K, n);

    return 0;
}
