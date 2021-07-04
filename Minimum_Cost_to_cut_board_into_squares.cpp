#include <bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    // storing number of boards in vertical and horizontal direction
    // initially it is one.
    int horizontal = 1;
    int vertical = 1;

    int answer = 0;

    // sorting both the costs in decreasing order.
    sort(X, X + m, greater<int>());
    sort(Y, Y + n, greater<int>());

    int i = 0, j = 0;
    while (i < m and j < n)
    {
        if (X[i] > Y[j])
        {
            answer += X[i] * vertical;
            horizontal++;
            i++;
        }
        else
        {
            answer += Y[j] * horizontal;
            vertical++;
            j++;
        }
    }
    // some part of board can be left if length and breadth are of different sizes.
    while (i < m)
    {
        answer += X[i] * vertical;
        i++;
    }

    while (j < n)
    {
        answer += Y[j] * horizontal;
        j++;
    }

    return answer;
}

int main()
{
    int m = 6, n = 4;
    int X[m - 1] = {2, 1, 3, 1, 4};
    int Y[n - 1] = {4, 1, 2};
    cout << "Minimum Cost of cutting is : " << minimumCostOfBreaking(X, Y, m - 1, n - 1);
    return 0;
}
