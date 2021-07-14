#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

/* 
i basically denotes the place i.e
i == 1 --> air
i == 2 --> water
i == 3 --> fire
*/

int solve(int h, int a, int i)
{
    if (a <= 0 or h <= 0)
        return 0;

    // If we have found the place again i.e. memorization part.
    if (dp[h][a] != -1)
        return dp[h][a];

    int x = 0, y = 0, z = 0;

    // Traversing all three possible places and then assigning the optimal place in the dp cell.
    if (i != 1)
        x = 1 + solve(h + 3, a + 2, 1);
    if (i != 2)
        y = 1 + solve(h - 5, a - 10, 2);
    if (i != 3)
        z = 1 + solve(h - 20, a + 5, 3);

    return dp[h][a] = max({x, y, z});
}

int main()
{
    int h, a;
    cout << "Enter the health and armour values : ";
    cin >> h >> a;

    // Initializing cells of dp matrix with -1.
    memset(dp, -1, sizeof(dp));

    int answer = max({solve(h + 3, a + 2, 1), solve(h - 5, a - 10, 2), solve(h - 20, a + 5, 3)});

    cout << "maximum time of survival is : " << answer;

    return 0;
}